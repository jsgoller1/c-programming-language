#include <ctype.h>
#include <string.h>
#include "common.h"
#include "decl.h"

// gettoken() - parse character by character until a tokentype can be
// determined. There are three valid characters: parens, brackets, or
// alphanumeric. Everything else is an error.
int gettoken(void) {
  char c;
  char *p = token;

  while ((c = (char)getch()) == ' ' || c == '\t') {
    // NOOP, skip tabs and spaces
  }

  if (c == '(') {
    // If a paren is read, determine if it's just an opener, or a pair
    if ((c = (char)getch()) == ')') {
      strcpy(token, "()");
      return tokentype = PARENS;  // pair
    } else {
      ungetch(c);
      return tokentype = '(';  // opening
    }
  } else if (c == '[') {
    // if a brace is read, copy all characters until the closing brace
    for (*p++ = c; (*p++ = (char)getch()) != ']';) {
    }
    *p = '\0';
    return tokentype = BRACKETS;
  } else if (isalpha(c)) {
    // if an alphanumeric is read, copy all characters til a non-alphanum
    for (*p++ = c; isalnum(c = (char)getch());) {
      *p++ = c;
    }
    *p = '\0';
    ungetch(c);
    return tokentype = NAME;
  } else {
    // otherwise, return the character we found (e.g. '$')
    return tokentype = c;
  }
}
