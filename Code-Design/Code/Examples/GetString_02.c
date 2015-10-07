#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function declerations
  void readString_00(void);
  void readString_01(void);
  void checkInput(char *stringIn[]);
    
// function definitions
void readString_00(){
  
  char *line = NULL;  /* forces getline to allocate with malloc */
  size_t len = 0;     /* ignored when line = NULL */
  ssize_t read;
  
  printf ("\n\tEnter string below\n\t\tString > ");
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

void readString_01(){
  char stringIn[] = "00000000\n";
  char array[8] = {0,0,0,0,0,0,0,0};
  int ret;
  char c;
  
  printf ("\n\tEnter string: \t");
  fgets(stringIn,9,stdin);
  
  //sscanf(line, "%[01]%c", array, &c) == 2 and c == '\n'
  
  //printf("ret: %d, array=%s, c=%d\n", ret, array, c);
  printf("\tThe string is: \t%s",stringIn);
  
  int i;
  for(i = 0; i < 8; i++) {
    ret = sscanf(stringIn, "%d", &i);
    //printf("\n\tchar %d:\t\t%c", i, stringIn[i]);
    printf("\n\tchar %d:\t\t%d", i, ret);
  }
  //checkInput(stringIn);
}

void checkInput(char *stringIn[]) {
//   int array[] = { 1, 4, 77, 2, 9, 123, -1 };
//   int x;
//   
  //   for( x = 0; stringIn[ x ] != -1; x++ )
//     ...do something...
  int i;
  for(i = 0; i < 9; i++) {
    printf("char %d: %s\n", i, stringIn[i]);
  }
}

int main (int argc, char *argv[]) {
  
  //readString_00();
  readString_01();
  printf ("\n\n");
  
  return 0;
}