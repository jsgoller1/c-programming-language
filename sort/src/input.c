#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "sort.h"

static char usage[] = "usage: sort -d -f -n -r";

// parse_args(): allowed args are -r, -n, -d, and -f
int parse_args(const int argc, char** const argv, input_flags* const flags) {
  for (int i = 1; i < argc; i++) {
    const char* const current_arg = argv[i];
    const int arg_len = (int)strlen(current_arg);
    printf("Evaluating arg: %s\n", current_arg);

    if (current_arg[0] != '-') {
      printf("sort: illegal arg '%s'\n", argv[i]);
      printf("%s\n", usage);
      return -1;
    } else {
      for (int j = 1; j < arg_len; j++) {
        switch (current_arg[j]) {
          case 'd':
            flags->directory = true;
            break;
          case 'f':
            flags->fold = true;
            break;
          case 'n':
            flags->numeric = true;
            break;
          case 'r':
            flags->reverse = true;
            break;
          default:
            printf("sort: unknown option '%c'\n", current_arg[j]);
            printf("%s\n", usage);
            return -1;
        }
      }
    }
  }
  return 0;
}
