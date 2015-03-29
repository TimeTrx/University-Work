#include <stdio.h>
#define ROW 11
#define COL 4
int ReadData (int [][COL]);
void RowCalc (int [][COL]);
void ColumnCalc (int [][COL]);
int rows;
int po = 0;
int main(void){
  int score[ROW][COL];
  ReadData (score);
  RowCalc (score);
  ColumnCalc (score);
  return 0;
}
int ReadData (int score[][COL]){
    int r, c;
    rows = 0;
    printf("Type scores for each row on a new line:\n");
    for (r=0; r<ROW; r++)
    {
       for (c=0; c<COL; c++)
       {
            if (score[r][0] != -1)
            {
                scanf("%d", &score[r][c]);
                if (score[r][c] >= 90)
               {
                  po = po +1;
            }
            }
            if (score[r][0] == -1)
            {
                return 0;
            }
       }
       rows++;
    }


 return 0;
}
void RowCalc (int score[][COL]){
  int r, c, sum, max;
  float avg;
  printf("\t");
  for (c=0;c<COL;c++)
  printf("Test%-3d\t",c+1);
  printf("RowAvg\tRowMin\n");
  for (r=0; r<ROW; r++)
  {
        if (score[r][0] == -1)
        {
            return;
        }
    printf ("\t");
    sum = 0;
    max = score[r][0];
    for (c=0; c<COL; c++)
    {
      printf ("%-6d\t", score[r][c]);
      sum += score[r][c];
      if (score[r][c] < max)
        max = score[r][c];
    }
    avg = (float)sum/COL;
    printf ("%6.2f\t%6d\n", avg, max);
    }
}
void ColumnCalc (int score[][COL]){
  int r, c, col_sum[COL], col_max[COL], t, mint;
  float col_avg[COL+1];
  for (c=0; c<COL; c++)
  {

    col_sum[c] = 0;
    col_max[c] = score[0][c];
    for (r=0; r<rows; r++)
    {

      col_sum[c] = col_sum[c] + score[r][c];
      if (score[r][c] < col_max[c])
        col_max[c] = score[r][c];
    }
    col_avg[c] = (float)col_sum[c]/rows;

  }
  col_avg[4] = (((float)col_sum[0]+col_sum[1]+col_sum[2]+col_sum[3])/4)/rows;
  printf ("\nColAvg\t");
  for (c=0; c<=COL; c=c+1)

    printf ("%-6.2f\t", col_avg[c]);
  printf ("\nColMin ");

  for (c=0; c<COL; c=c+1)
  printf ("\t%-6d", col_max[c]);

  mint = col_max[0];
  for(t=0; t<4; t++)
  {
      if(col_max[t] < mint)
      {
          mint = col_max[t];
      }
  }
  printf ("\t\t     %d\n", mint);
  printf ("There are %d marks that are 90%% or higher!", po);
}
