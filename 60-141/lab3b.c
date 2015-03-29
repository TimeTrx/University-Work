
#include<stdio.h>
#include<math.h>

#define MAX 20// number of elements in the array

//Part 2

//1. Exchange the values of 2 integer pointers
void swap(int *, int *);

//2. triple the value of a parameter of type int pointer
int Triple(int *);
//Part3
// 3 Sort the array. sortorder= 1 =) ascending; sortorder = -1 =) descending
void BubbleSort(int [], int, int);// you have to call swap function in part 2

//4 Populate the array with increasing even numbers starting with 4. (example: 4, 6, 8 ...)
void PopulateArray (int []);

//5 Triple the value of each element in the array
int TripleArray(int []);

//6 Print each element in the array
void PrintArray(int [], int );

//7 call Functions in Main
int main (void)
{
	int a;
    int numElements;
    numElements = 20;
    int sortorder;
    scanf("%d", &sortorder);
    int NumList[MAX];
    PopulateArray(NumList);
    PrintArray(NumList, MAX);
	for(a=0; a < MAX; a++)
	{
   		 Triple(NumList+a);
	}
    PrintArray(NumList, MAX);
    BubbleSort(NumList, numElements, sortorder);//ask user about the sort order
    PrintArray(NumList, MAX);

return(0);
}

//***********************
/*PrintArray: Prints the specfic array in a list format
Input: The array to print, the number of elements in the array
Output: None
*/
void PrintArray(int array[], int numElements)
{
	int row;
	int *ptr = array;
	for(row = 0; row < numElements;  row++)
		{
			printf("%-5d", *ptr);
			ptr++;
		}
    printf("\n");
}
//Part 2
//***********************
/*Swap: Switches two integer values around
Input: The two values to be changed
Output: Returns the completed result
*/
void swap(int *value1, int *value2)
{
	int a, b;
	a = *value1;
	b = *value2;
	*value1 = b;
	*value2 = a;
}
//***********************
/*Triple: The function will triple the inputted value
Input: The integer to be tripled
Output: Returned the final value
*/
int Triple(int *value)
{
	int ret;
	ret = 3 * (*value);
	*value = 3 * (*value);
	return ret;
}
//***********************
/*BubbleSort: Sorts the list, by the choosen sortOrder
Input: Takes the array and the sortOrder
Output: The finished sorted array
*/
void BubbleSort(int array[], int numElements, int sortOrder)
{
	int a, b;
	int temp;
	int test;
	if(sortOrder == -1)
	{
        do
        {
            test = 0;
            for(b = 0; b < MAX-1; b++)
            {
                    if(array[b] > array[b+1])
                    {
                        swap(&array[b], &array[b+1]);
                        test = 1;
                    }
            }
        }while(test != 0);
	}
	if(sortOrder== 1)
	{
        do
        {
            test = 0;
            for(b = 0; b < MAX-1; b++)
            {
                    if(array[b] < array[b+1])
                    {
                       swap(&array[b], &array[b+1]);
                       test = 1;
                    }
            }
        }while(test != 0);
	}
}
//***********************
/*PopulateArray: Takes the array and initializes the numbers: 4,6,8,etc
Input: The array to populate, the number of elements in the array
Output: The populated array
*/

void PopulateArray(int NumList[])
{
    int c; //=((2* MAX) + 4);
    int a, d;

    	for(a = 0; a < MAX; a++)
    	{
    	    d = a;
    	    c = (d*2)+4;
       	 	NumList[a] = c;
    	}

}
