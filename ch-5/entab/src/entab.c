#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "entab.h"

#define TAB_CHAR '$'

// entab(): given a string of len, return it with all whitespaces of a given
// length replaced by tabs (represented by "$" for clarity)
char* entab(const char* const in_line, const int in_len,
            const int* const tab_stop) {
  char* out_line = {""};
  int i = 0, j = 0, next_stop = 0;
  char temp[MAXLINE] = {0};

  // Copy char by char til we get a whitespace; if so,
  // look_ahead() to see if we can entab - do so if possible,
  // otherwise just copy the char.
  for (j = i = 0; i < in_len; i++) {
    if (in_line[i] == ' ') {
      if ((next_stop = look_ahead(in_line, in_len, i, tab_stop))) {
        temp[j] = TAB_CHAR;
        j++;
        i = next_stop - 1;
      } else {
        temp[j] = in_line[i];
        j++;
      };
    } else {
      temp[j] = in_line[i];
      j++;
    }
  }
  temp[j] = '\0';

  outline = strdup(temp);
  return out_line;
}

/*
look_ahead(): given string in_line of length in_len, determine if
the characters between in_line[offset] and the nearest tab_stop are
all whitespaces. If they are, return the next tab stop's offset; otherwise,
return 0.
*/
int look_ahead(const char* const in_line, const int in_len, int offset,
               const int tab_stop) {
  int next_stop;

  next_stop = offset + (tab_stop - (offset % tab_stop));

  // Quit if we try to read past the buffer
  if (next_stop > in_len) {
    return 0;
  }
  for (; offset < next_stop; offset++) {
    if (in_line[offset] != ' ') {
      return 0;
    }
  }
  return next_stop;
}
