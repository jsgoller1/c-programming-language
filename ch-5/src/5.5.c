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

char *my_strncpy(char *s, char *t, unsigned int len) {
  unsigned int i;
  for (i = 0; i < len && s[i] != '\0'; i++) {
    t[i] = s[i];
  }
  for (; i < len; i++) {
    t[i] = '\0';
  }

  return t;
}

/*
The  strcat()  function appends the src string to the dest string,
overwriting the terminating null byte ('\0') at the end of dest, and then
adds a terminating null byte.

The strncat() function is similar, except that: 1) it will use at most n bytes
from src; and 2) src does not need to be null-terminated if it contains n or
more bytes. As with strcat(), the resulting string in dest is always
null-terminated. If src contains n or more bytes, strncat() writes n+1 bytes to
dest(n from src plus the terminating null byte). Therefore, the size of dest
must be at least strlen(dest)+n+1.
*/

char *my_strncat(char *s, char *t, unsigned int len) {
  unsigned int i, j;
  t = (void *)t;

  // advance to the end of the string,
  for (i = 0; s[i] != '\0'; i++) {
    // no-op
  }

  // copy up to len bytes of t into s
  for (j = 0; j < len; j++, i++) {
    s[i] = t[j];
  }
  s[i] = '\0';

  return s;
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

  // JosDEFGHIJKLMNOPQRSTUVWXYZ
  printf("%s\n", my_strncpy("Joshua", first, 3));
  // JoshuaGHIJKLMNOPQRSTUVWXYZ
  printf("%s\n", my_strncpy("Joshua", first, 6));
  // Joshua + nulls
  printf("%s\n\n", my_strncpy("Joshua", first, 11));

  // JoshuaGoller
  printf("%s\n", my_strncat(first, "Goller", 6));
  // JoshuaGollerGOL
  printf("%s\n", my_strncat(first, "GOLLER", 3));
  // JoshuaGollerGOL
  printf("%s\n\n", my_strncat(first, "RELLOG", 0));

  // What exactly does "greater than" / "less than" mean in the strncmp
  // description? Basically, that when a[i] != b[i], a[i] - b[i] is
  // returned; if one of the strings terminates before the other, the first
  // character after the termination is returned in the non-terminating string.
  printf("%d == %d\n", strncmp("Joshua", "Josh", 6),
         my_strncmp("Joshua", "Josh", 6));
  printf("%d == %d\n", strncmp("Joshua", "Joshua", 6),
         my_strncmp("Joshua", "Joshua", 6));
  printf("%d == %d\n", strncmp("", "", 6), my_strncmp("", "", 6));

  return 0;
}
