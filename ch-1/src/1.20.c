#include "1.20.h"
#include <stdio.h>
#include "common.h"

// Write a function that replaces tabs with the correct number of whitespaces
// (or any other character).

// ALWAYS USE CURLY BRACES, YOU IDIOT

int main() {
  int len, i;          // current line length, and string index
  char line[MAXLINE];  // current input line

  while ((len = getline(line, MAXLINE)) > 0) {
    detab(line, len, 4);
    printf("%s\n", line);
  }
  return 0;
}

// detab(): given a string of len, return it with all tabs replaced by
// whitespaces-long sets of whitespace (using "." instead of whitespace for
// clarity.)
void detab(char string[], int len, int whitespaces) {
  char copy[MAXLINE];
  int i, j, k;
  k = 0;

  for (i = 0; i < len; i++) {
    if (string[i] == '\t') {
      for (j = 0; j < whitespaces; j++) {
        copy[k] = '.';
        k++;
      }
    } else {
      copy[k] = string[i];
      k++;
    }
  }

  for (i = 0; i < k; i++) {
    string[i] = copy[i];
  }

  string[k] = '\0';
}
