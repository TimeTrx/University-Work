/*Morand, Michael
103626334
Lab # 2
Jan 17, 12
Working with 2D Arrays including initialization, populate, sort, search, print, left shift, etc
*/
#include <stdio.h>
#include <math.h>
#include <time.h>
#define M 10
#define N 5
void initializearray2d (int array[][N]);
void populaterandomvalue2d(int array[][N]);
void sort2d(int array[][N]);
void linearsearch2d(int array[][N]);
void printarray2d (int array[][N]);
void leftshift2d(int array[][N]);

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
		printf("Please enter 0-6\n");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
			initializearray2d(array);
			break;
			case 2:
			populaterandomvalue2d(array);
			break;
			case 3:
			sort2d(array);
			break;
			case 4:
			linearsearch2d(array);
			break;
			case 5:
			leftshift2d(array);
			break;
			case 6:
			printarray2d(array);
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
void initializearray2d(int array[][N])
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
void populaterandomvalue2d(int array [][N])
{
    //Seed the random number generator, so that the numbers are different each time
    //use the following functions to generate random number between 1 to 100
    srand(time(NULL));
    int i, j;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            array[i][j]= 1+ rand()%100;
        }

    }


}
/*Sort2d: Performs a 2d version of the bubble sort on the specified 2d array
Input: The array to sort, the number of rows and columns to sort (starting top-left)
Output: NONE
*/
void sort2d (int array [][N])
{
    int i, j, a;
    int q;
    int size = M * N;

    /*for (i = 0; i < size; i++)
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

    }*/
    for(a = 0; a <(size-1); a++)
    {
        for (i = 0; i < M; i++)
        {
            for (j = 0; j < N; j++)
            {

                if(array[i][j] > array[i][j+1])
                {
                    q = array[i][j];
                    array[i][j] = array[i][j+1];
                    array[i][j+1] = q;
                }

            }
        }
        if(array[i][N-1] > array[i+1][0])
        {
            q = array[i][N-1];
            array[i][N-1] = array[i+1][0];
            array[i+1][0] = q;
        }
    }
}

/*linearsearch2d: searches an array for a selected value
Input: The array to populate, the number of rows and columns to populate (starting top -left), and the value to search for
Output: Result of the search
*/
void linearsearch2d(int array [][N])
{
    int key;
    int a;
    int b;
    int val;
    int val1;
    printf("Please enter an search number:\t");
    scanf("%d", &key);
    for (a = 0; a < M; a++)
    {
        if(a == 0)
        {
            val1 = 0;
        }
        if(a == 1)
        {
            val1 = 5;
        }
        if(a == 2)
        {
            val1 = 10;
        }
        if(a == 3)
        {
            val1 = 15;
        }
        if(a == 4)
        {
            val1 = 20;
        }
        if(a == 5)
        {
            val1 = 25;
        }
        if(a == 6)
        {
            val1 = 30;
        }
        if(a == 7)
        {
            val1 = 35;
        }
        if(a == 8)
        {
            val1 = 40;
        }
        if(a == 9)
        {
            val1 = 45;
        }

        for (b = 0; b < N; b++)
        {
            val = val1 + (b+1);
            if(array[a][b] == key)
            {

                printf("Number: %d Found At: %d\n", key, val);
            }
        }
    }
}
/*printarray2d: prints the array
Input: The array, the number of rows and columns to populate (starting top -left)
Output: The values of the array
*/
void printarray2d(int array [][N])
{
    int a, b;

    for (a = 0; a < M; a++)
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
void leftshift2d(int array [][N])
{
    int i, j;
    int q;
    q = array[0][0];
    for (i = 0; i < 1; i++)
    {
        for (j = 1; j <= 4; j++)
        {
               array[i][j-1] = array[i][j];
        }
    }
    array[0][4] = array [1][0];
     for (i = 1; i < 2; i++)
    {
        for (j = 1; j <= 4; j++)
        {
               array[i][j-1] = array[i][j];
        }
    }
    array[1][4] = array [2][0];

    for (i = 2; i < 3; i++)
    {
        for (j = 1; j <= 4; j++)
        {
               array[i][j-1] = array[i][j];
        }
    }
    array[2][4] = array [3][0];
    for (i = 3; i < 4; i++)
    {
        for (j = 1; j <= 4; j++)
        {
               array[i][j-1] = array[i][j];
        }
    }
    array[3][4] = array [4][0];
	for (i = 4; i < 5; i++)
    {
        for (j = 1; j <= 4; j++)
        {
               array[i][j-1] = array[i][j];
        }
    }
    array[4][4] = array [5][0];

    for (i = 5; i < 6; i++)
    {
        for (j = 1; j <= 4; j++)
        {
               array[i][j-1] = array[i][j];
        }
    }
    array[5][4] = array [6][0];
    for (i = 6; i < 7; i++)
    {
        for (j = 1; j <= 4; j++)
        {
               array[i][j-1] = array[i][j];
        }
    }
    array[6][4] = array [7][0];
	for (i = 7; i < 8; i++)
    {
        for (j = 1; j <= 4; j++)
        {
               array[i][j-1] = array[i][j];
        }
    }
    array[7][4] = array [8][0];

    for (i = 8; i < 9; i++)
    {
        for (j = 1; j <= 4; j++)
        {
               array[i][j-1] = array[i][j];
        }
    }
    array[8][4] = array [9][0];
    for (i = 9; i < 10; i++)
    {
        for (j = 1; j <= 4; j++)
        {
               array[i][j-1] = array[i][j];
        }
    }
	array[9][4] = q;
}

