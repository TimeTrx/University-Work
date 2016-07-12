
// Compile with -lboost_regex

#include <boost/regex.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


int main()
{
  using namespace boost;
  using namespace std;

  ifstream in("in.html");
  ostringstream buf;
  buf << in.rdbuf();

  string data = buf.str();

  regex reg(R"(<\s*a\s+.*href=(['"])(.*)(\1).*>(.*))");
  sregex_iterator pos(data.cbegin(), data.cend(), reg);
  sregex_iterator end;
  for (; pos != end; ++pos)
  {
    cout 
      << "match: " << pos->str() << '\n'
      << "  tag: " << pos->str(1) << '\n'
      << "value: " << pos->str(2) << '\n'
    ;
  }
}

