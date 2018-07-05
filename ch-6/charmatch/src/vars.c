#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "charmatch.h"
#include "common.h"

static var_name* defined_vars = NULL;

int store_varname(const char* const varname) {
  string* group = NULL;
  string* var = NULL;

  printf("store_varname() | storing %s\n", varname);
  // Find a group match
  if ((group = walk_groups_ll(defined_vars, varname, MATCH_LENGTH)) != NULL) {
    // found correct group, now check if string is present
    if ((var = walk_strings_ll(group, varname)) != NULL) {
      // var is present, do nothing.
      return 0;
    } else {
      // var wasn't present, add it
      if ((var = alloc_string(varname)) != NULL) {
        var->next_string = group->next_string;
        group->next_string = var;
      } else {
        printf("store_varname() | couldn't allocate a new string for var.\n");
        return -1;
      }
    }
  } else {
    // couldn't match to a group, create a new one.
    if ((group = alloc_string(varname)) != NULL) {
      group->next_group = defined_vars;
      defined_vars = group;
    } else {
      printf(
          "store_varname() | couldn't allocate a new string for new group.\n");
      return -1;
    }
  }
  return 0;
}

void parse_varname() {
  char varname[MAXLEN];
  char next_char[MAXLEN];

  while (true) {
    skip_whitespace();
    gettoken(varname, MAXLEN);
    skip_whitespace();
    gettoken(next_char, MAXLEN);  // following char
    printf("parse_varname() | varname: %s, next_char: %s\n", varname,
           next_char);
    if (next_char[0] == ',') {
      store_varname(varname);
      continue;
    } else if (next_char[0] == ';' || next_char[0] == '=' ||
               next_char[0] == '[') {
      store_varname(varname);
      break;
    } else if (next_char[0] == '(') {
      printf("parse_varname() | now inside function params\n");
      IN_FUNCTION_PARAMS = true;
      break;
    } else {
      break;
    }
  }
}

void display_varnames() {
  string* current_group = defined_vars;
  while (current_group != NULL) {
    string* current_string = current_group;
    while (current_string != NULL) {
      printf("%s | ", current_string->chars);
      current_string = current_string->next_string;
    }
    current_group = current_group->next_group;
    printf("\n");
  }
}

void cleanup_varnames() {
  string* current_group = defined_vars;
  while (current_group != NULL) {
    string* current_string = current_group;
    string* next_group = current_group->next_group;
    while (current_string != NULL) {
      string* next = current_string->next_string;
      free_string(current_string);
      current_string = next;
    }
    current_group = next_group;
  }
}
