#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "sort.h"
// main(): sort input lines depending on flags
int main(int argc, char **argv) {
  input_flags p_flags = {false, false, false, false, false, {0}};
  input_flags s_flags = {false, false, false, false, false, {0}};

  if (parse_args(argc, argv, &p_flags, &s_flags) == -1) {
    return -1;
  }
  char *lines[MAXLEN];
  const int nlines = readlines(lines, MAXLEN);

  // do primary sort
  if (p_flags.numeric) {
    myqsort(lines, 0, nlines - 1, &p_flags, (int (*)(void *, void *))numcmp);
  } else if (p_flags.fold) {
    myqsort(lines, 0, nlines - 1, &p_flags, (int (*)(void *, void *))foldcmp);
  } else {
    myqsort(lines, 0, nlines - 1, &p_flags, (int (*)(void *, void *))strcmp);
  }

  if (s_flags.in_use) {
    // Once index order is assured, go through each string and sort the
    // subfields
    for (int i = 0; i < nlines; i++) {
      char *substrings[MAXLEN] = {0};
      char *string = lines[i];
      int count = 0;
      int offset = 0;
      char sorted_str[MAXLEN] = {0};

      // == 0 because -1 is an error and we add 1
      if ((offset = (indexof(string, ' ') + 1)) == 0) {
        printf("main() | %s has no spaces.\n", string);
        freelines(lines, nlines);
        return -1;
      }

      // convert each string into an array of substrings.
      count = split(string, offset, ' ', substrings);
      if (count == -1) {
        printf("main() | couldn't break string into substrings.\n");
        freelines(lines, nlines);
        return -1;
      }

      // printf("main() | subsorting in %s ", string);
      /*
      for (int j = 0; j < count; j++) {
        printf("[%s] (%d) | ", substrings[j], j);
      }
      printf("\n");
      */
      // call qsort on the substrings; -2 to not sort the \n

      // do primary sort
      if (s_flags.numeric) {
        myqsort(substrings, 0, count - 1, &s_flags,
                (int (*)(void *, void *))numcmp);
      } else if (s_flags.fold) {
        myqsort(substrings, 0, count - 1, &s_flags,
                (int (*)(void *, void *))foldcmp);
      } else {
        myqsort(substrings, 0, count - 1, &s_flags,
                (int (*)(void *, void *))strcmp);
      }

      /*
      printf("main() | sorted in %s ", string);
      for (int j = 0; j < count; j++) {
        printf("%s | ", substrings[j]);
      }
      */

      // convert substrings back to a single string
      if (join(substrings, count, " ", sorted_str) == -1) {
        freelines(substrings, count);
        freelines(lines, nlines);
        return -1;
      }
      freelines(substrings, count);

      // overwrite unsorted portion of old string with sorted version
      /*
      printf("main() | overwriting %s [%d, %d bytes] with %s (%d bytes)\n",
             string, offset, (int)strlen(string), sorted_str,
             (int)strlen(sorted_str));
      */
      strcpy(string + offset, sorted_str);
    }
  }

  // Write out and clean up
  writelines(lines, nlines);
  freelines(lines, nlines);
  return 0;
}
