#include <stdio.h>
int main()
{
  char name[10];
  printf("Who are you? \n");
  fgets(name,10,stdin);
  printf("Good to meet you, %s.\n",name);
  return(0);
}