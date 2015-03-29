//
//Assignment 2
//Feb 25, 2012
//Objective is to solve a random physics question.
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int sort(char *S, int);

int main(void)
{
    int num;
    char first[10];
    char line[10];
    int final = 1;
    num = atoi(gets(line));

    char sentence[100];

    while(num--)
    {
       gets(sentence);
       sort(sentence, final);
       final++;
    }
    return 0;
}

int sort (char *sentence, int final)
{
    //fprintf(stderr, "testing");
    char *pch;

    int a = 0;
    int b = 0;
    int c = 0;
    int n = 0;

    char print[100];
    double array[5];
    double answer;
    pch = strtok (sentence," :;,");
    while (pch != NULL)
    {
        int flagm = 0;
        int flagK = 0;
        int flagM = 0;
        if(*pch=='I' && *(pch+1)=='=')
        {
            size_t count1=0;
            char temp1[20];
            while(*(pch+count1)!='A')
            {
                count1++;
                if(*(pch+count1) == 'm')
                {
                    flagm = 1;
                }
                if(*(pch+count1) == 'K')
                {
                    flagK = 1;
                }
                if(*(pch+count1) == 'M')
                {
                    flagM = 1;
                }
            }


            array[n] = atof(strncpy(temp1,pch+2,count1));
            if(flagm == 1)
                {
                    array[n] = (array[n]/1000);
                }
                if(flagM == 1)
                {
                    array[n] = (array[n]*1000000);

                }
                if(flagK == 1)
                {
                    array[n] = (array[n]*1000);
                }
            a++;
            n++;
            if(b == 1)
            {
                answer = (array[0] * array[1]);
                printf("Problem #%d\n", final);
                printf("P=%.2f",answer);
                if(flagK == 1)
                {
                    array[n] = (array[n]/1000);
                    printf("K");
                }
                if(flagM == 1)
                {
                    array[n] = (array[n]/1000000);
                    printf("M");
                }
                if(flagm == 1)
                {
                    array[n] = (array[n]*1000);
                    printf("m");
                }
                printf("W\n");
            }
            if(c == 1)
            {
                answer = (array[1]/array[0]);
                printf("Problem #%d\n", final);
                printf("U=%.2f", answer);
                if(flagK == 1)
                {
                    array[n] = (array[n]/1000);
                    printf("K");
                }
                if(flagM == 1)
                {
                    array[n] = (array[n]/1000000);
                    printf("M");
                }
                if(flagm == 1)
                {
                    array[n] = (array[n]*1000);
                    printf("m");
                }
                printf("V\n");
            }

        }
        //if(ptr1 != NULL)


       else if(*pch=='U' & *(pch+1)=='=')
        {
            size_t count=0;
            char temp[20];
            while(*(pch+count)!='V')
            {
                count++;
                if(*(pch+count) == 'm')
                {
                    flagm = 1;
                }
                if(*(pch+count) == 'K')
                {
                    flagK = 1;
                }
                if(*(pch+count) == 'M')
                {
                    flagM = 1;
                }
            }



            array[n] = atof(strncpy(temp,pch+2,count));
			if(flagm == 1)
                {
                    array[n] = (array[n]/1000);
                }
                if(flagM == 1)
                {
                    array[n] = (array[n]*1000000);

                }
                if(flagK == 1)
                {
                    array[n] = (array[n]*1000);
                }
            b++;
            n++;
            if(a == 1)
            {
                answer = (array[1] * array[0]);
                printf("Problem #%d\n", final);
                printf("P=%.2f", answer);
				if(flagK == 1)
                {
                    array[n] = (array[n]/1000);
                    printf("K");
                }
                if(flagM == 1)
                {
                    array[n] = (array[n]/1000000);
                    printf("M");
                }
                if(flagm == 1)
                {
                    array[n] = (array[n]*1000);
                    printf("m");
                }
				printf("W\n");
            }
            if(c == 1)
            {
                answer = (array[0]/array[1]);
                printf("Problem #%d\n", final);
                printf("I=%.2f", answer);
				if(flagK == 1)
                {
                    array[n] = (array[n]/1000);
                    printf("K");
                }
                if(flagM == 1)
                {
                    array[n] = (array[n]/1000000);
                    printf("M");
                }
                if(flagm == 1)
                {
                    array[n] = (array[n]*1000);
                    printf("m");
                }
				printf("A\n");
            }

        }

       else if(*pch=='P' & *(pch+1)=='=')
        {
            size_t count=0;
            char temp2[20];
            while(*(pch+count)!='W')
            {
                count++;
                if(*(pch+count) == 'm')
                {
                    flagm = 1;
                }
                if(*(pch+count) == 'K')
                {
                    flagK = 1;
                }
                if(*(pch+count) == 'M')
                {
                    flagM = 1;
                }
            }



            array[n] = atof(strncpy(temp2,pch+2,count));
			
			if(flagm == 1)
                {
                    array[n] = (array[n]/1000);
                }
                if(flagM == 1)
                {
                    array[n] = (array[n]*1000000);

                }
                if(flagK == 1)
                {
                    array[n] = (array[n]*1000);
                }
			
            c++;
            n++;

            if(b == 1)
            {
                answer = (array[0]/array[1]);
                printf("Problem #%d\n", final);
                printf("I=%.2f", answer);
				if(flagK == 1)
                {
                    array[n] = (array[n]/1000);
                    printf("K");
                }
                if(flagM == 1)
                {
                    array[n] = (array[n]/1000000);
                    printf("M");
                }
                if(flagm == 1)
                {
                    array[n] = (array[n]*1000);
                    printf("m");
                }
				printf("A\n");

            }

            if(a == 1)
            {
				
                answer = (array[1]/array[0]);
                printf("Problem #%d\n", final);
                printf("U=%.2f", answer);
				
				printf("V\n");
            }

        }



        pch = strtok(NULL, " ,;");



    }
    /*
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
    }*/
    return 0;
}
