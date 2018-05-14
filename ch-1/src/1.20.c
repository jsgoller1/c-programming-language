#include "1.20.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "tests.h"

/*
* Ex 1.20: Write a program detab() that replaces tabs in the input with the
* proper number of blanks to space to the next tab stop. Assume a fixed set of
* tab stops, say every n columns. Should n be a variable or a symbolic
* parameter?
* ---
* I am not sure what "symbolic parameter" means here, but a "tab stop" means
* the following: suppose that you declare every 10 columns to be a tab stop.
* Then entering 5 characters and pressing tab causes columns 1 through 5 to be
* populated with keystroke characters, and columns 6 through 10 to be populated
* with whitespaces. Entering another 9 characters and pressing tab populates
* columns 11 through 19 with characters and column 20 with a whitespace.
*/

#define WHITESPACE '.'

static void test(const char* const input, const char* const expected,
                 const int tab_stop, const char* const message) {
  const int len = (int)strlen(input);
  const char* const actual = detab(input, len, tab_stop);
  assert_string_eq(actual, expected, "detab", message);
}

int main() {
#ifdef DEBUG
  int len;             // current line length, and string index
  char line[MAXLINE];  // current input line
  char* tabless_line;

  printf("Begin entering text; whitespace will be printed as '.'\n");
  while ((len = mygetline(line, MAXLINE)) > 0) {
    tabless_line = detab(line, len, 5);
    printf("%s", tabless_line);
    free(tabless_line);
  }
#else
  printf("1.20: No unit tests.\n");
#endif
  return 0;
}

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
