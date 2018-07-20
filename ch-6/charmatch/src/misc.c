#pragma clang diagnostic ignored "-Wcast-qual"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

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

// gettoken(): similar to getword(), except that gettoken() looks for characters
// that are syntactically relevant to a C program instead of just alphanumeric
// words and ignores whitespace. Always reads at least one valid character or
// EOF character, but will stop parsing when it reads the first non-alphanum
// character. Returns number of chars read.
int gettoken(char* const word, const int len) {
  int c = 0;
  int i = 0;

  while (((c = getchar()) != EOF) && i < len) {
    if (!isalnum(c) && c != '_') {
      if (i == 0) {
        word[i++] = (char)c;  // always read at least one char
        break;
      } else {
        ungetc(c, stdin);
        break;
      }
    } else {
      word[i++] = (char)c;
    }
  }
  word[i] = '\0';
  update_fsm(word);
  return i;
}
