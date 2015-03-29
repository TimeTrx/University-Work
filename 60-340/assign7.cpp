#include <iostream>
#include <map>
#include <list>
#include <string>

typedef 
    std::map<
        std::string, 
        unsigned int> 
    WordHist; //The first map
typedef 
  std::map<
    unsigned int, 
    std::list<std::string>, 
    std::greater<WordHist::mapped_type> 
  > 
  WordsByFreq
; //The second map


int main()
{
  using namespace std;

    WordHist wh;
    string word;
    while (cin >> word)//word gets the input of the string to test
    {
      pair<typename WordHist::iterator, bool> result = 
        wh.insert(make_pair(word,0U));
      ++result.first -> second;  
      word.clear();
    }

    WordsByFreq whbf;
    typename WordHist::const_iterator i = wh.begin();
    typename WordHist::const_iterator iEnd = wh.end();
    for (; i != iEnd; ++i)
    {
      pair<typename WordsByFreq::iterator, bool> test = 
        whbf.insert(
          make_pair(
            i -> second, 
            typename WordsByFreq::mapped_type{}
          )
        )
      ;

      test.first -> second.push_back(i -> first);
    }
    auto fir = whbf.begin();
    auto end = whbf.end();
    for(; fir != end; ++fir)
    {
      cout << fir -> first << ": "; 
      auto exa = fir -> second.begin();
      for(; exa != fir -> second.end(); ++exa)
      {  
        cout << *exa << " "; // ostream operator
      }
      cout << endl;
    }
    return 0;
}


