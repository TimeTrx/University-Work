//Michael Morand
//Monday, March 25th 2013
//103626334
//Final Project 60-340
//Group A0
//Uses Paul Preney's monitor.cxx as monitor.hxx

/*Requirements: 
Use <regex> to parse HTTP response headers and HTML/XHTML hyperlink tags.
Uses monitor<T> class 
Uses Queue  with threading to hold URLs.
Boost: -lboost_regex
*/
//Start of code:

//Includes:
#include "ex_info.hxx"
#include "http_utils.hxx"
#include "tcp_stream.hxx"
#include "monitor.hxx"
#include <algorithm>
#include <ostream>
#include <thread>
#include <boost/regex.hpp>
#include <queue>
#include <string>
#include <future>
#include <sstream>
#include <exception>
#include <mutex>
#include <iostream>//for testing purposes only

using namespace boost; //to fix this, -lboost_regex
using namespace std;
map<char,int> umap;
int a = 0;

ostream& output_ip(std::ostream& os, uint32_t ipaddr);

void input()
{
    const string server_address = [](){string t; cin >> t; return t;}(); //for testing only, use an url
    const string server_resource = [](){string e; cin >> e; return e;}(); //for testing only,
	cout << "test " << server_address << server_resource << endl;
    tcp_iostream conn;//all below is for testing and has to amended
	try
  	{
    		cout << "==== Connecting to " << server_address << "...\n";
            conn.open(server_address, "http");//for testing only

    		cout
      		<< "==== Connected to "
            << conn.server_name() << ':'//for testing only
      		<< conn.port() << " --> IP:"
            ;
    		output_ip(cout, conn.ip())
      		<< ':' << conn.port() << '\n'
    		;
            cout << "==== Sending HTTP Request...\n";
    		conn
      		<< "GET " << server_resource << " HTTP/1.0" << crlf
      		<< "Host: " << server_address << crlf
      		<< crlf
    		;
            conn.flush();
  	}
  	catch (...)
  {
    conn.exceptions(std::ios_base::goodbit);
    process_exception();
    cout << "Error!" << endl;
  }
    conn.exceptions(std::ios_base::goodbit);
    cout << "==== Outputting response...\n";
    while (true)//fix the while loop once you have fixed everything else
    //Will need the regex portion here eventually and push function
    {
	auto c = conn.get();
    	if (c != tcp_iostream::traits_type::eof())
        cout.put(c);
	/*regex reg (R"(<\s*a\s*href=["](.*)["][^>]*>)");
    	sregex_iterator pos(put(c).cbegin(), put(c).cend(), reg);
    	sregex_iterator end;
    	umap.insert ( pair<char,int>(pos->str(1),a) );
	++a;
    	cout << "1: " << pos->str(1) << '\n';//for testing purposes only*/
    else
      break;
  }
	/*bool check = checkUrl(pos->str(1));
    if(check) //Sends the url to be checked if its absolute, use foreach, regex
    {
	//PUSH IT TO THE Queue 
        input(); //sends it to input to handle the URL step
    }
    else //if link is not absolute, eg. relative
    {
	string html;
	html = server_address + pos->str(1);
        //push it on the queue here
    }*/
}

bool checkUrl(string str) //use search/find from algorithm
{
  	string delim ("html://");
  	unsigned found = str.find(delim);
  	if (found <= str.size())
	{
		return true;
	}

 	return false;
}



int main()
{
    //string test; //for testing purposes only
    //getline(cin, test); //for testing purposes only
    /*regex reg (R"(<\s*a\s*href=["](.*)["][^>]*>)");
    sregex_iterator pos(test.cbegin(), test.cend(), reg);
    sregex_iterator end;*/
    //monitor<queue <string> > urls.push(pos->str(1));//why doesn't this work? I'm pushing the queue
    //cout << "1: " << pos->str(1) << '\n';//for testing purposes only
    //for testing purposes only
    input();

    //string_monitor.push(testing);
    //urls.push(async(input()));  //Option 1

     // monitor<string> string_monitor();
     // thread<queue<string>> v; //needs to be changed,

       /* v.push(
          async(
            launch::async, // tell async() to run right away!!!
            [&,test]()//work on the lambda function, mike, why is i not working?
            {
                //
                // Modify the global string in string_monitor. This is needed
                // because, except for the thread portion of the Standard Library,
                // everything in C++ is NOT thread-safe. Thus you need to
                // ensure the data is bitwise const for all threads OR
                // internally synchronized!
                //
                string_monitor(
                  [=](string& s)
                  {
                    s += test; // string concatenation of test (which is the getline input) to s
                  }
                );
                cout << "Test test: " << test << endl;//for testing only
                cout << "Test S: " << &string_monitor << endl;//for testing only
                // The next line tells the system that execution can switch to
                // another thread here. This is not needed here because of the
                // above sleep_for() call, but, often it is both used and wise to
                // place yields() in long-running threads...
                this_thread::yield();
            }));*/
	
    return 0;
}

//End of Mike's code, [] Lines Total.
