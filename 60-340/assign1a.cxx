#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>

using namespace std;

template <typename BidiIter>
/*
The bubble_sort() routine:
-performs all container accesses and manipulations using iterators
-has only one while loop
-has only one for loop
-does not declare more than two variables of type BidiIter in the function,
-uses std::iter_swap() to swap the contents of two locations where required, and,
-no function calls except: std::iter_swap() , std::next() , std::prev() and BidiIter iterator member functions.
*/
void bubble_sort(BidiIter first, BidiIter last)
{
	bool swapped = false;
	BidiIter i = first;
	//if(i != last)
	//{
	//	i = next(i);		
	//++i;//There are more than 0 elements
		
	//}
	if(i == last)
		return; //We're done, only one element!

	//WE KNOW WE HAVE AT LEAST 2 Elements! At this point!
	
	
	do
	{	
		i = first;
		swapped = false;
		i = next(i);
		for(; i != last;)
		{
			BidiIter i_minus_1 = prev(i);//I minus 1 points to the first.
			if(*i_minus_1 > *i)
			{
				iter_swap(i, i_minus_1); //This swaps the place of the iterators
				swapped = true;
			}
			i = next(i);
		}	
	}
	while(swapped);
}
/*
The main function:
-declares a std::list variable, called words
-reads in from std::cin, 'x' number of std::string values until there is an error or end-of-file appending each to words,
-calls bubble_sort(begin(words), end(words) to sort the list, and,
-outputs the entire list to std::cout after the sorting has completed in function bubble_sort.
*/
int main()
{
	int i;

	list<int> words;
	while (cin >> i)
		words.push_back(i);

	bubble_sort(words.begin(), words.end()); //Calls the bubble sort

	for(list<int>::iterator i = words.begin(), 
	iEnd = words.end();
	i != iEnd;
	++i)
	{
		cout << *i << " " << "\n";
	}
	 cout << "\n";

	return 0;
}
