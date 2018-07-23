#include "5.4.h"
#include <stdio.h>

// Ex 5.4: Write a program strend(s, t) that returns 1 if string t is
// found at the end of string s, and 0 otherwise.

int strend(char *s, unsigned int s_len, char *t, unsigned int t_len) {
  // By convention, a null-terminated string is found at the end of any string.
  if (t_len == 0) {
    return 1;
  }

  // The only string at the end of a null string is another null string.
  if (s_len == 0) {
    return (t_len ? 0 : 1);
  }

  // Starting from the end of each string, compare char-by-char; if we reach
  // zero for t_len before or at the same time as s_len, it's at the end of s;
  // otherwise, it isn't.
  unsigned int t_end = t_len - 1;
  unsigned int s_end = s_len - 1;
  while (s[s_end] == t[t_end]) {
    // if we hit the end of s first, t is not at the end of s unless t == s (and
    // thus t_end is also zero)
    if (s_end == 0) {
      return (t_end ? 0 : 1);
    }

    // if we hit t_end first, it is at the end of s.
    if (t_end == 0) {
      return 1;
    }

    t_end--;
    s_end--;
  }

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
