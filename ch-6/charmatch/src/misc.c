#include <ctype.h>
#include <stdio.h>

#include "charmatch.h"

void skip_whitespace() {
  int c;
  while (isspace(c = getchar())) {
  }
  ungetc(c, stdin);
}
