#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Write a program to concatenate a string at
// the end of another string.
//--
// Since K&R talked about alloc already(),
// I'm going to use malloc() here -
// we cannot just append t to the end of s, because
// we don't know if s has enough space for all
// the characters; we could mandate that a third
// array is passed in that does have sufficient capacity,
// but doing this is probably the safest and most concise
// approach.

static char* my_strcat(const char* const s, const unsigned int s_len,
                       const char* const t, const unsigned int t_len) {
  int i = 0;
  char* new = malloc(sizeof(char) * (s_len + t_len + 1));

  for (unsigned int j = 0; j < s_len; j++) {
    new[i++] = s[j];
  }

  for (unsigned int k = 0; k < t_len; k++) {
    new[i++] = t[k];
  }

  new[i] = '\0';
  return new;
}

int main() {
  char first[] = {"Joshua "};  // len = 7
  char last[] = {"Goller"};    // len = 6
  char* full_name = my_strcat(first, (unsigned int)strlen(first), last,
                              (unsigned int)strlen(last));
  printf("My name is: %s.\n", full_name);
  free(full_name);
  return 0;
}
