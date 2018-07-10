#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "entab.h"

#define WHITESPACE '.'

// detab(): replace tabs in in_line with with
// whitespace up to next tab_stop-th column
char* detab(const char* const in_line, const int in_len, const int tab_stop) {
  char* out_line;
  int i, j;
  char temp[MAXLINE];

  // go through in_line until a tab is found and convert
  // to appropriate number of whitespace up to tab stop
  for (j = i = 0; i < in_len; i++) {
    if (in_line[i] != '\t') {
      temp[j] = in_line[i];
      j++;
    } else {
      while (j % tab_stop) {
        temp[j] = WHITESPACE;
        j++;
      }
    }
  }
  temp[j] = '\0';

  out_line = (char*)malloc((unsigned long)j + 1);
  strncpy(out_line, temp, (unsigned long)j + 1);
  return out_line;
}
