#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "charmatch.h"
#include "common.h"

/*
parse_varname(): given that we know that the stream is in a valid region of
code, we look for four possible variable declarations:
int x;
int x, y;

Start with parsing two tokens. If we encounter

*/

void parse_varname() {
  char varname[MAXLEN];
  char next_char[MAXLEN];

  while (true) {
    skip_whitespace();
    gettoken(varname, MAXLEN);
    skip_whitespace();
    gettoken(next_char, MAXLEN);  // following char
    if (next_char[0] == ',') {
      printf("store_varname() | storing %s\n", varname);
      continue;
    } else if (next_char[0] == ';' || next_char[0] == '=') {
      printf("store_varname() | storing %s\n", varname);
      break;
    } else if (next_char[0] == '(') {
      IN_FUNCTION_PARAMS = true;
      break;
    } else {
      break;
    }
  }
}

void display_varnames() {}

void cleanup_varnames() {}
