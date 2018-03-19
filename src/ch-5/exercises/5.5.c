#include "5.5.h"
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

// Write versions of the library functions strcpy(), strncat(), and strncmp(),
// which operate on at most the first n characters of their arguments;
// it is the caller's responsibility to ensure the space is large enough.

/*
Copy at most n characters of s to t; If there is no null byte among the first n
bytes of src, the string placed in dest will not be null-terminated. If the
length of src is less than n, strncpy() writes additional null bytes to dest to
ensure that a total of n bytes are written (I looked at the man page for part
of this).
*/

int my_strncpy(char *s, char *t, unsigned int len) {
  unsigned int i;
  for (i = 0; i < len && s[i] != '\0'; i++) {
    t[i] = s[i];
  }
  for (; i < len; i++) {
    t[i] = '\0';
  }

  return 0;
}

char *my_strncat(char *s, char *t, unsigned int len) {
  char *new;
  s = t = new = NULL;
  len = 0;

  return new;
}

int my_strncmp(char *s, char *t, unsigned int len) {
  unsigned int i;
  for (i = 0; s[i] == t[i] && i < len; i++) {
    // no-op
  }

  if (s[i] != t[i]) {
    return s[i] - t[i];
  }

  return 0;
}

int main() {
  char first[MAX_LEN] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  my_strncpy("Joshua", first, 3);
  printf("%s\n", first);

  my_strncpy("Joshua", first, 6);
  printf("%s\n", first);

  my_strncpy("Joshua", first, 11);
  printf("%s\n", first);

  // What exactly does "greater than" / "less than" mean in the strncmp
  // description? Basically, that when a[i] != b[i], a[i] - b[i] is returned;
  // if one of the strings terminates before the other, the first character
  // after the termination is returned in the non-terminating string.
  printf("%d == %d\n", strncmp("Joshua", "Josh", 6),
         my_strncmp("Joshua", "Josh", 6));
  printf("%d == %d\n", strncmp("Joshua", "Joshua", 6),
         my_strncmp("Joshua", "Joshua", 6));
  printf("%d == %d\n", strncmp("", "", 6), my_strncmp("", "", 6));

  return 0;
}
