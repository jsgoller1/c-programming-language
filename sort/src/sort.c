#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

// swap(): interchange v[i] and v[j] in char** v
void swap_strs(char **v, const int i, const int j) {
  void *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

// myqsort(): quicksort v into increasing order
void myqsort(char **strings, int left, int right, input_flags *flags,
             int (*comp)(void *, void *)) {
  int i, last;

  // Quit if empty array
  if (left >= right) {
    return;
  }

  swap_strs(strings, left, (left + right) / 2);

  last = left;
  for (i = left + 1; i <= right; i++) {
    if ((*comp)(strings[i], strings[left]) < 0 && !(flags->reverse)) {
      swap_strs(strings, ++last, i);
    } else if ((*comp)(strings[i], strings[left]) > 0 && flags->reverse) {
      swap_strs(strings, ++last, i);
    }
  }

  swap_strs(strings, left, last);

  // recursively sort subarrays
  myqsort(strings, left, last - 1, flags, comp);
  myqsort(strings, last + 1, right, flags, comp);
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
