//
//Assignment 3
//mar 15, 2012
//Objective is to  create a pda like program
//Mike morand
#include<stdio.h>
#include<math.h>
#include<libgen.h>
#include <stdlib.h>

struct value//This structure holds the values used throughout.
{
char lastname[40];
char firstname[40];
char address[100];
char postalcode[6];
char phonenumber[10];
};

typedef struct value Code;

int nuke = 0;



int wordcap(char *);

int main (void)
{
    int b = 0;
    int n = 0;
    struct value Code[10];
    char test[20];
    char th[1];
    char line[10];
    char phone[10];
    int i = 0;
    int number;
    printf("***Assignment 3 PECB***\n");//Menu screen
    printf("1. Add new contact\n");
    printf("2. Display current contacts\n");
    printf("3. Search for a contact\n");
    printf("4. Save contacts to file\n");
    printf("5. Load contacts from file\n");
    printf("6. Exit\n");

    number = atoi(gets(line));//checks for user selcetion
    while( n != 1)
    {
        switch(number)
        {
        case 1://Case 1 adding a new contact
        {
            printf("Adding new contact\n");
            printf("First name:\t");
            gets(Code[i].firstname);
            wordcap(Code[i].firstname);
            printf("Last name:\t");
            gets(Code[i].lastname);
            wordcap(Code[i].lastname);
            printf("Address:\t");
            gets(Code[i].address);

            printf("Postal Code:\t");
            gets(Code[i].postalcode);

            printf("Phone:\t");
            gets(Code[i].phonenumber);
            printf("Add another contact?<Y/N>\t");
            i++;
            gets(test);
            nuke++;
            while(*test != 'N')
            {
                if(nuke > 9)//Stops the entrys at 10
                {
                    printf("Maximum entries: 10!\n");
                    printf("Add another contact?<N>\t");
                    gets(test);
                }
                else
                {
                printf("Adding new contact\n");
                printf("First name:\t");
                wordcap(Code[i].firstname);
                gets(Code[i].firstname);
                printf("Last name:\t");

                gets(Code[i].lastname);
                wordcap(Code[i].lastname);
                printf("Address:\t");
                gets(Code[i].address);
                printf("Postal Code:\t");
                gets(Code[i].postalcode);
                printf("Phone:\t");
                gets(Code[i].phonenumber);
                i++;
                nuke++;
                printf("Add another contact?<Y/N>\t");
                gets(test);
                }
            }
            printf("***Assignment 3 PECB***\n");
            printf("1. Add new contact\n");
            printf("2. Display current contacts\n");
            printf("3. Search for a contact\n");
            printf("4. Save contacts to file\n");
            printf("5. Load contacts from file\n");
            printf("6. Exit\n");
            number = atoi(gets(line));
            break;
        }

        case 2://displays all the entrys currnetly in the program.
        {
        int a;
        int array[10];

        for(a = 0; a < nuke; a++)
        {
            char ya[50];
            array[a] = atoi(Code[a].phonenumber);
            printf("Contact #%d\n", a + 1);
            printf("First name:\t%s\n",Code[a].firstname);//prints firstname
            printf("Last name:\t%s\n",Code[a].lastname);//prints lastname
            printf("Address:\t%s\n",Code[a].address);//prints the address


            printf("Postal Code:\t%s\n",Code[a].postalcode);//prints postal code
            printf("Phone:\t%d\n",array[a]);

        }
            printf("***Assignment 3 PECB***\n");
            printf("1. Add new contact\n");
            printf("2. Display current contacts\n");
            printf("3. Search for a contact\n");
            printf("4. Save contacts to file\n");
            printf("5. Load contacts from file\n");
            printf("6. Exit\n");
            number = atoi(gets(line));
            break;
        }
        case 3://User selects a lastname and inputs it in to be searched

        {
            int a;

    char test[40];

    int n = 0;
    printf("What is the contact's lastname?\t");
    gets(test);
    for(a = 0; a < nuke; a++)
    {
            if(strcmp(test, Code[a].lastname) == 0)//returns 0 if same
            {
                n++;
            }
    }
    if(n > 0)
    {
            printf("Found %d Record(s)\n", n);
    }
    else
    {
        printf("Record not found\n");
    }
    int g = 1;
    for(a = 0; a < nuke; a++)
    {
        if(strcmp(test, Code[a].lastname) == 0)//outputs results (if any)
        {
            printf("Contact #%d\n", g);
            printf("First name:\t%s\n",Code[a].firstname);
            printf("Last name:\t%s\n",Code[a].lastname);
            printf("Address:\t%s\n",Code[a].address);
            printf("Postal Code:\t%s\n",Code[a].postalcode);
            printf("Phone:\t%d\n",Code[a].phonenumber);
            g++;
        }

    }
            printf("***Assignment 3 PECB***\n");
            printf("1. Add new contact\n");
            printf("2. Display current contacts\n");
            printf("3. Search for a contact\n");
            printf("4. Save contacts to file\n");
            printf("5. Load contacts from file\n");
            printf("6. Exit\n");
            number = atoi(gets(line));
            break;
        }

        case 4://outputs the information to the file: record.dat
        {
             FILE *output;
            int a;
            if((output = fopen("record.dat", "w")) == NULL)
            {
                printf("error!");
            }
            else
            {

            for(a = 0; a < nuke; a++)
            {

                fprintf(output, "%s\n", Code[a].firstname);
                fprintf(output, "%s\n", Code[a].lastname);//saves the records.
                fprintf(output, "%s\n", Code[a].address);
                fprintf(output, "%s\n", Code[a].postalcode);
                fprintf(output, "%d\n", Code[a].phonenumber);
            }

        }
    fclose(output);
            printf("***Assignment 3 PECB***\n");
            printf("1. Add new contact\n");
            printf("2. Display current contacts\n");
            printf("3. Search for a contact\n");
            printf("4. Save contacts to file\n");
            printf("5. Load contacts from file\n");
            printf("6. Exit\n");
            number = atoi(gets(line));
            break;
        }

        case 5://retrives the file from record .dat
        {
         FILE *input;
        int a = 0;

        if((input = fopen("record.dat", "r")) == NULL)
        {
		printf("Error!");
        }
        else
        {

			while(!feof(input))
			{
				fscanf(input, "%s", Code[a].firstname);
                fscanf(input, "%s", Code[a].lastname);//scans the inputs for the struct
                fscanf(input, "%s", Code[a].address);
                fscanf(input, "%s", Code[a].postalcode);
                fscanf(input, "%s", Code[a].phonenumber);
				a++;
			}
	}
    fclose(input);
        printf("***Assignment 3 PECB***\n");
        printf("1. Add new contact\n");
        printf("2. Display current contacts\n");
        printf("3. Search for a contact\n");
        printf("4. Save contacts to file\n");
        printf("5. Load contacts from file\n");
        printf("6. Exit\n");
        number = atoi(gets(line));
        break;
        }

        case 6:
        {
            printf("Save contacts to file before exiting?<Y/N>\t");
            gets(th);
            if(*th == 'Y')//Saves the file if Y is selected
            {
                 FILE *output;
            int a;
            if((output = fopen("record.dat", "w")) == NULL)
            {
                printf("error!");
            }
            else
            {

            for(a = 0; a < nuke; a++)
            {

                fprintf(output, "%s\n", Code[a].firstname);
                fprintf(output, "%s\n", Code[a].lastname);
                fprintf(output, "%s\n", Code[a].address);
                fprintf(output, "%s\n", Code[a].postalcode);
                fprintf(output, "%d\n", Code[a].phonenumber);
            }

        }
    fclose(output);
            }
            n = 1;
            return(0);
            break;
        }

        default://For invaild selections to reselect
        {
            printf("Invalid Selection");
            printf("***Assignment 3 PECB***\n");
            printf("1. Add new contact\n");
            printf("2. Display current contacts\n");
            printf("3. Search for a contact\n");
            printf("4. Save contacts to file\n");
            printf("5. Load contacts from file\n");
            printf("6. Exit\n");
            number = atoi(gets(line));
            break;
        }
    }
    }

}

/*wordcap: Allows the program to captialize all needed words
Input: inputs a point which is declared as a struct
Output: the captialized word
*/
int wordcap(char *string)
{

char c;
    int i = 0;
    while(i == 0)
    {
        c = string[i];
        string[i] = toupper(c);
        i++;
    }

return 0;
}




