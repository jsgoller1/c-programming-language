#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "charmatch.h"

bool IN_CPP_COMMENT = false;  // this kind of comment
bool IN_C_COMMENT = false;    /* this kind of comment */
bool IN_STRING = false;
bool IN_FUNCTION_PARAMS = false;

void update_fsm(const char* const token) {
  int c = 0;
  if (token == NULL) {
    return;
  }

  if ((strcmp(token, ")") == 0) && IN_FUNCTION_PARAMS) {
    IN_FUNCTION_PARAMS = false;
    return;
  }

  if (strcmp(token, "\"") == 0) {
    IN_STRING = !IN_STRING;
    return;
  }

  if (strcmp(token, "/") == 0) {
    if ((c = getchar()) == '/') {
      IN_CPP_COMMENT = true;
    } else if (c == '*') {
      IN_C_COMMENT = true;
    } else {
      ungetc(c, stdin);
    }
  }

  if (strcmp(token, "*") == 0 && IN_C_COMMENT) {
    if ((c = getchar()) == '/') {
      IN_C_COMMENT = false;
    } else {
      ungetc(c, stdin);
    }
  }

  if (strcmp(token, "\n") == 0) {
    IN_CPP_COMMENT = false;
    return;
  }
}
