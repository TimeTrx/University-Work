#include <stdio.h>
//Michael Morand  Section Number: 60-140 Date: Oct 17, 11 Lab: 51
float WasherWeight (float,float,float,float, float);
void CircleArea(float, float, float *);
void PrintWeight (float,float,float,float,float,float,float,float,float,float,float,float,float,float,float,float, float);
int main(void)
{
float quantity,thickness,density,inner,outer,Weight1,Weight2,Weight3, Weight4,Area,Quantity1,Quantity2,Quantity3,Quantity4,Thickness1,Thickness2,Thickness3,Thickness4,Density1,Density2,Density3,Density4,TotalWeight, r =0,t=0;
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
Area = CircleArea(outer, inner, r);
Weight1 = WasherWeight(Area, density, thickness, quantity, t);
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
Area = CircleArea(outer, inner, r);
Weight2 = WasherWeight(Area, density, thickness, quantity, t);
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
CircleArea(outer, inner, &Area);
Weight3 = WasherWeight(Area, density, thickness, quantity, t);
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
Area = CircleArea(outer, inner, r);
Weight4 = WasherWeight(Area, density, thickness, quantity, t);
TotalWeight = Weight1+Weight2+Weight3+Weight4;
PrintWeight(Quantity1,Quantity2,Quantity3,Thickness1,Thickness2,Thickness3,Thickness4,Quantity4,Density1,Density2,Density3,Density4,Weight1,Weight2,Weight3,Weight4,TotalWeight);
	return 0;
}

void CircleArea(float outer,float inner, float *r)
{

    *r = (((outer/2)*(outer/2))*3.141)-(((inner/2)*(inner/2))*3.141);

}

float  WasherWeight(float Area,float density,float thickness, float quantity, float t)
{
    t = (Area*density*thickness)*quantity;
    return t;
}

void PrintWeight(float Quantity1,float Quantity2, float Quantity3,float Thickness1, float Thickness2,float Thickness3, float Thickness4,float Quantity4, float Density1, float Density2, float Density3, float Density4, float Weight1,float Weight2,float Weight3,float Weight4,float TotalWeight)
{
printf("Washer Type\t Qty\t Thickness\t Density\t Weight\n");
printf("A                 %.0f\t %.1f\t\t %.1f\t\t %.1f \n",Quantity1, Thickness1, Density1, Weight1);
printf("B                 %.0f\t %.1f\t\t %.1f\t\t %.1f \n",Quantity2, Thickness2, Density2, Weight2);
printf("C                 %.0f\t %.1f\t\t %.1f\t\t %.1f \n",Quantity3, Thickness3, Density3, Weight3);
printf("D                 %.0f\t %.1f\t\t %.1f\t\t %.1f \n",Quantity4, Thickness4, Density4, Weight4);
printf("Total Weight******************************************** %.1f\n",TotalWeight);
}
