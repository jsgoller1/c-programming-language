#include <stdbool.h>
#include <stdio.h>

#include "2.2.h"
#include "common.h"

/*
Ex 2.2: Write a loop equivalent to the for loop below without using &&
or ||.

for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i) {
  s[i] = c;
}

*/

int main() {
  int len;
  char line[MAXLEN];  // current input line
  while ((len = getline_nobool(line, MAXLEN)) > 0) {
    printf("%d: %s\n", len, line);
  }

  return 0;
}

// getline(): read a line into s, return length
int getline_nobool(char* const s, const int lim) {
  int i;
  char c = 0;

  for (i = 0; i < lim - 1; i++) {
    c = (char)getchar();
    if (c == EOF) {
      break;
    } else if (c == '\n') {
      break;
    } else {
      s[i] = c;
    }
  }

  s[i] = '\0';
  return i;
}
