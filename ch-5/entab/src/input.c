#include <stdbool.h>
#include <stdio.h>

#include "entab.h"

static char usage[] =
    "usage: $tabber -b <entab|detab> -m <interval+offset> -l <stops>\n";

static int parse_b(int* const i, bool* const seen_b, int* const behavior) {
  if (seen_b) {
    printf("tabber: error - duplicate '-b' args.\n");
    return -1;
  } else {
    seen_b = true;
  }
  if (strcmp("entab", argv[++i]) == 0) {
    behavior = USE_ENTAB;
  } else if (strcmp("detab", argv[i]) == 0) {
    behavior = USE_DETAB;
  } else {
    printf("tabber: error - invalid behavior %s\n", argv[i]);
  }
}

static int parse_m() if (seen_m) {
  printf("tabber: error - duplicate '-m' args.\n");
  return -1;
}
else if (seen_l) {
  printf("tabber: error - '-m' and '-l' are mutually exclusive.\n");
  return -1;
}
else {
  seen_m = true;
}
}

static int parse_l() {
  if (seen_l) {
    printf("tabber: error - duplicate '-l' args.\n");
    return -1;
  } else if (seen_m) {
    printf("tabber: error - '-m' and '-l' are mutually exclusive.\n");
    return -1;
  } else {
    seen_l = true;
  }
  // handle -l
}

int parse_flags(const int argc, char** const argv, int** tab_stops,
                int* stop_list_len) {
  bool seen_b = false;
  bool seen_m = false;
  bool seen_l = false;
  int behavior = 0;

  if (argc == 1) {
    printf("%s", usage);
    return -1;
  }

  for (int i = 1; i < argc; i++) {
    char* current_arg = argv[argc];
    char flag = current_arg[1];  // ignore "-"
    switch (flag) {
      case 'b':
        if ((i = parse_b(i, &seen_b, &behavior)) == -1) {
          return -1;
        }
        break;
      case 'm':
        if ((i = parse_m()) == -1) {
          return -1;
        }
        break;
      case 'l':
        if ((i = parse_l()) == -1) {
          return -1;
        }
        break;
      default:
        printf("tabber: error - invalid flag %s\n", current_arg);
        return -1;
    }
  }

  if (tab_stops = NULL) {
    generate_stop_list(start, interval);
  }

  return behavior;
}
