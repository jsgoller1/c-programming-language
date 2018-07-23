#include <stdio.h>
#include <string.h>

#include "common.h"

/*
Exercise 5-7. Rewrite readlines to store lines in an array supplied by main,
rather than calling alloc to maintain storage. How much faster is the
program?
-----------------------
There is now one less function call, but alloc() is O(c), so the program
will likely not be noticeably faster.
*/

#define MAXLEN 1000               // maximum number of chars in a lines
#define MAXLINES 5000             // maximum number of sortable lines
#define STORAGE_BUFFER_SIZE 5000  // number of bytes for stack buffer

// swap(): interchange v[i] and v[j]
static void swap(char **const v, const int i, const int j) {
  char *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

// qsort(): sort v[left]...v[right] into increasing order
static void qsort(char **const v, const int left, const int right) {
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
static int bufferedreadlines(char **const lineptr_buffer,
                             const int lineptr_buffer_size, char *const lines,
                             const int lines_size) {
  int len, nlines, bufferindex;
  char line[MAXLEN];

  nlines = 0;
  bufferindex = 0;
  while ((len = mygetline(line, MAXLEN)) > 1) {
    if (nlines >= lineptr_buffer_size) {
      printf("Error: No remaining lines for next string.\n");
      return -1;
    } else if ((int)strlen(line) + bufferindex >= lines_size) {
      printf("Error: insufficient storage space for next string.\n");
      return -1;
    } else {
      // Copy line into storage buffer, and capture the address of its first
      // character in the lineptr buffer
      strcpy(lines + bufferindex, line);
      lineptr_buffer[nlines++] = lines + bufferindex;
      bufferindex += len + 1;
    }
  }
  return nlines;
}

// main(): sort input lines
int main() {
  int nlines;  // number of input lines read
  char lines[STORAGE_BUFFER_SIZE];
  char *lineptr_buffer[MAXLINES];

  if ((nlines = bufferedreadlines(lineptr_buffer, MAXLINES, lines,
                                  STORAGE_BUFFER_SIZE)) >= 0) {
    qsort(lineptr_buffer, 0, nlines - 1);
    writelines(lineptr_buffer, nlines);
    return 0;
  } else {
    printf("error: input too big to sort.\n");
    return 1;
  }
}
