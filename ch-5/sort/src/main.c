#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "sort.h"
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
    myqsort(substrings, 0, count - 1, &flags, (int (*)(void *, void *))numcmp);

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

  // Write out and clean up
  writelines(lines, nlines);
  freelines(lines, nlines);
  return 0;
}

/*
 int main() {
  int count;
  char unsplit[] = "joshua 55 12 667 224 90";
  char* split_strings[MAXLEN] = {0};
  char joined_string[MAXLEN] = {0};

  count = split(unsplit, 7, ' ', split_strings);
  for (int i = 0; i < count; i++) {
    printf("%s\n", split_strings[i]);
  }

  join(split_strings, count, " ", joined_string);
  strcpy(unsplit + 7, joined_string);

  printf("%s\n", unsplit);

  freelines(split_strings, count);
  return 0;
}
*/
