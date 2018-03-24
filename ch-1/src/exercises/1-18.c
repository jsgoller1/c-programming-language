#include <stdio.h>
#define MAXLINE 1000  // maximum input line size

int getline(char line[], int maxline);

// Write a program to remove trailing blanks and tabs from each line of input,
// and to delete blank lines Trailing characters can be found by starting at the
// end of the string and working backwards; doing this and removing any \t or '
// ' we find until we hit a character solves the first part. Empty lines occur
// if someone just hits \n; getline returns 1, so main can just not print it.

// ALWAYS USE CURLY BRACES, YOU IDIOT

int main() {
  int len, i;          // current line length, and string index
  char line[MAXLINE];  // current input line

  while ((len = getline(line, MAXLINE)) > 0) {
    for (i = len - 2; (line[i] == ' ') || (line[i] == '\t'); i--) {
      line[i] = '\0';
      len--;
    }
    line[len + 1] = '\n';
    if (len > 1) {
      printf("%d: %s", len - 1, line);
    }
  }
  return 0;
}

// getline(): read a line into s, return length
int getline(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
