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
      printf("gettoken() | got (), tokentype PARENS\n");
      return tokentype = PARENS;
    } else {
      ungetc(c, stdin);
      printf("gettoken() | got (, tokentype (\n");
      return tokentype = '(';
    }
  } else if (c == '[') {
    for (*p++ = (char)c; (*p++ = (char)getchar()) != ']';) {
      // skip array size specifier
    }
    *p = '\0';
    printf("gettoken() | got [], tokentype BRACKETS\n");
    return tokentype = BRACKETS;
  } else if (isalpha(c)) {
    for (*p++ = (char)c; isalnum(c = getchar());) {
      *p++ = (char)c;
    }
    *p = '\0';
    ungetc(c, stdin);
    printf("gettoken() | got %s, tokentype NAME\n", token);
    return tokentype = NAME;
  } else {
    printf("gettoken() | got %c, tokentype %c\n", c, c);
    return tokentype = c;
  }
}

int istype(void) {
  for (int i = 0; i < TYPESCOUNT; i++) {
    if (strcmp(types[i], token) == 0) {
      printf("istype() | %s is a type.\n", token);
      return i;
    }
  }
  return -1;
}
