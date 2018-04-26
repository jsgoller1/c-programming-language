#include "1.16.h"
#include <stdio.h>

/*
1.16 Revise the main routine of the longest-line program so it will correctly
print the length of arbitrarily long input lines, and as much as possible of the
text.
*/

#define MAXLINE 1000  // maximum input line size

// getline(): read a line into s, return length
int mygetline(char line[], const int maxline) {
  int c = 0, i;

  for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = (char)c;
  }
  if (c == '\n') {
    line[i] = (char)c;
    ++i;
  }
  line[i] = '\0';
  return i;
}

// copy(): copy 'from' into 'to'; assumes 'to' is big enough
void copy(char to[], const char from[]) {
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}

int main() {
  int len;                // current line length
  int max;                // maximum length seen so far
  char line[MAXLINE];     // current input line
  char longest[MAXLINE];  // longest line saved here

  max = 0;
  while ((len = mygetline(line, MAXLINE)) > 0)
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  if (max > 0)  // there was a line
    printf("%d: %s", max - 1, longest);
  return 0;
}
