#include<stdio.h>
#include<math.h>

int main (void)
{
float input1, input2, input3, hst, total, water, chip, milk, subtotal;
int input4;
printf("Please input the cost for bottle of water\n");
scanf("%f", &input1);
printf("Please input the cost for bag of potato chips\n");
scanf("%f", &input2);
printf("Please input the cost for a carton of milk\n");
scanf("%f", &input3);
printf("Please enter age of customer\n");
scanf("%d", &input4);

if (input4 >= 65)
{
water = input1 *3;
chip = input2 * 4;
milk = input3 *2;
subtotal = water + chip + milk;
hst = 0;
printf("Output:\n");
printf("Water 3 @ %.2f:  $%.2f\n",input1, water);
printf("Chips 4 @ %.2f:  $%.2f\n",input2, chip);\
printf("Milk 2 @ %.2f:  $%.2f\n",input3, milk);
printf("Subtotal:  $%.2f\n",subtotal);
printf("HST:  $%.2f\n",hst);
printf("Total:  $%.2f\n",subtotal);
}
if (input4 < 65)
{
water = input1 *3;
chip = input2 * 4;
milk = input3 *2;
subtotal = water + chip + milk;
hst = subtotal *0.13 ;
total = subtotal + hst;
printf("Output:\n");
printf("Water 3 @ %.2f:  $%.2f\n",input1, water);
printf("Chips 4 @ %.2f:  $%.2f\n",input2, chip);\
printf("Milk 2 @ %.2f:  $%.2f\n",input3, milk);
printf("Subtotal:  $%.2f\n",subtotal);
printf("HST:  $%.2f\n",hst);
printf("Total:  $%.2f\n",total);
}
return(0);
}
