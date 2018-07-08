#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "decl.h"

int gettoken(void) {
  int c;
  char *p = token;

  while ((c = getchar()) == ' ' || c == '\t') {
    // skip whitespaces
  }

  if (c == '(') {
    if ((c = getchar()) == ')') {
      strcpy(token, "()");
      return tokentype = PARENS;
    } else {
      ungetc(c, stdin);
      return tokentype = '(';
    }
  } else if (c == '[') {
    for (*p++ = (char)c; (*p++ = (char)getchar()) != ']';) {
      // skip array size specifier
    }
    *p = '\0';
    return tokentype = BRACKETS;
  } else if (isalpha(c)) {
    for (*p++ = (char)c; isalnum(c = getchar());) {
      *p++ = (char)c;
    }
    *p = '\0';
    ungetc(c, stdin);
    return tokentype = NAME;
  } else {
    return tokentype = c;
  }
}
