#include "5.6-sort.h"
#include <stdio.h>
#include <string.h>
#include "5-common.h"

static char *glineptr[MAXLINES];

// main(): sort input lines
int main() {
  int nlines;  // number of input lines read

  if ((nlines = readlines(glineptr, MAXLINES)) >= 0) {
    qsort(glineptr, 0, nlines - 1);
    writelines(glineptr, nlines);
    return 0;
  } else {
    printf("error: input too big to sort.\n");
    return 1;
  }
}

// readlines(): read input lines
int readlines(char *lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = mygetline(line, MAXLEN)) > 1) {
    if (nlines >= maxlines || (p = myalloc(len)) == NULL) {
      return -1;
    } else {
      line[len - 1] = '\0';  // delete the newline
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  }
  return nlines;
}

// writelines(): write output lines
void writelines(char *lineptr[], int nlines) {
  int i;

  for (i = 0; i < nlines; i++) {
    printf("%s\n", lineptr[i]);
  }
}

void qsort(char *lineptr[], int left, int right) {}
