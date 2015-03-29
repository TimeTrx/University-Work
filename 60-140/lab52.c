#include<stdio.h>
#include<math.h>

int main (void)
{
int sales, taxes;
printf("Please enter total income:\t$");
scanf("%d",&sales);
if (sales >= 200000)
{
taxes = sales * 0.50;
printf("Total taxes to be paid: $%d\n",taxes);
}
else if(sales>= 1500000)
{
taxes = sales * 0.36;
printf("Total taxes to be paid: $%d\n",taxes);
}
else if(sales>= 1000000)
{
taxes = sales * 0.30;
printf("Total taxes to be paid: $%d\n",taxes);
}
else if(sales>= 50000)
{
taxes = sales * 0.20;
printf("Total taxes to be paid: $%d\n",taxes);

}
else if(sales>= 20000)
{
taxes = sales * 0.10;
printf("Total taxes to be paid: $%d\n",taxes);
}
else if(sales < 20000)
{
taxes = 0;
printf("Total taxes to be paid: $%d\n",taxes);
}
return(0);
}
