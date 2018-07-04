#include <stdio.h>
#include <string.h>

#include "charmatch.h"
#include "common.h"

void store_varname() {
  char temp[MAXLEN];
  char varname[MAXLEN];
  gettoken(temp, MAXLEN);  // whitespace
  gettoken(varname, MAXLEN);
  gettoken(temp, MAXLEN);        // following char
  if (strcmp(temp, "(") != 0) {  // not a function
    printf("store_varname() | storing %s\n", varname);
  }
}

void display_varnames() {}

void cleanup_varnames() {}
