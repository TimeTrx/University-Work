#include <stdio.h>

int main(void)
{

 int T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, W1, W2, W3, W4, W5, W6, W7, W8, W9, W10, W11, W12;

 int Sum1, Sum2, Sum3, Sum4, Sum5, Sum6, TT, TW;

T1 = 70 * 3.99;
T2 = 60 * 6.00;
T3 = 200 * 12.00;
T4 = 80 * 2.49;
Sum1 = T1+T2+T3+T4;

T5 = 150*2.50;
T6 = 130*4.50;
T7 = 250*15.00;
T8 = 80*2.49;
Sum2 = T5+T6+T7+T8;

T9 = 100*4.00;
T10 = 210*4.00;
T11 = 180*10.00;
T12 = 240*3.10;
Sum3 = T9+T10+T11+T12;

W1 = 150*70;
W2 = 60*5;
W3 = 200*4;
W4 = 80*3;
Sum4 = W1+W2+W3+W4;

W5 = 150*150;
W6 = 130*5;
W7 = 250*4;
W8 = 80*3;
Sum5 = W5+W6+W7+W8;

W9 = 100 * 100;
W10 = 210 * 210;
W11 = 180 * 180;
W12 = 240 * 240;
Sum6 = W9+W10+W11+W12;

TT = Sum1+Sum2+Sum3;
TW = Sum4+Sum5+Sum6;

printf("Details of Goods sent by QR Charity Agency: \n");
printf("****************************** \n");
printf("Total cost of goods in Trunk 1 with HST is: $ %d%0.2f \n",Sum1);
printf("Total cost of goods in Trunk 2 with HST is: $%d%0.2f \n",Sum2);
printf("Total cost of goods in Trunk 3 with HST is: $%d%0.2f \n",Sum3);
printf("****************************** \n");
printf("Total cost of goods in the three trunks with HST is: $%d%0.2f \n",TT);
printf("****************************** \n");
printf("Total weight of goods in Trunk 1: %d lbs \n",Sum4);
printf("Total weight of goods in Trunk 2: %d lbs \n",Sum5);
printf("Total weight of goods in Trunk 3: %d lbs \n",Sum6);
printf("****************************** \n");
printf("Total weight of goods in the three trunks is: %d lbs \n",TW);
printf("****************************** \n");
printf("End of processing !!!\n");
	return 0;

}
