#include <stdio.h>
#include <string.h>

#include "charmatch.h"
#include "common.h"

int MATCH_LENGTH;

/*
Maybe it would be best to move gettoken() into this program, and then have
it where each call to gettoken() updates the FSM, and only store_var() actually
checks to see if the current FSM state allows for vars? Otherwise, assume all
parts of the C program are valid places for vars to occur?
*/

int main(int argc, char** argv) {
  if ((MATCH_LENGTH = parse_input(argc, argv)) < 1) {
    return -1;
  }

  int i = 0;
  char word[MAXLEN] = {0};
  while ((i = gettoken(word, MAXLEN)) > 0) {
    if (istypename(word)) {
      parse_varname();
    } else if (strcmp(word, "#define") == 0) {
      handle_define();
    } else if (strcmp(word, "typedef") == 0) {
      handle_typedef();
    }
  }

  display_varnames();
  cleanup_varnames();
  cleanup_typenames();
  return 0;
}
