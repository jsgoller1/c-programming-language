#include "1.20.h"
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

/*
Ex 1.20: Write a program detab() that replaces tabs in the input with the
proper number of blanks to space to the next tab stop. Assume a fixed set of
tab stops, say every n columns. Should n be a variable or a symbolic parameter?
---
I am not sure what "symbolic parameter" means here, but a "tab stop" means
the following: suppose that you declare every 10 columns to be a tab stop.
Then entering 5 characters and pressing tab causes columns 1 through 5 to be
populated with keystroke characters, and columns 6 through 10 to be populated
with whitespaces. Entering another 9 characters and pressing tab populates
columns 11 through 19 with characters and column 20 with a whitespace.
*/

/*
typedef struct str {
  char* data;
  int len;
} string;
*/

int main() {
  // int len, i;          // current line length, and string index
  // char line[MAXLINE];  // current input line

  /*
    while ((len = mygetline(line, MAXLINE)) > 0) {
      detab(line, len, 4);
      printf("%s\n", line);
    }
  */

  detab("this\thas\ttwo", 12, 5);
  return 0;
}

// detab():
void detab(char line[], const int len, const int tab_stop) {
  int i, j;
  char new[MAXLINE];
  for (j = i = 0; i < len; i++) {
    if (line[i] != '\t') {
      new[j] = line[i];
      j++;
    } else {
      while (j % tab_stop) {
        // printf("Filling in tab...\n");
        new[j] = '.';
        j++;
      }
    }
  }
  new[j] = '\0';
  printf("%s\n", new);
}

/*
// stringify(): create a null-terminated string of len characters in line
string* stringify(char line[], int len) {
  string* str = (string*)malloc(sizeof(string));
}
*/
