#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function declerations
void readString(void);

// function definitions
void readString(){
  
  char *line = NULL;  /* forces getline to allocate with malloc */
  size_t len = 0;     /* ignored when line = NULL */
  ssize_t read;
  
  printf ("\n\tEnter string below [ctrl + d] to quit\n\t\tString > ");
  read = getline(&line, &len, stdin);

  /* Check to see if number of characters grater than 8. */
  if ((read - 1) != 8){
    printf ("\n\tError: not 8 bit binary");
    return;
  }
  
  /* Remove trailing newline character from the input buffer if needed. */
  if (line[read - 1] == '\n'){
    line[read - 1] = '\0';
  }
  
  printf ("\n\tRead %zd chars from stdin, allocated %zd bytes for line: \"%s\"", read-1, len, line);
  
  free (line);  /* free memory allocated by getline */
}

int main (int argc, char *argv[]) {
  
  readString();
  
  printf ("\n\n");
  
  return 0;
}