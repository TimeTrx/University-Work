#include <stdio.h>

 

/*   function prototype declaration for FindSum   */

void FindSum(int, int, int *);

int main(void)

{

int a=2, b=5, c=1, x=3, y=4, z=7;

 

/*   body of main   */

  FindSum (a, b, &c);    /* a first call to FindSum   */

  printf(\u201cfirst call in main %d  %d  %d  %d  %d  %d \n\u201d, a, b, c, x, y, z); 

  FindSum (x, y, &z);    /* a second call to FindSum   */

  printf(\u201csecond call in main %d  %d  %d  %d  %d  %d \n\u201d, a, b, c, x, y, z); 

  return  0;

}

 

/*   definition of FindSum   */

void FindSum (int a, int b, int *c)

{

  a += (b * 2);

  b += (B * 2);

*c += (b * 2);

  printf(\u201cin FindSum: %d  %d  %d \n\u201d, a, b, *c); 

}
