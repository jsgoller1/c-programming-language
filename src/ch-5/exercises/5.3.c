#include "5.3.h"
#include <stdio.h>
#include <stdlib.h>

// append s to the end of t; since K&R talked about
// alloc already(), I'm going to use malloc() here -
// we cannot just append t to the end of s, because
// we don't know if s has enough space for all
// the characters; we could mandate that a third
// array is passed in that does have sufficient capacity,
// but doing this is probably the safest and most concise
// approach.
char* my_strcat(char *s, unsigned int s_len, char *t, unsigned int t_len)
{
  int i = 0;
  char* new = malloc(sizeof(char) * (s_len + t_len));

  for (unsigned int j = 0; j < s_len; j++)
  {
    new[i++] = s[j];
  }

  for (unsigned int k = 0; k < s_len; k++)
  {
    new[i++] = t[k];
  }

  new[i] = '\0';
  return new;
}

int main() {
  char first[] = {"Joshua "}; // len = 7
  char last[] = {"Goller"}; // len = 6
  char* full_name = my_strcat(&first[0], 7, &last[0], 6);
  printf("My name is: %s.\n", full_name);
  return 0;
}
