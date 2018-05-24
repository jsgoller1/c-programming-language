#include "sort.h"

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
    if (flags->directory) {
      // TODO: Conditionally process to dir style here if flags dictate
    }

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

// swap(): interchange v[i] and v[j] in char** v
void swap_strs(char **v, const int i, const int j) {
  void *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
