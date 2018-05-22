#include "5.14-5.17.h"
#include <stdio.h>
#include <string.h>
#include "common.h"

// main(): sort input lines
int main() {
  const char *lines[MAXLINES];
  const int nlines = readlines(lines, MAXLINES);

  qsort(lines, 0, nlines - 1);
  writelines(lines, nlines);
  freelines(lines, nlines);

  return 0;
}

// swap(): interchange v[i] and v[j] in char** v
void swap(const void **v, const int i, const int j) {
  void *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

// qsort(): sort v[left]...v[right] into increasing order
void qsort(char *v[], int left, int right) {
  int i, last;

  if (left >= right) {
    return;
  }
  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++) {
    if (strcmp(v[i], v[left]) < 0) {
      swap(v, ++last, i);
    }
  }
  swap(v, left, last);
  qsort(v, left, last - 1);
  qsort(v, last + 1, right);
}
