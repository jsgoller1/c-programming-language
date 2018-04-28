#include "1.21.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

#define MAXLINE 1000  // maximum input line size
#define TAB_CHAR '$'
#define TAB_STOPS 5

/*
Write a program entab that replaces strings of blanks by the minimum number of
tabs and blanks to achieve the same spacing. Use the same tab stops as for
detab(). When either a tab or a single blank would suffice to reach a tab stop,
which should be given preference?
---
We will use a tab for a single blank before a tab stop.
*/

int main() {
  int len;             // current line length
  char line[MAXLINE];  // current input line
  char* stripped;

  printf(
      "Begin typing - tab stops every %d columns; \\t is represented as '$'\n",
      TAB_STOPS);
  while ((len = mygetline(line, MAXLINE)) > 0) {
    stripped = entab(line, len, TAB_STOPS);
    printf("%s\n", stripped);
  }

  return 0;
}

// entab(): given a string of len, return it with all whitespaces of a given
// length replaced by tabs (represented by "$" for clarity)
char* entab(const char* const in_line, const int in_len, const int tab_stop) {
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

  out_line = (char*)malloc((unsigned long)j + 1);
  strncpy(out_line, temp, (unsigned long)j + 1);
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
