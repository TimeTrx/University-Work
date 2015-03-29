#include <stdio.h>
//Michael Morand Student number: 103626334 Section Number: 60-140 Date: Oct 17, 11 Lab: 51
int WasherWeight ();
float quantity,thickness,density,inner,outer,Weight1,Weight2,Weight3, Weight4,Area,Quantity1,Quantity2,Quantity3,Quantity4,Thickness1,Thickness2,Thickness3,Thickness4,Density1,Density2,Density3,Density4,TotalWeight;
int CircleArea();
void PrintWeight ();
int main(void)
{
printf("Enter quantity, thickness, density, inner diameter, outer diameter for\nWasher Type 1:\n");
printf("Enter quantity:  \t");
scanf("%f",&quantity);
printf("Enter thickness:\t");
scanf("%f",&thickness);
printf("Enter density:  \t");
scanf("%f",&density);
printf("Enter inner diameter:\t");
scanf("%f",&inner);
printf("Enter outer diameter:\t");
scanf("%f",&outer);
Density1 = density;
Thickness1 = thickness;
Quantity1 = quantity;
Area = CircleArea();
Weight1 = WasherWeight();
printf("Enter quantity, thickness, density, inner diameter, outer diameter for\nWasher Type 2:\n");
printf("Enter quantity:  \t");
scanf("%f",&quantity);
printf("Enter thickness:\t");
scanf("%f",&thickness);
printf("Enter density:  \t");
scanf("%f",&density);
printf("Enter inner diameter:\t");
scanf("%f",&inner);
printf("Enter outer diameter:\t");
scanf("%f",&outer);
Density2 = density;
Quantity2 = quantity;
Thickness2 = thickness;
Area = CircleArea();
Weight2 = WasherWeight();
printf("Enter quantity, thickness, density, inner diameter, outer diameter for\nWasher Type 3:\n");
printf("Enter quantity:  \t");
scanf("%f",&quantity);
printf("Enter thickness:\t");
scanf("%f",&thickness);
printf("Enter density:  \t");
scanf("%f",&density);
printf("Enter inner diameter:\t");
scanf("%f",&inner);
printf("Enter outer diameter:\t");
scanf("%f",&outer);
Density3 = density;
Quantity3 = quantity;
Thickness3 = thickness;
Area = CircleArea();
Weight3 = WasherWeight(Area, density, thickness, quantity);
printf("Enter quantity, thickness, density, inner diameter, outer diameter for\nWasher Type 4:\n");
printf("Enter quantity:  \t");
scanf("%f",&quantity);
printf("Enter thickness:\t");
scanf("%f",&thickness);
printf("Enter density:  \t");
scanf("%f",&density);
printf("Enter inner diameter:\t");
scanf("%f",&inner);
printf("Enter outer diameter:\t");
scanf("%f",&outer);
Density4 = density;
Quantity4 = quantity;
Thickness4 = thickness;
Area = CircleArea();
Weight4 = WasherWeight();
TotalWeight = Weight1+Weight2+Weight3+Weight4;
PrintWeight();
	return 0;
}

int CircleArea()
{

float r;
    r = (((outer-inner)*(outer-inner))*3.142);
return (r);
}

int WasherWeight()
{
float r;
    r = (Area*density*thickness)*quantity;
return (r);
}
void PrintWeight()
{
printf("Washer Type\t Qty\t Thickness\t Density\t Weight\n");
printf("A                 %.1f\t %.1f\t\t %.1f\t\t %.1f \n",Quantity1, Thickness1, Density1, Weight1);
printf("B                 %.1f\t %.1f\t\t %.1f\t\t %.1f \n",Quantity2, Thickness2, Density2, Weight2);
printf("C                 %.1f\t %.1f\t\t %.1f\t\t %.1f \n",Quantity3, Thickness3, Density3, Weight3);
printf("D                 %.1f\t %.1f\t\t %.1f\t\t %.1f \n",Quantity4, Thickness4, Density4, Weight4);
printf("Total Weight******************************************** %.1f\n",TotalWeight);
}
