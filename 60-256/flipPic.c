//Michael Morand
//
//Assignment3
//oct 17 2012
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	
	int i;
	FILE * fp;
	FILE * cp;
	FILE * input;
  	long lSize, cSize, pSition;
	char * buffer = malloc(50);

	if(argc != 3)//will check for the two arguments and close if not given
	{
		printf("Usage: %s [filename missing] and/or [filename missing]\n", argv[0]);
		return 1;
	}
	
	
	cp = fopen (argv[1], "rb" );//opens the first arguements input file
	fgets(buffer, 50, cp);
	fgets(buffer, 50, cp);
	
	sscanf(buffer, "%ld %ld", &cSize, &lSize);//get the size of the binary file
	fgets(buffer, 50, cp); //gets the next line
	free(buffer);//frees the values
	buffer = malloc(cSize+1);// gets the size of the total columns
	fp = fopen( argv[2] , "wb" );//sets the write to file
	pSition = ftell(cp);//tells the position of the file pointer
	
	fprintf(fp, "P5\n");//prints the type of file at the beginning
	fprintf(fp, "%ld %ld\n255\n", cSize, lSize);//prints the size byte x byte
	for(i = lSize-1; i >= 0; i--)//starts at the end of the input and writes to the beginning of the output file
	{
	fread(buffer, cSize, 1, cp);//reads the line in input
	pSition = fseek(cp, cSize * i + pSition, SEEK_SET);//sets the positon
	
	fwrite(buffer, cSize, 1, fp);//outputs the bytes to the output file
	
	}
	free(buffer);//frees and closes the allocated memory values
	fclose(fp);
	fclose(cp);
  	return 0;
}


