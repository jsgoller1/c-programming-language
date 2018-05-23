#include "5.14-17.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

// main(): sort input lines
int main() {
  char *lines[MAXLEN];
  const int nlines = readlines(lines, MAXLEN);
  int numeric = 0;

  myqsort(lines, 0, nlines - 1,
          (int (*)(void *, void *))(numeric ? numcmp : strcmp));
  writelines(lines, nlines);
  freelines(lines, nlines);

  return 0;
}

// swap(): interchange v[i] and v[j] in char** v
void swap_strs(char **v, const int i, const int j) {
  void *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

// myqsort(): sort v[left]...v[right] into increasing order
void myqsort(char **strings, int left, int right, int (*comp)(void *, void *)) {
  int i, last;

  // Quit if empty array
  if (left >= right) {
    return;
  }

  swap_strs(strings, left, (left + right) / 2);

  last = left;
  for (i = left + 1; i <= right; i++) {
    if ((*comp)(strings[i], strings[left]) < 0) {
      swap_strs(strings, ++last, i);
    }
  }

  swap_strs(strings, left, last);

  // recursively sort subarrays
  myqsort(strings, left, last - 1, comp);
  myqsort(strings, last + 1, right, comp);
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
