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
int x = 0;
int x = 0, y = 0;

Start with parsing two tokens. If we encounter

*/
void parse_varname() {
  char temp[MAXLEN];
  char varname[MAXLEN];
  bool find_varnames = true;

  gettoken(temp, MAXLEN);  // skip over whitespace
  while (find_varnames) {
    gettoken(varname, MAXLEN);
    gettoken(temp, MAXLEN);  // following char
    printf("store_varname() | %s%c\n", varname, temp[0]);
    if (temp[0] == ',' || temp[0] == ';') {  // not a function
      printf("store_varname() | storing %s\n", varname);
    } else {
      find_varnames = false;
    }
  }
}

void display_varnames() {}

void cleanup_varnames() {}
