//Michael Morand
/*
Lab Section 53
Kobti
Feb 7, 12
Lab 5
*/
#include<stdio.h>
#include<math.h>
#include<string.h>
void reverse(char []);
void recursivereverse(char [], int);
int parsesentence();
/*Main: Follows the instructions for the lab
Input: The word and sentence inputted into the array
Output: None, but passes arrays and integer values
*/
int main (void)
{
	int b = 0;
	char Buffer1[] = {'t','h','i','s','i','s','a','b','u','f','f','e','r','\0'};
	char Buffer2[] = "this is the second buffer";
	char Buffer3[80];
	char *point;
	int start;
	//scanf("%s", &Buffer3);//warning format %s expects type 'char *' but type 2 has type 'char (*)[80]'
	gets(Buffer3);
	printf("%s\n", Buffer1);//prints thisisabuffer
	printf("%s\n", Buffer2);//prints this is the second buffer
	printf("%s\n", Buffer3);//prints the string from the scanf
	char *pBuffer = Buffer3;

	int a = 0;
	do
	{
		printf("%s", pBuffer);
		a++;
		b = b + 1;
	}while(Buffer3[a] == '\0');
	printf("\n");
	start = strlen(Buffer3);
	reverse(Buffer3);
	recursivereverse(Buffer3, start);
	parsesentence();
	return(0);
}
/*Reverse: Reverses the word inputted from the main
Input: The char array from the main
Output: Prints the flipped character.
*/
void reverse(char array[])
{
	int start;
	char * point;
	int a;
	int b;
	start = strlen(array);
	for(a = start - 1; a >= 0; a--)
	{
		printf("%c", array[a]);

	}
	printf("\n");
	return;
}
/*recursivereverse: this allows a recursive reverse for the char
Input: The char array from the main to be flipped
Output: Prints the flipped char array
*/
void recursivereverse(char array[], int a)
{
    char * point;
	if(array[a-1] == 0)
	{
		printf("%c", array[a]);
		printf("\n");
		return;
	}
	if (array[a] != '\0')
	{

		printf("%c", array[a]);
	}
	a--;
	recursivereverse(array, a);

}
/*parsesentence: Takes a set of charaters to be broken up and sorted in order of letters
Input: The sentence to be sorted
Output: Prints the sentence in alphabetical order
*/
int parsesentence()
{
	int a = 0;
    int b, c;
    //char S[] ="this is a test";
    char S[80];
    gets(S);
    char * pch;
    int sorted;
    //printf ("Splitting string \"%s\" into tokens:\n",str);
    pch = strtok (S," ,.;");
    char * print[80];
    char * hold;
    while (pch != NULL)
    {
        print[a] = pch;
        //printf ("%s\n",pch);
        pch = strtok (NULL, " ,.;");
        a++;


    }
    do
    {
        sorted = 0;
        for(c = 0; c < a - 1; c++)
        {
            if(strcmp(print[c], print[c + 1]) > 0)
            {
                hold = print[c];
                print[c] = print[c + 1];
                print[c + 1] = hold;
                sorted = 1;
            }
        }
    }
    while(sorted == 1);
    for(b = 0; b < a; b++)
    {

        printf ("%s\n",print[b]);
    }

    return 0;
}
