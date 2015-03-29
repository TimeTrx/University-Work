//===========================================================================

#include <memory>                     // For std::shared_ptr
#include <string>                     // For std::string
#include <utility>                    // For std::move()
#include <vector>                     // For std::vector
#include <sstream>                    // For std::istringstream
#include <iostream>
#include <iomanip>                    // For std::setprecision

//===========================================================================

class employee_impl
{

  private:
   
  std::string name_;  
  
  public:
   
  employee_impl(std::string&& name) : name_(std::move(name)) {}//constructor
  
  employee_impl(std::string const& name) : name_(name) {}//constructor
  
  std::string const& name() const
  {
    return name_; 
  }
  
  std::string name(std::string const& new_name)
  {
    std::string retval = new_name;
    retval.swap(name_); 
    return retval;
  }
  
  std::string name(std::string&& new_name)
  {
    std::string retval = std::move(new_name); 
    return retval;
  }
  
  virtual double hourly_rate() const;
  virtual double annual_rate() const;
  double pay_by_year() const {return annual_rate();}
  double pay_by_hour(double hours) const {return hourly_rate()*hours;}
  
};

//===========================================================================

class hourly_employee_impl : public employee_impl
{
    private:
    
    double hourly_rate_;
    
    public:
    
    hourly_employee_impl(std::string const& name, double const& rate) : employee_impl(name) { hourly_rate_ = rate; }//constructor
    
    hourly_employee_impl(std::string&& name, double const& rate):employee_impl (name){hourly_rate_ = rate;}
    
    virtual double hourly_rate()
    {
    return hourly_rate_;
    }
    
    virtual double annual_rate()
    {
        return (40 * 50 * hourly_rate_);
    }
};

//===========================================================================

class salary_employee_impl : public employee_impl
{
  private:
    
    double annual_rate_;
    
    public:
    
    salary_employee_impl(std::string const& name, double const& rate) : employee_impl(name) { annual_rate_ = rate; }//constructor
    
    salary_employee_impl(std::string&& name, double const& rate):employee_impl (name){annual_rate_ = rate;}
    
    virtual double hourly_rate()
    {
        return ((annual_rate_ / 50) / 60);
    }
    
    virtual double annual_rate()
    {
        return annual_rate_;
    }
};

//===========================================================================

typedef std::shared_ptr<employee_impl> employee;
typedef std::vector<employee>  employees;

//===========================================================================

std::istream& operator >>(std::istream& is, employee& e)
{
    bool fail = false;
    char a;
    std::string name;
    double amount;
    if(is >> a >> name >> amount)
    {
    try{
        switch(a)//checks to see if of type annual or hourly
        {
            case 'h':
            e.reset(new hourly_employee_impl(name, amount));
            break;
            case 's':
            e.reset(new salary_employee_impl(name, amount));
            break;
            default:
            fail=true;
         }
        }catch (...)
        {
            fail=true;
        }
    }
  if (fail)
    is.clear(std::ios_base::failbit); // Invalid format, fail stream.

  return is;
}

//===========================================================================

std::ostream& operator <<(std::ostream& os, employee const& e)
{
  bool fail = false;
    
    
    if(hourly_employee_impl* y = dynamic_cast<hourly_employee_impl*>(e.get()))
    {
        os << "h " << y->name << y->hourly_rate;
    }
    else if(hourly_employee_impl* y = dynamic_cast<hourly_employee_impl*>(e.get()))
    {
        os << "s " << y->name << y->annual_rate;
    }
    else
    {
        fail = true;
    }

  if (fail)
    os.clear(std::ios_base::failbit);

  return os;
}

//===========================================================================

//
// See std::basic_istream in <istream> for rdbuf() description and note the
// std::basic_istream constructor that accepts a std::streambuf. (We will
// be using this later to do network I/O.)
//
// See std::basic_streambuf in <streambuf> for in_avail(). A streambuf
// handles all buffering (if any) and low-level I/O operations. Think of
// this class as a device driver for the IOStream classes.
//
// gobble_available_input's declaration make look odd, but, C++ defines
// this overloaded operator:
//
//   std::istream& operator <<(
//     std::ostream& is,
//     std::istream& (*func)(std::istream&) // This is a function pointer!
//   );
//
// (and a corresponding one for ostreams as well). This allows one to
// write:
//
//   int i;
//   if (cin >> gobble_available_input >> i)
//     // ...
//   // etc.
//
// gobble_available_input consumes all characters in the input buffer, if
// any. This is handy with incorrect user-prompted inputs as it discards
// any previous extra characters that may exist.
//
std::istream& gobble_available_input(std::istream& is)
{
  std::streamsize const avail = is.rdbuf()->in_avail();
  if (avail > 0)
  {
    for (std::streamsize i=0; i != avail; ++i)
      is.get();
  }
  return is;
};

//===========================================================================

int main()
{
  using namespace std;

  // Declare list...
  employees es;

  // Read in one employee per line...
  for (string line; getline(cin, line) && !line.empty(); line.clear())
  {
    // Make the line read in an input stream and process the employee
    // record...
    istringstream sin(line);

    employee e;
    if (sin >> e)
      es.emplace_back(e);
    else
      // Since sin failed, we'll also fail cin...
      cin.clear(ios_base::failbit);
  }

  // Reset the fail (i.e., handle what we could read in)...
  if (cin.fail())
    cin.clear();

  // If any other errors occurred (incl. EOF) then quit...
  if (!cin)
  {
    cout << "ERROR: Unable to read in input!\n";
    return 1;
  }

  //
  // Use a pointer to member function to remember what the
  // user wants to see output.
  //
  // This prototype looks different than a normal function
  // pointer --because it is. A pointer to a member function
  // is really an INDEX into a SLOT. So to call it one needs
  // BOTH an object and the function pointer. Suppose one
  // has a reference to an employee_impl called eref, then pmf
  // would be called as follows:
  //
  //   (eref.*pmf)()
  //
  // If one instead had a pointer to an employee_impl called
  // eptr, then pmf would be called as follows:
  //
  //   (eptr->*pmf)()
  //
  // i.e., notice the "->" instead of a ".".
  //
  // NOTE: You need to/ wrap the content before the function call
  //       operator due to operator precedence. (Look up the
  //       operator precedence table and you'll see that the
  //       function call operator has higher precedence than
  //       ".*" or "->*".)
  //
  // Like regular pointers, "nullptr" is the invalid value.
  // Never invoke the pointer to member function if it has the
  // value nullptr!
  //
  double (employee_impl::*pmf)() const = nullptr;

  // Ask the user what they want to see output...
  do
  {
    cout << "(h)ourly or (a)nnual rate output: ";

    char choice;
    if (cin >> gobble_available_input >> choice)
    {
      if (choice == 'h')
        pmf = &employee_impl::hourly_rate;
      else if (choice == 'a')
        pmf = &employee_impl::annual_rate;
      else
        cout << "Invalid input.\n\n";
    }
  }
  while (cin && pmf == nullptr);

  if (pmf == nullptr)
  {
    cout << "\nERROR: Invalid input. Aborting.\n";
    return 2;
  }

  // Output requested data...
  cout << "\n\n";
  for (auto const& e : es)
  {
    cout << "Name: " << e << "\n" << "Rate: $" << es << "\n";
  }
}

//===========================================================================
