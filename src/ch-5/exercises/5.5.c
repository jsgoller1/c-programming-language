#include "5.5.h"
#include <stdio.h>

// Write versions of the library functions strcpy(), strncat(), and strncmp(),
// which operate on at most the first n characters of their arguments.
int strncpy(char *s, char *t, unsigned int len)
{

  return 0;
}

char* strncat(char *s, char *t, unsigned int len)
{
  char* new;

  return new;
}

int strncmp(char *s, char *t, unsigned int len)
{
  return 0;
}


int main() {
  printf("Joshua and Goller: %d\n", strend("Joshua", 6, "Goller", 6));
  printf("Joshua and shua: %d\n", strend("Joshua", 6, "shua", 4));
  printf("Joshua and empty string: %d\n", strend("Joshua", 6, "", 0));
  printf("empty string and Joshua: %d\n", strend("", 0, "Joshua", 6));
  printf("two empty strings: %d\n", strend("", 0, "", 0));
  return 0;
}
