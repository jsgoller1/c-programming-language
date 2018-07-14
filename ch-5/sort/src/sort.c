#include <alloca.h>
#include <string.h>

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

  char *string_i, *string_left;
  last = left;
  for (i = left + 1; i <= right; i++) {
    if (flags->directory) {
      // If we're doing directory sorting, create temporary stripped
      // versions of the strings and do the comparisons based on that.
      int i_len = (int)strlen(strings[i]);
      string_i = alloca((unsigned int)i_len);
      dir_strip(string_i, strings[i], i_len);

      int left_len = (int)strlen(strings[left]);
      string_left = alloca((unsigned int)left_len);
      dir_strip(string_left, strings[left], left_len);
    } else {
      // Otherwise, do string comparisons as-is.
      string_i = strings[i];
      string_left = strings[left];
    }
    if ((*comp)(string_i, string_left) < 0 && !(flags->reverse)) {
      swap_strs(strings, ++last, i);
    } else if ((*comp)(string_i, string_left) > 0 && flags->reverse) {
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
