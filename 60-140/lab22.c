#include<stdio.h>
#include<math.h>

int main (void)
{
int c, f;
printf("Please enter a Celsius temperature: \t");

scanf("%d", &c);

f = ((c * 9/5) + 32); 

printf("The temperature in Fahrenheit: \n");
printf("%d",f,"\n");
return(0);
}
