#include <stdio.h>

// Ex. 4-1: Write the function strrindex(s,t) , which returns the position of
// the rightmost occurrence of t in s , or -1 if there is none.

static char pattern[] = {"ould"};

// strindex: return the rightmost index of t in s, -1 if not found.
// start at the right and go left until either the beginning of the string
// occurs or a match is found
static int strrindex(const char* const s, const int s_len,
                     const char* const t) {
  int i, j, k;

  for (i = s_len - 1; i > 0; i--) {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
      // noop
    }
    if ((k > 0) && (t[k] == '\0')) {
      return i;
    }
  }
  return -1;
}

// Find all lines matching pattern
int main() {
  // 9
  char good1[] = "goodfoodwouldmold";
  printf("%d\n", strrindex(good1, 17, pattern));

  // 11
  char good2[] = "wouldwouldwould";
  printf("%d\n", strrindex(good2, 15, pattern));

  // -1
  char good3[] = "g0000000000000d";
  printf("%d\n", strrindex(good3, 15, pattern));
  return 0;
}
