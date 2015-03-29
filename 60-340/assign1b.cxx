#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>

using namespace std;
/*
The middle() function:
template <typename BidiIter>
BidiIter middle(BidiIter first, BidiIter last);
-middle() must return the iterator that represents the middle position.

*/
template <typename BidiIter>
BidiIter middle(BidiIter First, BidiIter Last)
{
	BidiIter tempSlow = First;
	BidiIter tempFast = First;
	if (tempFast != Last) //This if statement is required otherwise it could give an extra value after on the last element
		++tempFast;
	for (; tempFast != Last; )
		{
			++tempFast;
			if (tempFast != Last)
			{
				++tempFast;
				++tempSlow;
			}
			//next(tempFirst, 2);
			//prev(tempLast);>
		}
	return tempSlow; //This returns the middle of the list
}


/*
The quick sort algorithm is implemented as follows:

template <typename BidiIter>
void quick_sort(BidiIter first, BidiIter last);
-[first,last) is the range to be sorted, and,
-uses only valid bidirection iterator actions (i.e., see TCPPSL §9.2.4),
-std::partition() (i.e., in <algorithm>) and a lambda passed to std::partition(),
-std::iter_swap(),
-std::next(),
-std::prev(),
-calls middle(first, last) which you've also written (see below).

*/
template <typename BidiIter>
void quick_sort(BidiIter first, BidiIter last)
{
	/* psuedo code
	function quicksort(A, lo, hi)
        	left, right = partition(A, p, lo, hi)  // note: multiple return values
      	quicksort(A, lo, left)
        	quicksort(A, right, hi)
	*/
	//cout << "test2\n";
	if(first == last)
		return;
	

		auto temp = middle(first, last);
		auto value = *temp;
		iter_swap(temp, first);
		
		auto midpoint = partition(next(first), last, 
			[&] (typename BidiIter::value_type const& tem) 
			{return tem < value; } //The partition will move any value thats less than tem to in front of the tem, otherwise if its greater it will move it behind
		);

		// swap back *first to where it should be (if necessary)
		auto midpoint_prev = midpoint;
  		if (first != midpoint)//Checks the midpoint is equal to the first, if its not it switchs to be be the case
  		{
   			midpoint_prev = prev(midpoint);
    			iter_swap(first, midpoint_prev);
  		}

		/*if (midpoint_prev != last)
			cout << "test3: " << *first << " to " << *midpoint_prev << "\n";
		else
			cout << "test3\n";
		*/		
		quick_sort(first, midpoint_prev);

		/*if (midpoint != last)
			cout << "test4: " << *midpoint << " to " << *prev(last) << "\n";
		else
			cout << "test4\n";	
		*/	
		quick_sort(midpoint, last);

}


/*
The main() function:

-declares a std::list variable,
-For reference purposes here assume this variable is called "words".
-read in from std::cin std::string values until there is an error or end-of-file appending each to words,
-call quick_sort(begin(words), end(words) to sort the list, and,
-output the entire list to std::cout after the sorting has completed.

*/
int main()
{
	int i;

	list<int> words;
	while (cin >> i)
		words.push_back(i);	
	//cout << "test1\n";
	quick_sort(words.begin(), words.end());

	for (list<int>::iterator i = words.begin(), iEnd = words.end(); i != iEnd; ++i)
		cout << *i << "\n";
	//cout << '\n';

	return 0;
}
