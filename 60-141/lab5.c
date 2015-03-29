#include <stdio.h>
#include <string.h>
#define MAX_WORDS 20

struct WordStruct
{
    char Word[51];
    int length;
}WordList[MAX_WORDS];
//************

typedef struct WordStruct wordStruct;

void BubbleSort(struct WordStruct[], int);
void Print(struct WordStruct[], int);
void SaveWords(char *, struct WordStruct[], int);

//1. define the  following structure





int main(void)
{
	
    //2. Define the array
    char inputString[] = "the cat in the hat jumped over the lazy fox done";
    //**************
    char delims[] = " ";
    char *word;
    int numWords = 0;
	
    // 3. use strtok to extract words

    word = strtok(inputString, delims);  // get the first token
    // for all tokens, add the word to the word list, unless it is done
    while(strcmp(word, "done") != 0)
    {
        strcpy(WordList[numWords].Word, word);
		WordList[numWords].length = strlen(word);
        //copy current word  and length of it into WordList +> strcpy
        word = strtok(NULL, delims);
        //extract next word => strtok
        //count number of words
        numWords++;
    }
	
    //*****************
    numWords--;
    printf("Unsorted:\n");
    Print(WordList, numWords);
    printf("\n");
    //**********
	
    //5. Sort the words
    BubbleSort(WordList, numWords);
    //********

	
    //6. print the words (again, this time in sorted order)
    printf("Sorted:\n");
    Print(WordList, numWords);
    printf("\n");
	
    //7. save the words to a text file
    char filename[] = "wlist.txt";
    SaveWords(filename, WordList, numWords);
    //*************************
    return 0;
}

/*Sorts a list of WordStructs
Input: A list of WordStructs, and the number of words in the list
Output:  NONE
*/
void BubbleSort(struct WordStruct words[], int numWords)
{
    //sort words
    int b, a;
	struct WordStruct temp;
	for(a = 0; a < numWords * numWords; a++)
	{
    	for(b = 0; b < numWords; b++)
        	{
                	if(strcmp(words[b].Word, words[b + 1].Word) > 0)
                	{
                   	 	temp = words[b];
                   	 	words[b] = words[b + 1];
                    	words[b + 1] = temp;
                	}
  	     	}
    }//strcmp function
}

/*Prints a lists of WordStructs
Input: A list of WordStructs, and the number of words in the list
Output: NONE
*/

void Print(struct WordStruct words[], int numWords)
{
    int a;
    for(a = 0; a < numWords; a++)
    {
        printf("%s ", words[a].Word);
        printf("%d ", words[a].length);
		printf("\n");
    }
    //print the content of the array
}

/* Saves a list of WordStructs to a file with the specified filename
Input: The filename, a list of word Structs and the number of words in the list
Output: None
*/

void SaveWords(char *filename, struct WordStruct words[], int numWords)
{
     int a;
    FILE *Output;
    Output = fopen("wlist.txt", "w");
    if(Output == NULL)
    {
        printf("error.");
		return;
    }
    /*int main ()
{
  FILE * pFile;
  pFile=fopen("myfile.txt","r");
  if (pFile==NULL) perror ("Error opening file");
  else {
    fputc ('x',pFile);
    if (ferror (pFile))
      printf ("Error Writing to myfile.txt\n");
    fclose (pFile);
  }
  return 0;
}*///Maybe good
    for(a = 0; a < numWords; a++)
    {
        fprintf(Output, "%s  %d\n", words[a].Word, words[a].length);
    }


    fclose(Output);
}
