#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "charmatch.h"

static char usage[] = {"usage: charmatch <match length>"};

int parse_input(const int argc, char** const argv) {
  int length = 0;

  if (argc != 2) {
    printf("Error: must provide a match length argument.\n");
    printf("%s\n", usage);
    return 0;
  }

  if ((length = atoi(argv[1])) < 1) {
    printf("Error: match length argument must be a number.\n");
    printf("%s\n", usage);
    return 0;
  }

  return length;
}

void skip_whitespace() {
  int c;
  while (isspace(c = getchar())) {
  }
  ungetc(c, stdin);
}

string* alloc_string(const char* const characters) {
  string* str;
  if ((str = malloc(sizeof(string))) == NULL) {
    return NULL;
  }

  if ((str->chars = strdup(characters)) == NULL) {
    free(str);
    return NULL;
  }

  str->next = NULL;
  return str;
}

void free_string(string* str) {
  free(str->chars);
  free(str);
}
