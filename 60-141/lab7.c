//Michael Morand
//
//lab8

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// DOCUMENT!!!!!!
struct point
{
	int x;
	int y;
	char label[21];
	struct point *ptrNext;		// self referential pointer
};

int isEmptyList(struct point *ptrF);
void PrintList(struct point *ptrF);
void ResetList(struct point *ptrF, struct point *ptrL);
void AddToBeginning(struct point *ptrF, struct point *ptrL);
void AddToEnd(struct point *ptrF, struct point *ptrL);
void InputRecord(struct point *ptrNew); // used by Add to interactively get the values from the user



struct point *ptrFirst = NULL;
struct point *ptrLast = NULL;

void main()
{
	struct point *ptrF;	
	struct point *ptrL;	
	struct point *ptrNew;	
	int nput;
	printf("1. Add a point at the END of the list.\n2. Add a point at the BEGINNING of the list.\n3. Is the list empty?\n4. Erase all points from the list.(reset).\n5. Display the list.\n6. Save the list to a sequential file (reset/replace file contents)\n7. Read the list back from a sequential file.(reset/replace current memory content)\n0. Exit\n");// do the menu
	scanf("%d", &nput);

	while(nput != 0)//This will allow the list to continue until 0 is entered
	{

		if(nput == 1)//if 1 is entered add to end
		{
			

			AddToEnd(ptrFirst,ptrLast);
		}

		if(nput == 2)
		{
			AddToBeginning(ptrFirst, ptrLast);
		}

		if(nput == 3)
		{
			isEmptyList(ptrFirst);
		}

		if(nput == 4)
		{
			ResetList(ptrFirst, ptrLast);
		}

		if(nput == 5)
		{
			PrintList(ptrFirst);
		}

		printf("1. Add a point at the END of the list.\n2. Add a point at the BEGINNING of the list.\n3. Is the list empty?\n4. Erase all points from the list(reset).\n5. Display the list.\n6. Save the list to a sequential file (reset/replace file contents)\n7. Read the list back from a sequential file 		   (reset/replace current memory content)\n0. Exit");
		scanf("%d", &nput);//asks for another selection
	}

    free (ptrNew);
	free (ptrF);
	free (ptrL);
	free (ptrFirst);
	free (ptrLast);
}
/*isEmptylist: checks if the list is emptry
Input: The pointer required to check the list.
Output: Returns if the list is empty or not.
*/
int isEmptyList(struct point *ptrF)
{
	int n = 0;
	if(ptrF == NULL)
	{
		n++;
	}

	if(n == 1)
	{
		printf("Yes the list is empty");
	}

	else
	{
		printf("No the list is not empty");
	}

}

/*PrintList: Prints the list of points
Input: The pointer required for the list.
Output: Outputs the list.
*/
void PrintList(struct point *ptrF)
{
	struct point *ptrNew;
	int a = 0;
	struct point *ptrtemp=ptrF;
	while(ptrtemp!=NULL)
	{
       // printf("Label: %s\nX = %d\nY = %d",ptrNext.label[a],ptrNext.x,ptrNext.y);
		
		printf("%s",ptrNew -> label);
		printf("%d",ptrNew -> x);
		printf("%d",ptrNew -> y); 
		ptrtemp=ptrtemp->ptrNext;
		a++;
	}

	
}

/*ResetList: Resets the list of points.
Input: The pointer required for the list.
Output: Outputs the the reset list.
*/
void ResetList(struct point *ptrF, struct point *ptrL)
{
	struct point *ptr;
	 if(ptrL == NULL)
    {
        return;
    }
    else
    {
        if(ptrF == NULL)
        {
            ptr->ptrNext = NULL;
            ptrF = NULL;
            ptrL = ptrF;
        }

        else
        {
            ptr->ptrNext;
            ptrF = NULL;
        }

    }
}

/*AddToBeginning: Adds a point to the beginning of a list.
Input: The pointer required for the list.
Output: The list with a pointer added to the beginning.
*/
void AddToBeginning(struct point *ptrF, struct point *ptrL)
{
	struct point *ptrNext;
	struct point *ptr;
	struct point *ptrNew;
	InputRecord(ptrNew);
    if(ptrL == NULL)
    {
        return;
    }
    else
    {
        if(ptrF == NULL)
        {
            ptr->ptrNext = NULL;
            ptrF = ptr;
            ptrL = ptr;
        }

        else
        {
            ptr->ptrNext;
            ptrF = ptr;
        }

    }
}

/*AddToEnd: Adds a point to the end of a list.
Input: The pointer required for the list.
Output: The list with a pointer added to the end.
*/
void AddToEnd(struct point *ptrF, struct point *ptrL)
{
	struct point *ptr;
	struct point *ptrNext;
	struct point *ptrNew;
	InputRecord(ptrNew);
    if(ptrF == NULL)
    {
        return;
    }
    else
    {
        if(ptrL == NULL)
        {
            ptr->ptrNext = NULL;
            ptrL = ptr;
            ptrF = ptr;
        }

        else
        {
            ptr->ptrNext;
            ptrL = ptr;
        }
	}
}

/*InputRecord: input a point into thre records.
Input: The pointer required for the list.
Output: Inputs a record to the list.
*/
void InputRecord(struct point *ptrNew)
{
	
   
	
    scanf("%s",ptrNew -> label);
	scanf("%d",&ptrNew -> x);
	scanf("%d",&ptrNew -> y); 
 
}
