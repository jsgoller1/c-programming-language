#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "charmatch.h"
#include "common.h"

static var_name* defined_vars = NULL;

void store_varname(const char* const varname) {
  string* current = defined_vars;
  // See if we find a group match
  while (current->next_group != NULL) {
    if (strncmp(varname, current->chars, (unsigned long)MATCH_LENGTH)) {
      // matched group, now find insertion point
      while (current->next != NULL) {
        // found existing, now quit.
        if (strcmp(current->chars, varname) == 0) {
          return;
        } else {
          current = current->next;
        }
      }
    } else {
      current = current->next_group;
    }
  }
  // didn't find a group, so create one.
  current->next_group = alloc_string(varname);
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
