#include <stdio.h>

#include "charmatch.h"
#include "common.h"

// TODO: make sure we cover unions, enums, and possibly structs
#define BASIC_COUNT 7
static char* basic_c_types[] = {"char",  "short",  "int", "long",
                                "float", "double", "bool"};

#define SPECIAL_COUNT 3
static char* special_c_types[] = {"long", "signed", "unsigned"};

static type_name* defined_types = NULL;

static int add_type() {}

// istypename(): given our lists above, determine if a parsed word is a type
// name
int istypename(const char* const word) {
  for (int i = 0; i < BASIC_COUNT; i++) {
    if (strcmp(word, basic_c_types[i]) == 0) {
      return 1;
    }
  }
  for (int i = 0; i < SPECIAL_COUNT; i++) {
    if (strcmp(word, special_c_types[i]) == 0) {
      return 1;
    }
  }
  type_name* current = defined_types;
  while (current != NULL) {
    if (strcmp(current->chars, word) == 0) {
      return 1;
    }
    current = current->next;
  }
  return 0;
}

// handle_define(): handle further parsing if "#define" is parsed.
// Ex. "#define foobar int"
void handle_define(void) {
  char space[MAXLEN];
  char defn[MAXLEN];
  char value[MAXLEN];

  getword(space);
  getword(defn);
  getword(space);
  getword(value);

  if (istypename(value)) {
    add_type(defn);
  }
}

// handle_typedef(): handle further parsing if "typedef" is parsed
void handle_typedef(void) {}
