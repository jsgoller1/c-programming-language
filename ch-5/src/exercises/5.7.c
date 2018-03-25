#include "5.7.h"
#include <stdio.h>
#include <string.h>
#include "5-common.h"

/*
Exercise 5-7. Rewrite readlines to store lines in an array supplied by main,
rather than calling alloc to maintain storage. How much faster is the
program?

There is now one less function call, but alloc() is O(c), so the program
will likely not be noticeably faster.
*/

static char *glineptr[MAXLINES];

// main(): sort input lines
int main() {
  int nlines;  // number of input lines read
  char storagebuffer[STORAGE_BUFFER_SIZE];

  if ((nlines = bufferedreadlines(glineptr, MAXLINES, storagebuffer,
                                  STORAGE_BUFFER_SIZE)) >= 0) {
    qsort(glineptr, 0, nlines - 1);
    writelines(glineptr, nlines);
    return 0;
  } else {
    printf("error: input too big to sort.\n");
    return 1;
  }
}

// swap(): interchange v[i] and v[j]
void swap(char *v[], int i, int j) {
  char *temp;

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

// bufferedreadlines(): read input lines into a supplied string buffer
int bufferedreadlines(char *lineptr[], int maxlines, char storagebuffer[],
                      int buffersize) {
  int len, nlines, bufferindex;
  char line[MAXLEN];

  nlines = 0;
  bufferindex = 0;
  while ((len = mygetline(line, MAXLEN)) > 1) {
    if (nlines >= maxlines) {
      printf("Error: No remaining lines for next string.\n");
      return -1;
    } else if ((int)strlen(line) + bufferindex >= buffersize) {
      printf("Error: insufficient storage space for next string.\n");
      return -1;
    } else {
      // Copy line into storage buffer, and capture the address of its first
      // character in the lineptr buffer
      line[len - 1] = '\0';  // delete the newline
      strcpy(&(storagebuffer[bufferindex]), line);
      lineptr[nlines++] = &storagebuffer[bufferindex];
      bufferindex += len;
    }
  }
  return nlines;
}
