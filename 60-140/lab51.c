#include<stdio.h>
#include<math.h>

int main (void)
{
int input, days, Total;
printf("Please enter the number of days:\t");
scanf("%d",&days);
printf("Please enter the total mileage:\t");
scanf("%d",&input);
Total = input/days;
if(Total > 66)
{
printf("It is better to go with plan A(unlimited mileage).\t");
}
if(Total == 66)
{
printf("Both plans are approximately same!\t");
}

if(Total < 66)
{
printf("It is better to go with plan B(15cents a mile).\t");
}
return(0);
}
