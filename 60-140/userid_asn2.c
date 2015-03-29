#include <stdio.h>
//Michael Morand  Section Number: 60-140 Date: Oct 7, 11 Lab: 51
int main(void)
{

 int T1, T2, T3, T4, TotalSecond, Hours, Minutes, Seconds;

 float Sum4, Sum5, Sum6, Sum7, Sum8, Sum9, Sum10, Sum11, Sum12, Sum13;

 printf("What is the length of the rectangular yard (feet)?\t");
 scanf("%d",&T1);
 printf("What is the width of the rectangular yard (feet)?\t");
 scanf("%d",&T2);
 printf("Please enter in the length of the rectangular house (feet):\t");
 scanf("%d",&T3);
 printf("Please enter in the width of the rectangular house (feet):\t");
 scanf("%d",&T4);
TotalSecond = (((T1*T2)-(T3*T4))/2);
Hours=((TotalSecond))/3600;
Minutes=((((TotalSecond))%3600)/60);
Seconds=((((TotalSecond))%3600)%60);
Sum4=(T1*T2);
Sum5=(Sum4*0.3048);
Sum6=(T3*T4);
Sum7=(Sum6*0.3048);
Sum8=Sum4-Sum6;
Sum9=(Sum4-Sum6)*(0.3048);
Sum10=(T1*2)+(T2*2);
Sum11=((T1*2)+(T2*2))*0.3048;
Sum12=((T3*2)+(T4*2));
Sum13=((T3*2)+(T4*2))*0.3048;
printf("------------------------------------------------------------------\n");
printf("The time required to cut the grass in the yard is: %d Hours %d Minutes %d Seconds \n",Hours,Minutes,Seconds);
printf("------------------------------------------------------------------\n");
printf("The area of the yard in square feet is:  %.2f sq. ft.\n",Sum4);
printf("The area of the yard in square meter is: %.2f sq. meter. \n",Sum5);
printf("The area of the house in square feet is: %.2f sq. ft. \n",Sum6);
printf("The area of the house in square meter is: %.2f sq. meter. \n",Sum7);
printf("The area of the grass area in square feet is: %.2f sq. ft.\n",Sum8);
printf("The area of the grass area in square meter is: %.2f sq. meter. \n",Sum9);
printf("The perimeter of the yard in feet is: %.2f ft. \n",Sum10);
printf("The perimeter of the yard in meter is: %.2f meter.\n",Sum11);
printf("The perimeter of the house in feet is: %.2f ft. \n",Sum12);
printf("The perimeter of the house in meter is: %.2f meter. \n", Sum13);
printf("------------------------------------------------------------------\n");
printf("Thank you for using our property evaluation software!!.\n");
printf("Have a great day.\n");
	return 0;

}
