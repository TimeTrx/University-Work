#include<stdio.h>
#include<math.h>
#define NUM_EMPLOYEES 3
int num = 0;
struct employee
{
	char firstname[40];
	char lastname[40];
	int id;
};

typedef struct employee Employee;

void SaveEmployeeRecords(Employee employee[], char *filename);
void PrintEmployeeRecords(Employee employee[]);
void InputEmployeeRecord(Employee employee[], int);


void main ()
{
	Employee e1[3];
	int i;

    InputEmployeeRecord(e1, i);
    PrintEmployeeRecords(e1);
	SaveEmployeeRecords(e1, "employee.dat");


}
/*InputEmployeeRecord: Asks the user to input 3 records.
Input: User inputs last name and first name
Output: Records the last and first names as well as id #
*/
void InputEmployeeRecord(Employee employee[], int a)
{
    int b;
    a = 10;
    for (b = 0; b < 3; b++)
    {
        gets(employee[b].firstname);
        gets(employee[b].lastname);
        a = a + 10;
    }
 		
}

/*SaveEmployeeRecord: Writes the records to a file
Input: User inputs last name and first name and id #
Output: Saves the last , first and id to a file
*/
void SaveEmployeeRecords(Employee employee[], char *filename)
{
    FILE *output;
    if((output = fopen(filename, "w")) == NULL)
    {
        printf("error!");
    }
    else
    {
        fprintf(output, "ID  FIRSTNAME   LASTNAME\n");
        int a;
        for(a = 0; a < 3; a++)
        {
            fprintf(output, "%d\t", (a * 10) + 10 );
            fprintf(output, "%s\t", employee[a].firstname);
            fprintf(output, "%s\n", employee[a].lastname);
        }

    }
    fclose(output);
}
/*PrintEmployeeRecord: Prints the records of the user
Input: The lastname, first name and id
Output: Prints the last , first and id to
*/
void PrintEmployeeRecords(Employee employee[])
{
    printf("ID  FIRSTNAME   LASTNAME\n");
    int a;
    for(a = 0; a < 3; a++)
    {
        printf("%d\t", (a * 10) + 10);
        printf("%s\t", employee[a].firstname);
        printf("%s\n", employee[a].lastname);
    }
}
