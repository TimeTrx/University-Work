#include <cstddef> // For std::size_t, same as #include <stddef.h>
#include <limits>  // For std::numeric_limits<T>
#include <cstring> // Equivalent to #include <string.h>
#include <iostream> // For cin/cout
/*
Michael Morand
103626334
Feb 25, 14
Assignment 2A
*/

template <std::size_t N>
struct bool_array
{
public:
using size_type = std::size_t;
using value_type = bool;


~bool_array() = default;
constexpr size_type size() const
{
return N;
}
bool operator [](size_type i) const
 	{
   	 unsigned char value = 1;
   	 size_type const INDEX = i / std::numeric_limits<unsigned char>::digits;
   	 size_type const OFFSET = i % std::numeric_limits<unsigned char>::digits;
   	 return bits_[INDEX] & (value << OFFSET);
 	}
private:
static constexpr auto MAX = 
N / std::numeric_limits<unsigned char>::digits
+ (N % std::numeric_limits<unsigned char>::digits != 0);
unsigned char bits_[MAX];
class bit_proxy
{
private:
unsigned char& datum_;
size_type const offset_;
public:
bit_proxy() = delete;
// default copy constructor & assignment... NOTE: How they are all set to "default"
bit_proxy(bit_proxy const&) = default;
bit_proxy& operator =(bit_proxy const&) = default;
   
// default move constructor & assignment... NOTE: How they are all set to "default"
bit_proxy(bit_proxy&&) = default;
bit_proxy& operator =(bit_proxy&&) = default;

// default destructor NOTE: How they are all set to "default"
~bit_proxy() = default;
bit_proxy(unsigned char& datum, size_type offset) : //a constructor accepting 2 arguments and the ability to assign bool values
datum_(datum), offset_(offset)//a datum is an l-value reference to an unsigned char and offset is size_type
{
}
bit_proxy& operator = (bool b)
{
unsigned char value {1};



if(b == true)
{
datum_ |= (value << offset_); //Sets bit, |= sets bit
}
else
{
datum_ &= ~(value << offset_); //Deselects a bit, &= and ~
}

return *this; //return this object (which IS an l-value)	
}
operator bool() const
{
unsigned char value{1};


datum_ &= value << offset_; //Bitwise-AND &= 

 	 bool t = (datum_ != 0);	

return t;
}
};
public:
bit_proxy operator [] (size_type i)
{
return bit_proxy{ bits_ [i / std::numeric_limits<unsigned char>::digits],
i % std::numeric_limits<unsigned char>::digits};
}


bool_array()//Constructor
{
 	std::memset(bits_, 0, sizeof(bits_));// memset call goes here
}

bool_array(bool_array const& a)//Copy Constructor
{
 	 std::memcpy(bits_, a.bits_, sizeof(bits_)));// memcpy call goes here
}
bool_array& operator = (bool_array const& a)//Copy Assignment Operator
{
  	std::memcpy(bits_, a.bits_, sizeof(bits_));//memcopy call goes here
return *this;
}
};

/*void func()
{
bool_array<13> var; //var will only use 13 bits of stack space (2 bytes)
}*/

int main()
{
/*bool_array<234> a;  // default constructed
 	bool_array<234> b = a; // copy constructed
 	bool_array<234> c;
 	c = a; // copy assignment operator
 	std::cout << c.size() << '\n'; // outputs 234
 	std::cout << c[12] << '\n'; // outputs false/zero unless you've hacked in a non-zero value in bits_*/
using namespace std;

 	bool_array<13> test;

 	for (unsigned i=0; i != 13; ++i)
   	 cout << i << ": " << test[i] << '\n';

 	for (unsigned i=0; i != 13; ++i)
 	{
   	 cout << i << ": " << test[i] << "; ";
   	 test[i] = true;
   	 cout << test[i] << '\n';
 	}

 	for (unsigned i=0; i != 13; ++i)
   	 cout << i << ": " << test[i] << '\n';
	
	for (unsigned i=0; i != 13; ++i)
 	{
   	 cout << i << ": " << test[i] << "; ";
	if(i == 1 || i == 2 || i == 3)
	test[i] = false;
   	 cout << test[i] << '\n';
 	}

	for (unsigned i=0; i != 13; ++i)
   	 cout << i << ": " << test[i] << '\n';
	
	
	for (unsigned i=0; i != 13; ++i)
 	{
   	 cout << i << ": " << test[i] << "; ";
	test[i] = true;
   	test[i/2] = false;
   	 cout << test[i] << '\n';
 	}

 	for (unsigned i=0; i != 13; ++i)
   	 cout << i << ": " << test[i] << '\n';

	for (unsigned i=0; i != 13; ++i)
 	{
   	 cout << i << ": " << test[i] << "; ";
	if(i == 0 || i == 4 || i == 7)
	test[i] = true;
   	 cout << test[i] << '\n';
 	}

	for (unsigned i=0; i != 13; ++i)
   	 cout << i << ": " << test[i] << '\n';
	


	for (unsigned i=0; i != 13; ++i)
 	{
   	 cout << i << ": " << test[i] << "; ";
	if(i == 0 || i == 4 || i == 7)
	test[i] = false;
   	 cout << test[i] << '\n';
 	}

	for (unsigned i=0; i != 13; ++i)
   	 cout << i << ": " << test[i] << '\n';



	for (unsigned i=0; i != 13; ++i)
 	{
   	 cout << i << ": " << test[i] << "; ";
	if(i == 1 || i == 2 || i == 3)
	test[i] = true;
   	 cout << test[i] << '\n';
 	}

	for (unsigned i=0; i != 13; ++i)
   	 cout << i << ": " << test[i] << '\n';

	for (unsigned i=0; i != 13; ++i)
 	{
   	 cout << i << ": " << test[i] << "; ";
	if(i == 1 || i == 2 || i == 3)
	test[i] = false;
   	 cout << test[i] << '\n';
 	}

	for (unsigned i=0; i != 13; ++i)
   	 cout << i << ": " << test[i] << '\n';


	for (unsigned i=0; i != 13; ++i)
 	{
   	 cout << i << ": " << test[i] << "; ";
	if(i == 6)
	test[i] = true;
   	 cout << test[i] << '\n';
 	}

	for (unsigned i=0; i != 13; ++i)
   	 cout << i << ": " << test[i] << '\n';
	

	for (unsigned i=0; i != 13; ++i)
 	{
   	 cout << i << ": " << test[i] << "; ";
	if(i == 5)
	test[i] = true;
   	 cout << test[i] << '\n';
 	}

	for (unsigned i=0; i != 13; ++i)
   	 cout << i << ": " << test[i] << '\n';

	for (unsigned i=0; i != 13; ++i)
 	{
   	 cout << i << ": " << test[i] << "; ";
	if(i == 6)
	test[i] =  false;
   	 cout << test[i] << '\n';
 	}

	for (unsigned i=0; i != 13; ++i)
   	 cout << i << ": " << test[i] << '\n';
	

	for (unsigned i=0; i != 13; ++i)
 	{
   	 cout << i << ": " << test[i] << "; ";
	if(i == 5)
	test[i] = false;
   	 cout << test[i] << '\n';
 	}

	for (unsigned i=0; i != 13; ++i)
   	 cout << i << ": " << test[i] << '\n';

 	for (unsigned i=0; i != 13; ++i)
 	{
   	 cout << i << ": " << test[i] << "; ";
   	 test[i] = false;
   	 cout << test[i] << '\n';
 	}

 	for (unsigned i=0; i != 13; ++i)
   	 cout << i << ": " << test[i] << '\n';

 	cout << "\n\n";
return 0;
}
