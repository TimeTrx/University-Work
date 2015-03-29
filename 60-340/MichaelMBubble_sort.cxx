#include <iostream>
#include <utility>
#include <algorithm>
#include <forward_list>
#include <string>

template <typename FwdIter> void bubble_sort(FwdIter first, FwdIter last)//as ordered in 
{

	bool swapped = false;
	
	FwdIter temp = first;  
	FwdIter i;
	temp++;
	//loops until sort is complete
	do{
	    swapped = false;
	    for(i = first; i != last && temp != last; first++) //runs the cycle of the loop
	    {
	        
	        if(*i > *temp)//checks that for the elements that are greater are sorted from the ones that are 
	        {
	            std::iter_swap(i, temp);
	            swapped = true;
	        }
	       temp++;
		}
	}while(!swapped && temp != last);	
	
}

int main()
{
   using namespace std;
  forward_list<string> words;
  string word; // declares a std::forward_list variable
  while(cin >> word)
    words.push_front(word);
  bubble_sort(words.begin(), words.end());
  for(auto elem : words)
  {
    cout << elem << "\n";
  }
          
}
