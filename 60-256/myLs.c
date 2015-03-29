#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void recursive(char* , char*);

int main(int argc, char* argv[1])
{


	if(argc != 2)
	{
		printf("Usage: %s [filename missing]\n", argv[0]);
		return 1;
	}
	
	recursive(".", argv[1]);
  	return 0;
}

void recursive(char* path, char* pattern)
{
	char buffer[200];
	
	char* see;
	int len;
	len = strlen(pattern);
	DIR *dp;
	struct dirent *dirp;//This is broken, fixed with allocating memory to avoid seg fault 
	
	
	dp = opendir(path);
	
	dirp = (struct dirent *)malloc(sizeof(dp));//Allocated memory to avoid seg fault, get a warning for incompatable type  
	
	while ( (dirp = readdir(dp)) != NULL) //For some reason dirp = readdir(dp) is returning null
	{
		if(strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0)	
		{
			continue;
		}
		if(strcmp(pattern, dirp->d_name) == 0)
		{
			printf("%s/%s\n", path, dirp->d_name);
		}
		
 		if((dirp->d_type & DT_DIR) == DT_DIR)
		{
			
			sprintf (buffer, "%s/%s", path, dirp->d_name);
			recursive(buffer, pattern);
		}   
		
	}
	
 	closedir(dp);
 
}


