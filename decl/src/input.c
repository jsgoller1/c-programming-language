#include <ctype.h>
#include <string.h>
#include "common.h"
#include "decl.h"

int gettoken(void) {
  char c;
  char *p = token;

  while ((c = (char)getch()) == ' ' || c == '\t') {
    // NOOP, skip tabs and spaces
  }

  if (c == '(') {
    if ((c = (char)getch()) == ')') {
      strcpy(token, "()");
      return tokentype = PARENS;
    } else {
      ungetch(c);
      return tokentype = '(';
    }
  } else if (c == '[') {
    for (*p++ = c; (*p++ = (char)getch()) != ']';) {
      // NOOP, skip til braces
    }
    *p = '\0';
    return tokentype = BRACKETS;
  } else if (isalpha(c)) {
    for (*p++ = c; isalnum(c = (char)getch());) {
      *p++ = c;
    }
    *p = '\0';
    ungetch(c);
    return tokentype = NAME;
  } else {
    return tokentype = c;
  }
}
