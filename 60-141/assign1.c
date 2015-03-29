//Morand, Michael
//
//Assignment
//Jan 31, 12
//Objective is to complete the assignment to check if points fall into rectangles
#include <stdio.h>
#include <math.h>
#define length 1000
#define width 11
#define height 11
#define some 11

int input(char t, float i1[], float i2[], float i3[], float i4[]);
int corn(float r1[], float r2[]);
int check(float i1[], float i2[], float i3[], float i4[],float r1[], float r2[]);
int b = 0;
int e = 0;
int main(void)
{
    char t;
    float r1[length];
    float r2[length];
    float i1[length];
    float i2[width];
    float i3[height];
    float i4[some];
    int a;

    input(t,i1,i2,i3,i4);
    corn(r1,r2);
    check(i1, i2, i3, i4, r1, r2);
    return 0;
}
/*input: Allows the program to read the input of rectangles
Input: Uses a .txt to input the rectangle corners
Output: None
*/
int input(char t, float i1[], float i2[], float i3[], float i4[])
{
    int a, counter = 1;

 	scanf("%c",  &t);
	while (t != '*' && counter <= 10)
	{


			if(t == '*')
		    {
		        return 0;
		    }
			else if (t == 'r')
			{

		    	scanf("%f %f %f %f",&i1[counter-1], &i2[counter-1], &i3[counter-1], &i4[counter-1]);
				counter++;
				e++;
			}

		scanf("%c", &t);
		while (t != 'r' && t != '*')
		{
			scanf("%c", &t);
		}
	}
    return 0;
}
/*corn: Allows the program to read the input of points
Input: Uses a .txt to input the points to be checked
Output: None
*/
int corn(float r1[], float r2[])
{
	int a = 0;
	scanf("%f", &r1[a]);
	scanf("%f", &r2[a]);
	int r1a = r1[a];
	int r2a = r2[a];
    a++;
    while(r1a != 9999 && r2a != 9999)
    {

        scanf("%f%f", &r1[a], &r2[a]);
		r1a = r1[a];
		r2a = r2[a];
		a++;
        b++;
    }
    return 0;
}
/*check: Allows the program to check and then print the conclusion of the inputted values
Input: Uses the pre-inputted values of the points and corners
Output: Prints the results of the values inputted into the program
*/
int check(float i1[], float i2[], float i3[], float i4[],float r1[], float r2[])
{
    int a, c;
    int d;
    for(c = 0; c < b; c++)
    {
        d = 0;
        for(a = 0; a < e; a++)
        {


            if(i1[a] < r1[c])
            {



                if(i3[a] > r1[c])
                {

                    if(i4[a] < r2[c])
                    {

                        if(i2[a] > r2[c])
                        {

                            printf("Point %d is contained in figure %d\n", c+1, a+1);
                            d = d + 1;
                        }
                    }
                }
            }

        }
        if (d == 0)
            {
                printf("Point %d is not contained in any figure\n", c+1);
            }

    }
    return 0;
}
