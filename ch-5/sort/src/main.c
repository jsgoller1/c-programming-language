#include <stdio.h>
#include <string.h>

#include "common.h"
#include "sort.h"
/*
// main(): sort input lines depending on flags
int main(int argc, char **argv) {
  input_flags flags = {false, false, false, false};
  if (parse_args(argc, argv, &flags) == -1) {
    return -1;
  }
  char *lines[MAXLEN];
  const int nlines = readlines(lines, MAXLEN);

  // do primary sort
  if (flags.numeric) {
    myqsort(lines, 0, nlines - 1, &flags, (int (*)(void *, void *))numcmp);
  } else if (flags.fold) {
    myqsort(lines, 0, nlines - 1, &flags, (int (*)(void *, void *))foldcmp);
  } else {
    myqsort(lines, 0, nlines - 1, &flags, (int (*)(void *, void *))strcmp);
  }

  // Once index order is assured, go through each string and sort the subfields
  char *substrings[MAXLEN];
  for (int i = 0; i < argc; i++) {
    int count = 0;
    char sorted_str[MAXLEN];
    char *string = lines[i];

    // convert each string into an array of substrings.
    count = split(string, &substrings, offset);
    if (count == -1) {
      freelines(lines, nlines);
      return -1;
    }

    // call qsort on the substrings
    myqsort(substrings, 0, count, flags);

    // convert substrings back to a single string
    if (join(substrings, count, ' ', sorted_str) == -1) {
      freelines(substrings, count);
      freelines(lines, nlines);
      return -1;
    }
    freelines(substrings, count);

    // overwrite unsorted portion of old string with sorted version
    strcpy(string + offset, sorted_substr);
    free(sorted_substr);
  }

  // Write out and clean up
  writelines(lines, nlines);
  freelines(lines, nlines);
  return 0;
}
*/
int main() {
  char unsplit[] = "this string should be split into substrings";
  char* split_strings[MAXLEN] = {0};
  int count;

  char* unjoined[] = {"this",   "bunch", "of",    "substrings",
                      "should", "be",    "joined"};
  char joined_string[MAXLEN] = {0};

  count = split(unsplit, 0, ' ', split_strings);
  for (int i = 0; i < count; i++) {
    printf("%s\n", split_strings[i]);
  }

  join(unjoined, 7, " ", joined_string);
  printf("%s\n", joined_string);

  freelines(split_strings, count);
  return 0;
}
