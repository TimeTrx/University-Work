//
//Assignment 4
//Mar 26, 2012
//Objective is to  create a pda like program
//Mike Morand
#include<stdio.h>
#include<math.h>
#include<libgen.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct value//This structure holds the values used throughout.
{
char lastname[40];
char firstname[40];
char address[100];
char postalcode[8];
char phonenumber[10];
struct value *Next;
};

struct value *create()
{
	return (struct value *) (malloc(sizeof(struct value)));
}

struct value *First = NULL;
struct value *Last = NULL;
struct value *Temp = NULL;
int must = 0;
int nuke = 0;

int postal(char *);
int numfix(char *);
int wordcap(char *);

int main (void)
{
    int b = 0;
    int n;
    
    char test[20];
    char th[1];
    char line[10];
    char phone[10];
	char *post[10];
	char post1[10];
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
				struct value *New = create();
				if(First == NULL && Last == NULL)
				{
            		printf("Adding new contact\n");
            		printf("First name:\t");
            		gets(New->firstname);
					
            		wordcap(New->firstname);
            		printf("Last name:\t");
            		gets(New->lastname);
            		wordcap(New->lastname);
            		printf("Address:\t");
            		gets(New->address);
		
            		printf("Postal Code:\t");
            		gets(New->postalcode);
				
            		printf("Phone:\t");
            		gets(New->phonenumber);
            		printf("Add another contact?<Y/N>\t");
            		i++;
            		First = New;
					Last = New;
            		gets(test);
            		nuke++;
					must = 0;
				}
				else
				{
	
            		printf("Adding new contact\n");
            		printf("First name:\t");
            		gets(New->firstname);
					
           			wordcap(New->firstname);
            		printf("Last name:\t");
           			gets(New->lastname);
         	  		wordcap(New->lastname);
         	   		printf("Address:\t");
         	   		gets(New->address);
			
            		printf("Postal Code:\t");
            		gets(New->postalcode);
				
            		printf("Phone:\t");
            		gets(New->phonenumber);
            		printf("Add another contact?<Y/N>\t");
            		i++;
					Last->Next = New;
					Last = New;
					
            		gets(test);
            		nuke++;
					must = 0;
				}	
			
            	while(*test == 'Y')
            	{
					struct value *New = create();
            	    printf("Adding new contact\n");
            	    printf("First name:\t");
            	    
            		gets(New->firstname);
					wordcap(New->firstname);
            	    printf("Last name:\t");
	
            	    gets(New->lastname);
              	  	wordcap(New->lastname);
                	printf("Address:\t");
                	gets(New->address);
                	printf("Postal Code:\t");
                	gets(New->postalcode);
                		printf("Phone:\t");
                	gets(New->phonenumber);
                	i++;
                	Last->Next = New;
					Last = New;
					Last->Next = NULL;
                	nuke++;
                	printf("Add another contact?<Y/N>\t");
                	gets(test);
                	must = 0;
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
        int a = 0;
        
		if(must = 1)
		{
			Temp = First;
        while(Temp->Next != NULL)
        {

            printf("Test");
            printf("Contact #%d\n", a + 1);
            printf("New name:\t%s\n",Temp->firstname);//prints firstname
            printf("Last name:\t%s\n",Temp->lastname);//prints lastname
            printf("Address:\t%s\n",Temp->address);//prints the address
			printf("Postal:\t");//prints postal code
			numfix(Temp->postalcode);
		
            
			printf("\n");
            printf("Phone:\t");
			postal(Temp->phonenumber);
            Temp = Temp->Next;
            a++;
        }
        }
        else
        {
        	Temp = First;
        	while(Temp != NULL)
        		{

            
            	printf("Contact #%d\n", a + 1);
           		 printf("New name:\t%s\n",Temp->firstname);//prints firstname
           	 printf("Last name:\t%s\n",Temp->lastname);//prints lastname
            printf("Address:\t%s\n",Temp->address);//prints the address
			printf("Postal:\t");//prints postal code
			numfix(Temp->postalcode);
		
            
			printf("\n");
            printf("Phone:\t");
			postal(Temp->phonenumber);
            Temp = Temp->Next;
            a++;
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
		
		
         
        case 3://User selects a lastname and inputs it in to be searched

        {
            int a;
			int flag = 0;
			char ty[40];

			int n = 0;
			printf("What is the contact's lastname?\t");
			gets(ty);
			
			Temp = First;
			while(Temp != NULL)
			{
				
				if(strcmp(ty, Temp->lastname) == 0)//returns 0 if same
				{
					n++;
					
				}
				Temp = Temp->Next; 
			}
			if(n > 0)
			{
				printf("Found %d Record(s)\n", n);
			}
			else
			{
				printf("Record not found\n");
				flag = 1;
			}
			int g = 1;
			
			
			Temp = First;
			while(Temp != NULL)
			{
				if(strcmp(ty, Temp->lastname) == 0)//outputs results (if any)
				{
					printf("Contact #%d\n", g);
					
					printf("New name:\t%s\n",Temp->firstname);
					printf("Last name:\t%s\n",Temp->lastname);
					printf("Address:\t%s\n",Temp->address);
					printf("Postal Code:\t%s\n",Temp->postalcode);
					printf("Phone:\t%s\n",Temp->phonenumber);
					g++;
					
				}
				Temp = Temp->Next;
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
			Temp = First;
            while(Temp != NULL)
			{
                fprintf(output, "%s\n", Temp->firstname);
                fprintf(output, "%s\n", Temp->lastname);//saves the records.
                fprintf(output, "%s\n", Temp->address);
                fprintf(output, "%s\n", Temp->postalcode);
                fprintf(output, "%s\n", Temp->phonenumber);
				Temp = Temp->Next;
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
		
		nuke = 0;
        if((input = fopen("record.dat", "r")) == NULL)
        {
		printf("Error!");
        }
		

        else
        {
			struct value *New = create();
			fscanf(input, "%s", New->firstname);
            fscanf(input, "%s", New->lastname);//scans the inputs for the struct
            fscanf(input, "%s", New->address);
            fscanf(input, "%s", New->postalcode);
            fscanf(input, "%s", New->phonenumber);
			First = New;			
			Last = First;
			nuke++;
			must = 1;
			while(!feof(input))
			{
				struct value *New = create();
				fscanf(input, "%s", New->firstname);
                fscanf(input, "%s", New->lastname);//scans the inputs for the struct
                fscanf(input, "%s", New->address);
                fscanf(input, "%s", New->postalcode);
                fscanf(input, "%s", New->phonenumber);
				Last->Next = New;
				Last = New;
				
				must = 1;
				nuke++;
			}
			Last->Next = NULL;
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
			Temp = First;
            while(Temp != NULL)
			{
                fprintf(output, "%s\n", Temp->firstname);
                fprintf(output, "%s\n", Temp->lastname);//saves the records.
                fprintf(output, "%s\n", Temp->address);
                fprintf(output, "%s\n", Temp->postalcode);
                fprintf(output, "%s\n", Temp->phonenumber);
				Temp = Temp->Next;
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
            	
        	}
    	
        
        n = 1;
        return 0;
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

/*numfix: Prints the correct postal code style
Input: Takes the unsorted postal code as pointer, to be sorted
Output: Prints the correct postal code style
*/
int numfix(char *post)
{	
	int a;
	printf("%c%c%c-%c%c%c",post[0],post[1],post[2],post[3],post[4],post[5]);
	
	return 0;
}

/*postal: Prints the correct phone number and style
Input: Takes the sorted phone number as a pointer
Output: Prints the correct phone number and style
*/
int postal(char *post)
{
	int a;
	printf("(%c%c%c) %c%c%c-%c%c%c%c\n",post[0],post[1],post[2],post[3],post[4],post[5],post[6],post[7],post[8],post[9]);
	
	return 0;
}
