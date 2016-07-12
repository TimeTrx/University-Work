#include <cstdlib>
#include <iostream>
#include <array>


using namespace std;


void insert2(int);
int size2();
int removeMin();

const int size = 25; //standard size for everything; from arrays to the size of the heap
int heap[size];
int vals[size];
int final[size];

void heapsort()
{
    int n;
    n = size2();
    int a = 0;
    for(; a < n; a++)
    {
        insert2(a);
        n = size2();
    }
    n = size2();
    for(a = 0; a = 0 || final[a] != 0; a++)
    {
        
       final[a] = removeMin();
       n = size2();
       cout << final[3];
    }
    
}

void insert2(int a)
{

    int a2 = size2();
    heap[a2] = vals[a];
    while(a != 1 && heap[a2] < heap[a2/2])
    {
        swap(heap[a2], heap[a2/2]);
    }
    
}

int min(int a)
{
    int value = heap[a];
    return value;
}

int removeMin()
{
    
    int value = heap[1];
    int count; 
    count = size2();
    heap[1] = heap[count];
    int a = 1;
    while((a*2) < count && (a*2+1) < count)
    {
    if(heap[a] > heap[a*2] && heap[2*a] < heap[2*a+1])
        {
            swap(heap[a], heap[a*2]);
            a = a*2;
           
        }
        
        else if(heap[a] > heap[a*2] && heap[2*a] > heap[2*a+1])
        {
            swap(heap[a], heap[a*2+1]);
            a = a*2 +1;
            
        }
      }
        cout << value;
    return value;
}

bool isEmpty()
{
    if(heap[0] == 0)
    return true;
    else
    return false;
}

int size2()
{
    int a = 1;
    while(heap[a] != 0)
    {
        a++;
    }
    
    cout << a << "\n";
    return a;
}

int main()
{
  int n = size;
 
  for (int i = 0; i < n; i++) 
  {
    vals[i] = (rand()%100) + 1;
  }
 
  cout << "Array to be sorted:\n";
  for (int i = 0; i < n; i++) 
  {
    cout << vals[i] << " ";
  }
  cout << "\n";
  heapsort();
 
  
  cout << "Sorted Array:\n";
  for (int i = 0; i < n; i++) 
  {
    cout << final[i] << " ";
  }
  cout << "\n";
  return 0;
}
