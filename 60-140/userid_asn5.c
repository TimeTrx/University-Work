#include <stdio.h>
#include <math.h>

//Michael Morand Section Number: 60-140 Date: Nov 15, 11 Lab: 51
int binaryc(int);
int complement1(int);
void printnum(int,int,int,int,int,int,int,int,int,int,int,int, int, int, int);

int main(void)
{
    int numpostotal = 0;
    int numnegtotal = 0;
    int ans;
    int opmule;
    int pomule;
    int mule;
    int totalmule;
    int numneg;
    int n;
    int num;
    char input;
    int numpos;
    int totalsum;
    int seepos;
    int seeneg;
    int numberneg;
    int seetotal;
    int num2;
    printf("Any more numbers to be converted?(Y/N)\n");
    printf("Please type Y to continue and N if you want to stop after next number\n");

    scanf("%c", &input);//This starts the loop to check if you want to start

    while (input != 'N') //This checks to stop the loop of numbers
    {
        scanf("%d",&num);//This is where you input the numbers
        fflush(stdin);

        if (num >= 0)//This checks for a positive
        {
            numpos =+ num;
            ans = binaryc(num);
            printf("Number:\tBinary:\n");
            printf("%d\t%08d\n",num, ans);//This outputs the results
            numpostotal = numpostotal +1;

        }
        if (num < 0)//This checks for a negative
        {
            numneg = num;
            numberneg =+ num;
            ans = complement1(num);
            printf("Number:\tBinary:\n");
            printf("%d\t%08d\n",numneg, ans);//This outputs the results
            numnegtotal = numnegtotal + 1;

        }
        printf("Any more numbers to be converted?(Y/N)\n");
        printf("Please type Y to continue and N if you want to stop after next number\n");

        scanf("%c", &input);//Asks and checks for the loop to continue
        fflush(stdin);
    }

    printf(" \n");
    num = numpostotal;
    opmule = binaryc(num);
    num = numnegtotal;//These are all the counters for the final print module
    pomule = binaryc(num);
    mule = numpostotal + numnegtotal;
    num = mule;
    totalmule = binaryc(num);
    num = numpos;
    seepos = binaryc(num);
    num = numberneg;
    seeneg = complement1(num);
    num2 = numpos + numberneg;
    num = num2;
    seetotal = binaryc(num);
    printnum( numpostotal, numnegtotal, numpos, totalsum, seepos, seeneg, numberneg, seetotal, num2, ans, opmule, pomule, mule, totalmule, numneg);
    return 0;
}

int complement1(int num)
{
    int thor;
    int test;
    int your;
    thor = abs(num);
    test = binaryc(thor);//This converts a negative number to a positive number to be sent to another module to convert
    your = 11111111 - test;//This then makes it a negative binary
    return your;
}

int binaryc(int num)
{
    int decimalnum;
    int num_d = num;
    int num_b = 0;
    int power2 = 0;//This converts a decimal number to a binary
    int quotient;
    int remainder;
    do
    {
        decimalnum = num_d;
        quotient = num_d / 2;
        remainder = num_d % 2;
        num_b = num_b + (remainder * pow(10, power2));
        num_d = quotient;
        power2 = power2 + 1;
    }
    while(quotient != 0);
    return num_b;
}

void printnum(int numpostotal, int numnegtotal, int numpos, int totalsum, int seepos, int seeneg, int numberneg, int seetotal,int num2,int ans, int opmule, int pomule, int mule, int totalmule,int numneg)
{

    printf("Number of postive numbers processed = %d and %08d in binary\n", numpostotal, opmule);
    printf("Number of negative numbers processed = %d and %08d in binary\n", numnegtotal, pomule);
    printf("Number of all numbers processed = %d and %08d in binary\n",mule ,totalmule);//This prints all the final results
    printf("Sum of postive numbers processed = %d and %08d in binary\n", numpos, seepos);
    printf("Sum of negative numbers processed = %d and %08d in binary\n", numneg, seeneg);
    printf("Sum of all numbers processed = %d and %08d in binary\n",num2, seetotal);

}
