#include<stdio.h>
#include<math.h>
int item = 0, itemcount = 0, quantity;
float price, totalsales = 0;
int main (void)
{
printf("Please enter item code (enter -1 to stop):\t");
scanf("%d", &item);
while (item != -1)
{
itemcount++;
printf("Please enter quantity:\t");
scanf("%d", &quantity); 
printf("Please enter the price:\t$");
scanf("%f", &price);
printf("Item Code: \t %d \t Total sales: \t $%0.2f \n", item, quantity*price);
totalsales += quantity*price;
printf("Please enter item code:\t");
scanf("%d", &item);
}
return(0);
}
