//Michael Morand
//
//Sept 28, 12
//Assignment 1
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void recursive(char* , char*);

int main(int argc, char* argv[1])
{


	if(argc != 2)//Checks if the input is correct 
	{
		printf("Usage: %s [filename missing]\n", argv[0]);//output why it was stopped and stops
		return 1;
	}
	
	recursive(".", argv[1]);//passes the values to start recursive loop
  	return 0;
}
//Recursive function calls the function recursively and feeds it hile looking for pattern
void recursive(char* path, char* pattern)
{
	char buffer[200];
	
	char* see;
	int len;
	len = strlen(pattern);
	DIR *dp;
	struct dirent *dirp;//Struct used to hold 
	
	dp = opendir(path);
	

	
	while ( (dirp = readdir(dp)) != NULL)//as long as there is a directory there
	{
		if(strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0)	
		{
			continue;//skips over . and .. because they are directory and will causee infinte lopp
		}
		if(strcmp(pattern, dirp->d_name) == 0)
		{
			printf("%s/%s\n", path, dirp->d_name);//Found the name outputing it
		}
		
 		if((dirp->d_type & DT_DIR) == DT_DIR)
		{
			
			sprintf (buffer, "%s/%s", path, dirp->d_name);
			recursive(buffer, pattern);//did not find anything restarting
		}   
		
	}
	
 	closedir(dp);
 
}


