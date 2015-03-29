#include<stdio.h>
#include<math.h>

int main (void)//If any line causes an error document it
{
//What is the function call of each line?
int a = 7;
int *aPtr;
aPtr = &a;
printf("%p\n", &a);//Printing the address of a
printf("%p\n", aPtr);//Printing the address of a
printf("%p\n", &aPtr);//Print of the address of aPtr
printf("%d\n", a);//Print the value of a
printf("%d\n", *aPtr);//Print the value of a
printf("%p\n", *&aPtr);//Prints the address of a
printf("%p\n", &*aPtr);//Prints the adress of a
printf("%d\n", *&a);//Prints the value of a
/*This list of code is an Error. error: invalid type argument of unary ‘*’ (have ‘int’) 
printf("%d\n", &*a); 
*/
return(0);
}


