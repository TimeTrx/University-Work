#include<stdio.h>
#include<math.h>
#include<ctype.h>
#define NUM_EMPLOYEES 3
int num = 0;
struct employee
{
	char firstname[40];
	char lastname[40];
	int id[40];
};

typedef struct employee Employee;

void SaveEmployeeRecords(Employee employee[], char *filename);
void LoadEmployeeRecords(Employee employee[], char *filename);

void toUppercase(char *);

int main (void)
{
	Employee employeeList[NUM_EMPLOYEES];
	int i;


	//read the employee data from afile
	LoadEmployeeRecords(employeeList, "employee.dat");
	// convert the first and last names to uppercase
	for(i = 0; i < NUM_EMPLOYEES; i++)
	{
		toUppercase(employeeList[i].firstname);
		toUppercase(employeeList[i].lastname);
	}

	//write the employee data to a file
	SaveEmployeeRecords(employeeList, "employee.dat");

	return 0;

}
/*toUppercase: Takes a letter and if its not uppercase in makes it uppercase.
Input: The file's first and last name.
Output: Returns the letters capitialized.
*/
void toUppercase(char *string)
{
    char c;
    int i = 0;
    while(i == 0)
    {
        c = string[i];
        string[i] = toupper(c);
        i++;
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
            fprintf(output, "%d\t", (a * 10) + 10);
            fprintf(output, "%s\t", employee[a].firstname);
            fprintf(output, "%s\n", employee[a].lastname);
        }

    }
    fclose(output);
}
/*LoadEmployeeRecord: Asks the user to input 3 records.
Input: File inputs last name and first name and id
Output: Returns the last and first names with id
*/
void LoadEmployeeRecords(Employee employee[], char *filename)
{
    FILE *input;
	char a[20];
	char b[20];
	char c[20];
	int num = 0;
    if((input = fopen(filename, "r")) == NULL)
    {
		printf("Error!");
    }
	else
	{
			fscanf(input, "%s%s%s", a, b, c);
			while(!feof(input))
			{
				fscanf(input, "%d", employee[num].id);
            	fscanf(input, "%s", employee[num].firstname);
            	fscanf(input, "%s", employee[num].lastname);
             	num++;
			}
	}
fclose(input);
}
