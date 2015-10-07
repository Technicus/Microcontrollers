#include <stdio.h>

int main(void)
{
    char s[] = "010101\n";
    char array[100];
    int ret;
    char c; 
    
    
    //sscanf(line, "%[01]%c", array, &c) == 2 and c == '\n'
   //fgets(s,sizeof(s),stdin);
    
    // Count how many specifiers saved correctly
    ret = sscanf(s, "%[01]%c", array, &c);
    
    //ret = sscanf(s, "%[01]%c", array, (char *) &c);
    printf("ret: %d, array=%s, c=%d\n", ret, array, c);
    return 0;
}

/* run
[guest@localhost c]$ .ansi t.c -o t
[guest@localhost c]$ ./t
ret: 2, array=010101, c=10
[guest@localhost c]$

*/