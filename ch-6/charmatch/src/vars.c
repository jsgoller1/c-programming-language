#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "charmatch.h"
#include "common.h"

static var_name* defined_vars = NULL;

void store_varname(const char* const varname) {
  string* current = defined_vars;
  // See if we find a group match
  while (current != NULL) {
    if (strncmp(varname, current->chars, (unsigned long)MATCH_LENGTH)) {
      // Find insertion point in group, or quit if
      // we have already stored this var name
    }
  }
}

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
