#include<stdio.h>
#include<math.h>
void readdata(int[][6]);
void rowcalc(int[][6]);
void colcalc (int[][6]);

void main ()
{
int score [3][6];
readdata(score);
rowcalc(score);
colcalc(score); 
}

void readdata(int score[][6])
{
int r, c;
for(r = 0; r<3; r++)
{
for(c = 0; c<6; c++)
{
scanf("%d", &score[r][c]);
}
}
}

void rowcalc(int score[][6])
{
int min, sum;
int r,c;
float avg;
for(r = 0; r<3; r++)
{
min = score[r][0];
sum = 0;
for(c = 0; c<6; c++)
{
if (score [r][c] < min)
{
min = score [r][c];
sum += score[r][c];
}
avg = sum/6;
printf("RowCalc");
printf("Average: %.0f  Sum:  %d\n", avg, sum);
}
}
}

void colcalc(int score[][6])
{
int min, sum;
int r,c;
float avg;
for(c = 0; c<3; c++)
{
min = score[0][c];
sum = 0;
for(r = 0; r<6; r++)
{
if (score [r][c] < min)
{
min = score [r][c];
sum += score[r][c];
}
avg = sum /6;
printf("ColCalc");
printf("Average:  %.0f   Sum:  %d\n", avg, sum);
}
}
}
