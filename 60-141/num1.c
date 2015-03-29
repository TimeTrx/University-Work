//Morand, Michael
//ID: 103626334
//Lab #2
//Jan 10, 12
//To run the programs from the labs
#include<stdio.h>
#include<math.h>

int fibR(int);
void fib();
int powerR(int, int);
void power();
void drawR(int);
void draw();
void drawuR(int);
void drawu();
int numR(int);
void num();
int n1R(int);
void n1();
int n2R(int);
void n2();
int gcdR(int, int);
void gcd();

int main (void)//Main Function
{
	int input, a, b, c;

	do//Switch used for selecting functions by outputting options
	{
		printf("1. Recursive Fibnacci\n");
		printf("2. Non-Recursive Fibnacci\n");
		printf("3. Recursive Power\n");
		printf("4. Non-Recursive Power\n");
		printf("5. Recursive gcd\n");
		printf("6. Non-Recursive gcd\n");
		printf("7. Recursive 2\n");
		printf("8. Non-Recursive 2\n");
		printf("9. Recursive 1\n");
		printf("10. Non-Recursive 1\n");
		printf("11. Recursive Print Num\n");
		printf("12. Non-Recursive Print Num\n");
		printf("13. Recursive Down Triangle\n");
		printf("14. Non-Recursive Down Triangle\n");
		printf("15. Recursive Up Triangle\n");
		printf("16. Non-Recursive Up Triangle\n");
		printf("0. Exit\n");
		printf("Please enter 0-16\n");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
            scanf("%d", &a);
			b = fibR(a);
			printf("%d\n", b);
			break;
			case 2:
			fib();
			break;
			case 3:
			scanf("%d", &a);
			scanf("%d", &c);
			b = powerR(a, c);
			printf("%d\n", b);
			break;
			case 4:
			power();
			break;
			case 5:
			printf("Please enter X\n");
            scanf("%d", &a);
            printf("Please enter Y\n");
            scanf("%d", &b);
			c = gcdR(a, b);
			printf("gcd(%d, %d)\n", b, c);
			break;
			case 6:
			gcd();
			break;
			case 7:
			scanf("%d", &a);
			b = n2R(a);
			printf("%d\n", b);
			break;
			case 8:
			n2();
			break;
			case 9:
			scanf("%d", &a);
			b = n1R(a);
			printf("%d\n", b);
			break;
			case 10:
			n1();
			break;
			case 11:
			scanf("%d", &a);
			b = numR(a);
			printf("%d \n", b);
			break;
			case 12:
			num();
			break;
			case 13:
			scanf("%d", &a);
			drawR(a);
			break;
			case 14:
			draw();
			break;
			case 15:
			scanf("%d", &a);
			drawuR(a);
			break;
			case 16:
			drawu();
			break;
		}
	}

	while(input != 0);
	return(0);
}
//compute  the draw function
//Input one number.It will create a right side down triangle
//Output will be determined by the number inputted and will output the a triangle of stars with the top row
void draw()
{
    int a, b, c, d;
    scanf("%d", &a);
    d = a;
    for(c = 1; c <= a; c++)
    {

        for(b = 1; b <= d; b++)
        {
            printf("*");

        }
        d = d - 1;
        printf("\n");
    }

}
//compute power
//The first is the base, second is power
//OUPUT is the base (a) to the power of b
void power()
{
	int b, a;
	scanf("%d", &b);
	int power = 1;
	for (a = 1; a < b; a++)
	{
		power*=a;
	}
	printf("%d\n", power);
}
//compute  the n1R function
//It will take the inputted value and by recursion
//will add up the value and output the total (factorial)
 int n1R(int a)
 {
     int b = 0;
     if (a == 0)// base case
     {
         return 0;
     }
    b = a + n1R(a-1);// recursive step
    return b;


 }
//compute  the drawuR function
//It will take the inputted value and by recursion
//will output a up side up triangle
void drawuR(int a)
{


    if(a < 1)// base case
    {
      return;
    }
    else// recursive step
    {
        drawuR(a -1);
        while(a > 0)
        {

            printf("*");
            a--;
        }

        a--;
        printf("\n");
    }

}
//compute  the drawu function
//It will take the inputted value and
//will output a up side up triangle by a loop
void drawu()
{
int a, b, c;
    scanf("%d", &a);
    for(c = 1; c <= a; c++)
    {

        for(b = 1; b <= c; b++)
        {
            printf("*");
        }
      printf("\n");
    }
}
//compute  the n2R function
//It will take the inputted value and by recursion
//will take the function and add up the total
int n2R(int a)
{
     int b = 0;
     if (a == 0)// base case
     {
         return 0;
     }
    b = ((a+1)*(a+1)) + n1R(a-1);// recursive step
    return b;
}
//compute power
//The first is the base, second is power
//Uses recursion to OUPUT the total, output is the base (a) to the power of b
int powerR(int a, int b)
{

    if (b==1)// base case
    {
        return a * 1;
    }
    if (b >-1)// recursive step
    {
        b--;
        return a * (powerR(a, b));
    }

}
//compute fibbonici
//The fib will compute the fib function
//OUPUT is the total value of the fib function
void fib()
{
    int a;
    scanf("%d", &a);
	int d;
	int t;
	int b = 0;
	int c = 1;
	for(t = 2; t <= a; t++)
	{
		d = c + b;
		b = c;
        c = d;
	}
	printf("%d\n", c);
}
//compute drawR
//The function takes the input and by recursion
//OUPUTS a right side up triangle of stars
void drawR(int a)
{
    int g;
    if(a == 0)// base case
    {
      return;
    }
    else// recursive step
    {
        for(g = 0; g < a; g++)
        {

            printf("*");

        }

        a--;
    printf("\n");
    drawR(a);
    }


}
//compute numR
//The function takes the input and by recursion
//OUPUTS the numbers in dcreasing order
int numR(int a)
{
	if (a<=1)// base case
		return a;
	else
	{
		printf("%d ", a);// recursive step
		numR(a-1);
	}

}
//compute numR
//The function takes the input and
//OUPUTS the numbers in dcreasing order
void num()
{
    int a, b;
    scanf("%d", &b);
    printf("Print(%d) = ", b);
    for(a = b; a > 0; a--)
    {
        printf("%d ", a);
    }
    printf("\n");
}
//compute fibbonici
//The fib will compute the fib function
//OUPUT is the total value of the fib function by using recursion
int fibR(int a)
{
    if (a == 0 || a==1 )// base case
    {
      return a;
    }
	 else// recursive step
	 {
	     return fibR(a - 1) + fibR (a - 2);
	 }
}

//compute  the n1 function
//It will take the inputted value and
//will add up the value and output the total (factorial)
void n1()
{
    int a, b;
    int c = 0;
    scanf("%d", &a);

    for(b = 1; b <= a; b++)
     {
      c += b;
     }
     printf("%d", c);
     printf("\n");
}
//compute  the n2 function
//It will take the inputted value and
//will take the function and add up the total eg. (n+1)^2
void n2()
{
    int a,b;
    int c = 0;
    scanf("%d", &a);

    for(b = 1; b <= a; b++)
     {
      c += (b + 1)*(b + 1);
     }
     printf("%d", c);
     printf("\n");


}
//compute gcd
//The function takes the two inputs
//and will output the value depending on the inputs, (eg. gcd(1, 3mod8))
void gcd()
{
    int e, r, t;
    printf("Please enter X\n");
    scanf("%d", &e);
    printf("Please enter Y\n");
    scanf("%d", &r);
    if (r == 0)
    {
        printf("%d \n", e);
    }

    if (r > 0)
    {
        t = e % r;
        printf("gcd(%d , %d)\n", r, t);
    }
}
//compute gcdR
//The function takes the two inputs and by recursion
//will output the value depending on the inputs, (eg. gcd(1, 3mod8))
int gcdR(int a, int b)
{
    int t;
    if (b == 0)// base case
    {
        return a;
    }

        t = a % b;// recursive step
        return t;
}
