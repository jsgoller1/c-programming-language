#include "5.14-17.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

// main(): sort input lines
int main() {
  char *lines[MAXLEN];
  const int nlines = readlines(lines, MAXLEN);

  myqsort(lines, 0, nlines - 1);
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

// qsort(): sort v[left]...v[right] into increasing order
void myqsort(char **strings, int left, int right) {
  int i, last;

  if (left >= right) {
    return;
  }
  swap_strs(strings, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++) {
    if (strcmp(strings[i], strings[left]) < 0) {
      swap_strs(strings, ++last, i);
    }
  }
  swap_strs(strings, left, last);
  myqsort(strings, left, last - 1);
  myqsort(strings, last + 1, right);
}
