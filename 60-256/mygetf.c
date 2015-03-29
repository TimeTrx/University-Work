#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> 

#ifndef _IOEOF
#define _IOEOF  0020
#endif

#ifndef _IOERR
#define _IOERR  0040
#endif
int num = 0;
int myfgetc(FILE *fp);

int main(int argc, char *argv[]){ 
        FILE * fp;
        int cnt=0, ch; 
        
        if(argc != 2){
                fprintf(stderr, "%s requires 1 arguments.\n", argv[0]); 
                exit(1); 
                } 
        
        if((fp = fopen(argv[1], "r")) == NULL){
                perror("File problem");
                exit(1); 
                } 

        while((ch=myfgetc(fp)) != EOF){
                //putchar(ch);                          
                cnt++;
                }
        if(feof(fp)) 
                printf("The file size is %d\n", cnt);
        else
                perror("Reading not completed");
}
        

int myfgetc(FILE *fp)
{
int c;
c = getc (fp);
return c;
}
