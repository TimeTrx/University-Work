#include <iostream>
#include <list> //doublely-linked list

using namespace std;

int main() 
{
	list<int> var; //create an empty list (in the variable var)

	var.push_back(23);

	for(auto value : var)
	cout << value << ',';
	cout << '\n';

	var.push_back(55);
	var.push_front(242);

	for(auto value : var)
	cout << value << ',';
	cout << '\n';

	cout <<	"Front Element is: " << var.front() << '\n';
	cout <<	"Back Element is: " << var.back() << '\n';
	cout <<	"The list size is " << var.size() << '\n';

	var.pop_back();
	
	for(auto value : var)
	cout << value << ',';
	cout << '\n';

	var.pop_front();

	for(auto value : var)
	cout << value << ',';
	cout << '\n';	

	return 0;
}
