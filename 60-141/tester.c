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
	printf("Welcome to the Program!\n");
    input(t,i1,i2,i3,i4);
    corn(r1,r2);
    check(i1, i2, i3, i4, r1, r2);
    return 0;
}

int input(char t, float i1[], float i2[], float i3[], float i4[])
{
    int a, counter = 1;
	printf("Please Select Shape(Rectangle = r)\n");
 	scanf("%c",  &t);
	while (t != '*' && counter <= 10)
	{


			if(t == '*')
		    {
		        return 0;
		    }
			else if (t == 'r')
			{
				printf("Please Enter the Four Corners of the Rectangle: %d \n", counter);
		    	scanf("%f %f %f %f",&i1[counter-1], &i2[counter-1], &i3[counter-1], &i4[counter-1]);
				counter++;
			}

		printf("Please Select Shape(Rectangle = r)\n");
		scanf("%c", &t);
		while (t != 'r' && t != '*')
		{
			scanf("%c", &t);
		}
	}
    return 0;
}

int corn(float r1[], float r2[])
{
	int a = 0;
	printf("Please Select Points(Select 9999.9 to stop)");
	scanf("%f", &r1[a]);
	scanf("%f", &r2[a]);

    while(r1[a] != 9999.9 && r2[a] != 9999.9)
    {
		printf("Test3\n");
		printf("Please Select Points(Select 9999.9 to stop)");
        scanf("%f%f", &r1[a], &r2[a]);
		a++;
        b++;
    }
    return 0;
}

int check(float i1[], float i2[], float i3[], float i4[],float r1[], float r2[])
{
    int a, c;
    int d;
    for(a = 0; a < 10; a++)
    {

        for(c = 0; c < b; c++)
        {
            d = 0;
            if(i1[a] < r1[c])
            {
                if(i2[a] > r1[c])
                {
                    if(i3[a] < r2[c])
                    {
                        if(i4[a] > r2[c])
                        {
                            printf("Point %d is contained in figure %d\n", c+1, a+1);
                            d++;
                        }
                    }
                }
            }
           /* if (d == 0)
            {
               printf("Point %d is not contained in any figure\n", c+1);
            }*/

        }
    }
    return 0;
}
