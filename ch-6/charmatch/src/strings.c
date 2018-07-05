#pragma clang diagnostic ignored "-Wcast-qual"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "charmatch.h"

string* alloc_string(const char* const characters) {
  string* str;
  if ((str = malloc(sizeof(string))) == NULL) {
    return NULL;
  }

  if ((str->chars = strdup(characters)) == NULL) {
    free(str);
    return NULL;
  }

  str->next_group = NULL;
  str->next_string = NULL;
  return str;
}

void free_string(string* str) {
  free(str->chars);
  free(str);
}

string* walk_groups_ll(const string* const head, const char* const str,
                       const int n) {
  const string* current = head;
  while (current != NULL) {
    if (strncmp(current->chars, str, (unsigned long)n) == 0) {
      break;
    } else {
      current = current->next_group;
    }
  }
  return (string*)current;
}

// implementing two different ll-walking functions given the need to use
// strcmp() for strings and strncmp() for groups felt easier than writing
// a single one with a more complicated interface.
string* walk_strings_ll(const string* const head, const char* const str) {
  const string* current = head;
  while (current != NULL) {
    if (strcmp(current->chars, str) == 0) {
      break;
    } else {
      current = current->next_string;
    }
  }
  return (string*)current;
}
