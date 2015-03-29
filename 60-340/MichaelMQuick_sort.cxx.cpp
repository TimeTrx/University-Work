#include <iostream>
#include <utility>
#include <algorithm>
#include <list>
#include <string>

template <typename BidiIter>
BidiIter middle(BidiIter first, BidiIter last)//as ordered in assignment
{
    BidiIter two = first;
    for(; two != last; first++)
    {
        two++;
        if(two != last)
            two++;
        else 
            break; 
    } 
    
    return first;
}

template <typename BidiIter> 
void quick_sort(BidiIter first, BidiIter last)//as ordered in assignment 
{
    if(first == last || next(first) == last)
        return;
    BidiIter mid = middle(first, last);//sends these to find the middle
    BidiIter nf = first;
    nf++;
    std::iter_swap(first, mid);//swaps the first with the mid
    auto f1 = [&] (typename BidiIter::value_type const& v) { return v < *first; }; //lambda function
    BidiIter ret = std::partition (nf, last, f1);//calls partition
    std::iter_swap(first, prev(ret));//swaps the first back with the mid
    
    quick_sort(ret,last); // First range
    quick_sort(first,prev(ret)); 
}

int main()
{
  using namespace std;
  list<string> words;
  string word; // declares a std::forward_list variable
  while(cin >> word)
    words.push_front(word);
 
  quick_sort(words.begin(), words.end());
  for(auto elem : words)
  {
   cout << elem << "\n";
  }
          
}
