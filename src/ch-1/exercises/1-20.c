#include <stdio.h>
#define MAXLINE 1000  // maximum input line size

int getline(char line[], int maxline);
void detab(char string[], int len, int whitespaces);

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

// getline(): read a line into s, return length
int getline(char s[], int lim) {
  int c, i;

  for (i = 0; (i < lim - 1) && ((c = getchar()) != EOF) && (c != '\n'); ++i) {
    s[i] = c;
  }

  if (c == EOF) {
    printf("\nGot EOF, quitting immediately.\n");
    return 0;
  } else if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}
