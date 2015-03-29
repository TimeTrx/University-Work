#include<stdio.h>
#include<math.h>

void Printall(int num1,int Sum1,int num2,int Sum2,int threedigit,int cardnum, int digitthree);


int main (void)
{
int num1, num2, cardnum, Sum1, Sum2, threedigit, digitthree;
scanf("Please type the first digit: %d", &num1);
scanf("Please type the second digit:  %d", &num2);
Sum1 = compute_sum(num1);
Sum2 = compute_sum(num2);
cardnum = (num1* 1000)+threedigit;
digitthree = threedigit - Sum2;
Printall(num1, num2, Sum1, Sum2, threedigit, cardnum, digitthree);
return(0);
}
int compute_sum(int num)
{
int digit1of1, new_number, digit4of1, digit3of1, digit2of1, sum;
new_number = num;
digit4of1 =  new_number % 10;
digit3of1 =  new_number % 10;
digit2of1 =  new_number % 10;
digit1of1 =  new_number / 10;
sum = digit4of1 + digit3of1 + digit2of1 + digit1of1;
return (sum);
}
int find_threedigit(int Sum1, int Sum2)
{
int threedigit;

threedigit = (Sum1*3)+Sum2;
return(threedigit);
}
void Printall(int num1,int Sum1,int num2,int Sum2,int threedigit,int cardnum, int digitthree)
{
printf("The sum of the first four digits, %d is:  %d", num1, Sum1);
printf("The sum of the second four digits, %d is:  %d", num2, Sum2);
printf("The three digit number, %d  is:  %d", Sum1, threedigit);
printf("The three digit number, %d  %d is:  %d", digitthree, Sum2, threedigit);
printf("The card number is:  %d", cardnum);
}
