#include <stdio.h>
#include <string.h>

#include "charmatch.h"
#include "common.h"

int MATCH_LENGTH;

int main(int argc, char** argv) {
  if ((MATCH_LENGTH = parse_input(argc, argv)) < 1) {
    return -1;
  }

  int i = 0;
  char word[MAXLEN] = {0};
  while ((i = gettoken(word, MAXLEN)) > 0) {
    if (should_evaluate(word)) {
      if (istypename(word)) {
        parse_varname();
      } else if (strcmp(word, "#define") == 0) {
        handle_define();
      } else if (strcmp(word, "typedef") == 0) {
        handle_typedef();
      }
    }
  }

  display_varnames();
  cleanup_varnames();
  cleanup_typenames();
  return 0;
}
