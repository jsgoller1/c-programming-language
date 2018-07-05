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

static void skip_whitespace() {
  int c;
  while (isspace(c = getchar())) {
  }
  ungetc(c);
}

void parse_varname() {
  char varname[MAXLEN];

  while () {
    skip_whitespace();
    gettoken(varname, MAXLEN);
    skip_whitespace();
    gettoken(temp, MAXLEN);  // following char
    if (temp[0] == ',') {    // not a function
      printf("store_varname() | storing %s\n", varname);
      continue;
    } else if (temp[0] == ';') {
      printf("store_varname() | storing %s\n", varname);
      break;
    } else {
      break;
    }
  }
}

void display_varnames() {}

void cleanup_varnames() {}
