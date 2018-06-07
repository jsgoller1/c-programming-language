#include <alloca.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

// dir_strip(): copy up to n bytes from src to dest with all non alphanumeric
// and whitespace removed, and a null terminator. Assumes dest is at least n+1
// bytes long.
void dir_strip(char *const dest, const char *const src, const int n) {
  int i, j;
  for (i = 0, j = 0; i < n; i++) {
    if (isalnum((char)src[i]) || src[i] == ' ') {
      dest[j++] = src[i];
    }
  }

  if (n > 0) {
    dest[j] = '\0';
  }
}

// foldcmp(): compare s1 and s2, ignoring case
int foldcmp(const char *const s1, const char *const s2) {
  int s1_len = (int)strlen(s1);
  char *s1_low = (char *)alloca(s1_len + 1);

  int s2_len = (int)strlen(s2);
  char *s2_low = (char *)alloca(s2_len + 1);

  int i;
  for (i = 0; i < s1_len; i++) {
    s1_low[i] = (char)tolower(s1[i]);
  }
  s1_low[i] = '\0';

  for (i = 0; i < s2_len; i++) {
    s2_low[i] = (char)tolower(s2[i]);
  }
  s2_low[i] = '\0';

  return strcmp(s1_low, s2_low);
}

// numcmp(): compare s1 and s2 numerically
int numcmp(const char *const s1, const char *const s2) {
  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);

  if (v1 < v2) {
    return -1;
  } else if (v1 > v2) {
    return 1;
  } else {
    return 0;
  }
}
