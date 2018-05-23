#include <stdio.h>
#include "sort-tests.h"
#include "sort.h"

// main(): sort input lines
int main(int argc, char **argv) {
#ifdef TEST
  test_parse_args();
#else
  input_flags flags = {false, false, false, false};
  if (parse_args(argc, argv, &flags) == -1) {
    return -1;
  }
  char *lines[MAXLENGTH];
  const int nlines = readlines(lines, MAXLEN);
  int numeric = 0;

  myqsort(lines, 0, nlines - 1,
          (int (*)(void *, void *))(numeric ? numcmp : strcmp));
  writelines(lines, nlines);
  freelines(lines, nlines);
#endif
  return 0;
}
