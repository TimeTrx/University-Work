/* fread example: read an entire file */
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[1]) {
  FILE * fp;
  FILE * cp;
  long lSize;
  char * buffer;
  size_t result;

  fp = fopen ( argv[1], "rb" );
  if (fp==NULL) {fputs ("File error",stderr); exit (1);}

  // obtain file size:
  fseek (fp , 0 , SEEK_END);
  lSize = ftell (fp);
  rewind (fp);

  // allocate memory to contain the whole file:
  buffer = (char*) malloc (sizeof(char)*lSize);
  if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}

  // copy the file into the buffer:
  result = fread (buffer,1,lSize,fp);
  if (result != lSize) {fputs ("Reading error",stderr); exit (3);}

  /* the whole file is now loaded in the memory buffer. */
  cp = fopen ( "output.txt" , "wb" );
  fwrite (buffer , 1 , ftell(fp) , cp);
  fclose (cp);
  // terminate
  fclose (fp);
  free (buffer);
  return 0;
}


