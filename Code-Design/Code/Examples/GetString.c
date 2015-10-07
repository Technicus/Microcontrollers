// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // function declerations
// void readString(void);
// 
// // function definitions
// void readString(){
//   
//   
//   fd_set rfds;
//   struct timeval tv;
//   int retval, len;
//   char buff[255] = {0};
//   
//   /* Watch stdin (fd 0) to see when it has input. */
//   FD_ZERO(&rfds);
//   FD_SET(0, &rfds);
//   
//   retval = select(1, &rfds, NULL, NULL, &tv);
//   
//   if (retval == -1){
//     perror("select()");
//     exit(EXIT_FAILURE);
//   }
//   else {
//     /* FD_ISSET(0, &rfds) is true so input is available now. */
//     
//     /* Read data from stdin using fgets. */
//     
//     fgets(buff, sizeof(buff), stdin);
//     
//     /* Remove trailing newline character from the input buffer if needed. */
//     len = strlen(buff) - 1;
//     if (buff[len] == '\n')
//       buff[len] = '\0';
//     
//     printf("\n\n\t'%s' was read from stdin.\n", buff);
//   }
// }
// int main(int argc, char *argv[])
// {
//   printf("\n\nType a string:");
//   
//   readString();
//      
//   exit(EXIT_SUCCESS);
// }

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
  
  /* Remove trailing newline character from the input buffer if needed. */
  //len = len - 1;
//   if (line[read - 1] == '\n'){
//     line[read - 1] = '\0';
//   }
  if (line[read - 1] == '\n'){
    line[read - 1] = '\0';
  }
  
  printf ("\n\tRead %zd chars from stdin, allocated %zd bytes for line: \"%s\"\n\n", read, len, line);
  
//   while ((read = getline(&line, &len, stdin)) != -1) {
//     
//     if (read > 0)
//       printf ("\n  read %zd chars from stdin, allocated %zd bytes for line : %s\n", read, len, line);
//     
//     printf ("Enter string below [ctrl + d] to quit\n");
//   }
//   
  free (line);  /* free memory allocated by getline */
  
  //return(line);
}

int main (int argc, char *argv[]) {
  
  readString();
  
  return 0;
}