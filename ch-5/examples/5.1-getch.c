#include <ctype.h>

int getch();
void ungetch(int val);
int getint(int *pn);

int main() { return 0; }

int getint(int *pn) {
  int c, sign;

  while (isspace(c = getch())) {
    // no op
  }

  if (!isdigit(c) && c != EOF &&) }