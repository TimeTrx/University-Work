#include<stdio.h>
#include<math.h>

int main (void)
{
int num1, num2, num3, n11, n12, n13, n14, n21, n22, n23, n24, n31, n32, n33, n34;
printf("Please enter two four digit numbers \t");

scanf("%d%d", &num1, &num2);

num1 = num1%10;
n11 = n11/10;
num1 = num1%10;
n12 = n11/10;
num1 = num1%10;
n13 = n11/10;
num1 = num1%10;
n14 = n11/10;

n21 = num1%10;
 = n11/10;
n22 = num1%10;
num2 = n11/10;
n23 = num1%10;
num2 = n11/10;
n24 = num1%10;
num2 = n11/10;

n31 = (n11 + n21)/2;
n32 = (n12 + n22)/2;
n33 = (n13 + n23)/2;
n34 = (n14 + n24)/2;

num3 = (n34 *1000) + (n33 * 100) + (n32 *10) + (31 *1);
printf("Your result is: \n");
printf("%d",num3"\n");


return(0);
}
