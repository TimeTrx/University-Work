#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <math.h>
#include <stdlib.h>

double checkplus(double, double);
double checkneg(double, double);
void checkit(char []);

int main()
{
	char buffer[5], total1[5], total2[5];
	int a, b = 0, c = 0;
	double num1 = 0, num2 = 0, totalplus, totalneg;
	size_t first, second, result1, result2;
	do{
	
	first = fread(buffer+b, 1, 1,stdin);//stdin for input from keyboard, stdout for screen output, buffer+b moves it the size of b
	
	b++;

	}while(buffer[b-1] != '\n');
	
	//buffer[first] = '';//adds null char to end of buffer
	checkit(buffer);
       	num1 = atof (buffer);
	//num1 = atof (buffer); //convert the char of numbers into a double	
	do{
	second = fread(buffer+c, 1, 1, stdin);//stdin for input from keyboard, stdout for screen output
	//buffer[second] = '';//adds null char to end of buffer
	
	c++;
	}while(buffer[c-1] != '\n');
	checkit(buffer);
	num2 = atof (buffer);
       	//num2 = atof (buffer);//convert the char of numbers into a double
	totalplus = checkplus(num1, num2);
	totalneg = checkneg(num1, num2);
 	
	gcvt(totalplus, b, total1); //converts the doubles back to strings
	gcvt(totalneg, c, total2);
	
	result1 = fwrite(total1, 1, b, stdout);//This will print out the plus answer
        result2 = fwrite(total2, 1, c, stdout);//This will print out the neg answer
	
	
	return 0;
}

void checkit(char check[])//checks if the number is acceptable, and closes if it is not
{
	int a;
	for(a = 0; a< 5; a++)
	{
	if(check[a] == 'a' ||check[a] == 'b'||check[a] == 'c'||check[a] == 'd'||check[a] == 'e'||check[a] == 'f'||check[a] == 'g'||check[a] == 'h'||check[a] == 'i'||check[a] == 'j'||check[a] == 'k'||check[a] == 'l'||check[a] == 'm'||check[a] == 'n'||check[a] == 'o'||check[a] == 'p'||check[a] == 'q'||check[a] == 'r'||check[a] == 's'||check[a] == 't'||check[a] == 'u'||check[a] == 'v'||check[a] == 'w'||check[a] == 'x'||check[a] == 'y'||check[a] == 'z')//checks for char a to z. 
	{
		exit(1);//kills the program if char found!
	}
	
	}//else
	//{
	//exit(1);//exits
	//}
	
}


double checkplus(double num1, double num2)//adds the two doubles together
{
	double total;
	total = num1 + num2;
	return total;
}

double checkneg(double num1, double num2)//subtracts the two doubles
{
	double total;
	total = num1 - num2;
	return total;
}
