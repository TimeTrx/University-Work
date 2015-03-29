#include<stdio.h>
#include<math.h>

int main (void)
{
int B, A, ans1, ans2, ans3, ans4;
printf("Please enter A: \t");
scanf("%d", &A);
printf("Please enter B: \t"); 
scanf("%d", &B);
printf("B/A equals: \t");
ans1 = B/A;
printf("%d",ans1,"\n");
printf("A/B equals: \t");
ans2 = A/B;
printf("%d",ans2,"\n");
printf("B(percent)A equals: \t");
ans3 = B%A;
printf("%d",ans3,"\n");
printf("A(percent)B equals: \t");
ans2 = A%B;
printf("%d",ans4,"\n");
return(0);
}
