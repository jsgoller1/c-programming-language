#include "1.21.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

#define MAXLINE 1000  // maximum input line size
//#define TAB_CHAR '$'

/*
Write a program entab that replaces strings of blanks by the minimum number of
tabs and blanks to achieve the same spacing. Use the same tab stops as for
detab(). When either a tab or a single blank would suffice to reach a tab stop,
which should be given preference?
*/

int main() {
  int len;             // current line length
  char line[MAXLINE];  // current input line

  while ((len = mygetline(line, MAXLINE)) > 0) {
    entab(line, len, 5);
    printf("%s\n", line);
  }

  return 0;
}

// entab(): given a string of len, return it with all whitespaces of a given
// length replaced by tabs (represented by "$" for clarity)
char* entab(const char* const in_line, const int in_len, const int tab_stop) {
  char* out_line = {""};
  int i, j, none;
  char temp[MAXLINE];
  none = tab_stop;  // remove this

  for (j = i = 0; i < in_len; i++) {
    if (in_line[i] == ' ') {
      printf("Test between %d and %d + (i mod tabstop) (%d).\n", i);
      temp[j] = in_line[i];
      j++;
    } else {
      temp[j] = in_line[i];
      j++;
    }
  }
  temp[j] = '\0';

  out_line = (char*)malloc((unsigned long)j + 1);
  strncpy(out_line, temp, (unsigned long)j + 1);
  return out_line;
}

/*
look_ahead(): given string in_line of length in_len, determine if
the characters between in_line[offset] and the nearest tab_stop are
all whitespaces.

If they are, return 1; otherwise, return 0. Returns -1 if we attempt to read
past the end of the buffer.
*/
int look_ahead(const char* const in_line, const int in_len, int offset,
               const int tab_stop) {
  if (offset + tab_stop >= in_len) {
    // we are attempting to read past the end of the buffer.
    return -1;
  }
  do {
    // printf("Evaluating %c\n", in_line[offset]);
    if (in_line[offset] != ' ') {
      return 0;
    }
    offset++;
  } while (offset % tab_stop);
  return 1;
}
