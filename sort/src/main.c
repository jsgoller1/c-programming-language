#include <stdio.h>
#include <string.h>
#include "common.h"
#include "sort-tests.h"
#include "sort.h"

/*
 * See README.md for exercise listing.
 */

#ifdef TEST_MESSAGES
// main(): run tests
int main() {
  printf("Launching tests...\n");
  // test_parse_args();
  test_foldcmp();
  printf("5.14 - 5.17: PASS!\n");
  return 0;
}
#else
// main(): sort input lines depending on flags
int main(int argc, char **argv) {
  input_flags flags = {false, false, false, false};
  if (parse_args(argc, argv, &flags) == -1) {
    return -1;
  }
  char *lines[MAXLEN];
  const int nlines = readlines(lines, MAXLEN);

  int (*comparator)(void *, void *);
  if (flags.numeric) {
    comparator = numcmp;
  } else if (flags.fold) {
    comparator = foldcmp;
  } else {
    comparator = strcmp;
  }

  myqsort(lines, 0, nlines - 1, &flags, comparator);
  writelines(lines, nlines);
  freelines(lines, nlines);
  return 0;
}
#endif
