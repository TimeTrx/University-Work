/*Morand, Michael

Lab # 2
Jan 17, 12
Working with 2D Arrays including initialization, populate, sort, search, print, left shift, etc
*/
#include <stdio.h>
#include <math.h>
#include <time.h>
#define M 10
#define N 5


int main(void)
{
    int input;
    int array [M] [N];
    do//Switch used for selecting functions by outputting options
	{
		printf("1. Initialize the Array\n");
		printf("2. Randomly Populate the Array\n");
		printf("3. Sort\n");
		printf("4. Search\n");
		printf("5. Left Shift\n");
		printf("6. Print Array\n");
		printf("0. Exit\n");
		printf("Please enter 0-7\n");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
			initializearray2d(array[M][N]);
			break;
			case 2:
			populaterandomvalue2d(array[M][N]);
			break;
			case 3:
			sort2d(array[M][N]);
			break;
			case 4:
			linearsearch2d(array[M][N]);
			break;
			case 5:
			leftshift2d(array[M][N]);
			break;
			case 6:
			printarray2d(array [M][N]);
			break;
		}
	}
    while(input != 0);
    return 0;
}
/*initializearray2d: populates an array with integers of zeroes
Input: The array to populate, the number of rows and columns to populate (starting top -left)
Output: None
*/
void initializearray2d(int array[M][N])
{
    int a, b;

    for (a = 0; a < M; a++)
    {
        for (b = 0; b < N; b++)
        {
            array[a][b] = 0;
        }
    }
}

/*Poplulaterandomvalue2d: populates an array with random integers in the range 1 to 100
Input: The array to populate, the number of rows and columns to populate (starting top -left)
Output: None
*/
void populaterandomvalue2d(int array [M][N])
{
    //Seed the random number generator, so that the numbers are different each time
    //use the following functions to generate random number between 1 to 100
    srand(time(NULL));
    int i, j;
    for (i = 0; i <=M; i++)
    {
        for (j = 0; j <= N; j++)
        {
            array[i][j]= 1+ rand()%100;
        }

    }


}
/*Sort2d: Performs a 2d version of the bubble sort on the specified 2d array
Input: The array to sort, the number of rows and columns to sort (starting top-left)
Output: NONE
*/
void sort2d (int array [M][N])
{
    int i, j;
    int q;
    int size = M * N;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (array[i][j] > array [i][j+1])
            {
               q = array[i][j];
               array[i][j] = array[i][j+ 1];
               array[i][j +1] = q;
            }
        }

    }
}
/*linearsearch2d: searches an array for a selected value
Input: The array to populate, the number of rows and columns to populate (starting top -left), and the value to search for
Output: Result of the search
*/
void linearsearch2d(int array [M][N])
{
    int key, a, b;
    printf("Please enter an search number:\t");
    scanf("%d", &key);
    for (a = 0; a < M; a++)
    {
        for (b = 0; b < N; b++)
        {
            if(array[a][b] == key)
            {
                printf("Number: %d Found At: &d, %d\n", key, M, N);
                return;
            }
        }
    }
    printf("Sorry, Number Not Found");
}
/*printarray2d: prints the array
Input: The array, the number of rows and columns to populate (starting top -left)
Output: The values of the array
*/
void printarray2d(int array [M][N])
{
    int a, b;

    for (a = 0; a < N; a++)
    {
        for (b = 0; b < N; b++)
        {
           printf("%d\t", array[a][b]);
        }
        printf("\n");
    }
}
/*leftshift2d: shifts the value of the array to the left
Input: The array, the number of rows and columns to populate (starting top -left)
Output: None
*/
void leftshift2d(int array [M][N])
{
    int i, j;
    int q;
    q = array[0][0];
    for (i = 0; i < 1; i++)
    {
        for (j = 1; j < 3; j++)
        {
               array[i][j-1] = array[i][j];
        }
    }
    array[0][3] = array [1][0];
     for (i = 1; i < 2; i++)
    {
        for (j = 1; j < 3; j++)
        {
               array[i][j-1] = array[i][j];
        }
    }
    array[1][3] = array [2][0];

    for (i = 2; i < 3; i++)
    {
        for (j = 1; j < 3; j++)
        {
               array[i][j-1] = array[i][j];
        }
    }
    array[2][3] = array [3][0];
    for (i = 3; i < 4; i++)
    {
        for (j = 1; j < 3; j++)
        {
               array[i][j-1] = array[i][j];
        }
    }
    array[3][3] = q;
}
