/* 
 * Example that demonstrates what different operations do.
 */

// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
// #include <sys/select.h>
// #include <termios.h>
// #include <stdio.h>
// 
// struct termios orig_termios;
// 
// void reset_terminal_mode()
// {
//   tcsetattr(0, TCSANOW, &orig_termios);
// }
// 
// void set_conio_terminal_mode()
// {
//   struct termios new_termios;
//   
//   /* take two copies - one for now, one for later */
//   tcgetattr(0, &orig_termios);
//   memcpy(&new_termios, &orig_termios, sizeof(new_termios));
//   
//   /* register cleanup handler, and set the new terminal mode */
//   atexit(reset_terminal_mode);
//   cfmakeraw(&new_termios);
//   tcsetattr(0, TCSANOW, &new_termios);
// }
// 
// int kbhit()
// {
//   struct timeval tv = { 0L, 0L };
//   fd_set fds;
//   FD_ZERO(&fds);
//   FD_SET(0, &fds);
//   return select(1, &fds, NULL, NULL, &tv);
// }
// 
// int getch()
// {
//   int r;
//   unsigned char c;
//   if ((r = read(0, &c, sizeof(c))) < 0) {
//     return r;
//   } else {
//     return c;
//   }
// }
// 
// int main(int argc, char *argv[])
// {
//   set_conio_terminal_mode();
//   
//   char character = '@';
//   
//   printf("\n\n\tThe character is %c", character);
//   
//   while (!kbhit()) {
//     /* do some work */
//     
//     character = getch(); 
//     
//     printf("\n\n\tThe character is %c", character);
//   }
//   
// 
//   
//   while (!kbhit()) {
//     /* do some work */
//   }
//   
//   (void)getch(); /* consume the character */
//   
//   printf("\n\n");
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  fd_set rfds;
  struct timeval tv;
  int retval, len;
  char buff[255] = {0};
  
  /* Watch stdin (fd 0) to see when it has input. */
  FD_ZERO(&rfds);
  FD_SET(0, &rfds);
  
  /* Wait up to five seconds. */
  tv.tv_sec = 5;
  tv.tv_usec = 0;
  
  retval = select(1, &rfds, NULL, NULL, &tv);
  
  if (retval == -1){
    perror("select()");
    exit(EXIT_FAILURE);
  }
  else if (retval){
    /* FD_ISSET(0, &rfds) is true so input is available now. */
    
    /* Read data from stdin using fgets. */
    fgets(buff, sizeof(buff), stdin);
    
    /* Remove trailing newline character from the input buffer if needed. */
    len = strlen(buff) - 1;
    if (buff[len] == '\n')
      buff[len] = '\0';
    
    printf("'%s' was read from stdin.\n", buff);
  }
  else
    printf("No data within five seconds.\n");            
  
  exit(EXIT_SUCCESS);
}