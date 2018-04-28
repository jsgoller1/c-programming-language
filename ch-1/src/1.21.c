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
  int i, j;
  char temp[MAXLINE] = {0};

  for (j = i = 0; i < in_len; i++) {
    if (in_line[i] == ' ') {
      if (look_ahead(in_line, in_len, i, tab_stop)) {
        // blanks up to tab
        temp[j] = TAB_CHAR;
        j++;
        // advance to next stop minus one as loop will increment
        i += tab_stop - (i % tab_stop) - 1;
        // printf("Replaced spaces with tabchar: %s.\n", temp);
      } else {
        temp[j] = in_line[i];
        j++;
        // printf("Lookahead failed, copied %c to temp.\n", in_line[i]);
      };
    } else {
      temp[j] = in_line[i];
      j++;
      // printf("No whitespace, copied %c to temp.\n", in_line[i]);
    }
  }
  temp[j] = '\0';

  // printf("j: %d, final temp: %s\n", j, temp);
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
  int next_stop;

  // 0 presents a pathological edge case in determining the next tab stop
  next_stop =
      (offset == 0) ? tab_stop : offset + (tab_stop - (offset % tab_stop));

  if (next_stop > in_len) {
    // we are attempting to read past the end of the buffer.
    return 0;
  }
  for (; offset < next_stop; offset++) {
    if (in_line[offset] != ' ') {
      return 0;
    }
  }
  return 1;
}
