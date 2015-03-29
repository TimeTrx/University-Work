//You also need in2.html for this to work
//Compile with -lboost_regex and -std=c++11
//Regex version 1.52 on server
#include <boost/version.hpp>
#include <boost/regex.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>


int main()
{
  using namespace boost;
  using namespace std;

  ifstream in("in2.html");
  ostringstream buf;
  buf << in.rdbuf();
	map<string,string> map_for_mapping;	

  string data = buf.str();
  regex reg(R"((.*)\x20/\x20(.*)/(.*)\n(.*):\x20(.*)\n)");//in <regex>: (.*)\x20.\x20(.*)\/(.*)\n(.*)\:\x20(.*)\n
  sregex_iterator pos(data.cbegin(), data.cend(), reg);
  sregex_iterator end;
 for (; pos != end; ++pos)
 {
    cout 
      << "Whats put in:\n" << pos->str() << '\n'
      << "1st Regex got: " << pos->str(1) << '\n'
      << "2nd Regex got: " << pos->str(2) << '\n'
			<< "3rd Regex got: " << pos->str(3) << '\n'
		//	<< "4th Regex got: " << pos->str(4) << '\n'
		//	<< "5th Regex got: " << pos->str(5) << '\n'
    ;

		//map_for_mapping.insert(pair<string,string>(pos->str(4), pos->str(5)));
  }
	
	string colon_data = buf.str();
	regex colon_reg(R"(\n(.*):\x20(.*)\n)");
	sregex_iterator colon_pos(colon_data.cbegin(), colon_data.cend(), colon_reg);
	sregex_iterator colon_end;
	for (; colon_pos != colon_end; ++colon_pos)
 {
    cout 
      << "Whats put in (Parsing):\n" << colon_pos->str() << '\n'
      << "1st Regex got: " << colon_pos->str(1) << '\n'
      << "2nd Regex got: " << colon_pos->str(2) << '\n'
    ;

		map_for_mapping.insert(pair<string,string>(colon_pos->str(1), colon_pos->str(2)));
  }
	map<string,string>::iterator position;
	for (position = map_for_mapping.begin(); position != map_for_mapping.end(); ++position)
	{
		cout << "Testing the Map, First: " << position->first << " Second: " << position->second << '\n';
	}
}
