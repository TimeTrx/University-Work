
#include<stdio.h>
#include<math.h>
#include<string.h>


int ParseSentence();

int main (void)
{
  ParseSentence();

  return 0;
}
int ParseSentence()
{
   /* char S[] = "this is a sentence";
  int max = 10;
  int count = 0;
  char **words = NULL;

  words = malloc(max);
  // check words for being NULL

  char *tokenPtr = NULL;

  tokenPtr = strtok(S, " ?!,.");

  while(tokenPtr != NULL)
  {
    words[count] = tokenPtr;
    ++count;
    printf("%s", words);
    if (count == max)
      {
	max+=10;

	words = realloc(words, max);
	if (words == NULL)
	  return 0; // out of memory
      }

    tokenPtr = strtok(NULL, " ?!,.");
  }*/

    int a = 0;
    int b, c;
    char str[] ="- This, a sample string.";
    char * pch;
    int sorted;
    printf ("Splitting string \"%s\" into tokens:\n",str);
    pch = strtok (str," ,.-");
    char * print[80];
    char * hold;
    while (pch != NULL)
    {
        print[a] = pch;
        //printf ("%s\n",pch);
        pch = strtok (NULL, " ,.-");
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
                        print[c] = print[c+1];
                        print[c+1] = hold;
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
