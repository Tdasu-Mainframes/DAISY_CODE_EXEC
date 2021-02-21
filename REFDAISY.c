#include <stdio.h>

void byref( char* string)
{
  FILE *stream;
  /* The following call opens a text file for reading */
  stream = fopen("//dd:STRING", "r");
  fgets(string,80,stream);
  fclose(stream);
}

int main( void )
{
  char origString[30]  = "JAKE";
  printf ( "%s\n", origString );
  byref(origString);
  printf ( "%s\n", origString );
  return 0;
}
