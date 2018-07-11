#include <stdbool.h>
#include <stdio.h>

#include "entab.h"

static char usage[] =
    "usage: $tabber -b <entab|detab> -m <interval+offset> -l <stops>\n";

// parse_b(): handle -b detab|entab
static int parse_b(const int* i, bool* const seen_b, int* const behavior) {
  if (*seen_b) {
    printf("tabber: error - duplicate '-b' args.\n");
    return -1;
  }
  *seen_b = true;

  char* behavior_str = argv[++(*i)];
  if (behavior_str == NULL || strlen(behavior_str) != 5) {
    printf("tabber: error - invalid behavior (-b %s)\n", argv[*i]);
    return -1;
  }

  if (strcmp("entab", behavior_str) == 0) {
    *behavior = USE_ENTAB;
  } else if (strcmp("detab", behavior_str) == 0) {
    *behavior = USE_DETAB;
  } else {
    printf("tabber: error - invalid behavior (-b %s)\n", argv[*i]);
    return -1;
  }
  return 0;
}

// parse_m(): handle shorthand -m x+y for tab stops every x columns, starting at
// column y
static int parse_m(const int* i, char** const argv, bool* const seen_m,
                   const bool* const seen_l, int* const start,
                   int* const interval) {
  // Determine if -m flag is valid given the other flags we've seen
  if (*seen_m) {
    printf("tabber: error - duplicate '-m' args.\n");
    return -1;
  }
  if (*seen_l) {
    printf("tabber: error - '-m' and '-l' are mutually exclusive.\n");
    return -1;
  }
  *seen_m = true;

  // Begin parsing the shorthand; ensure the string is of sane size
  char* shorthand = argv[++(*i)];
  if (strlen(shorthand) > 10) {
    printf("tabber: error - '-m' args are too big.\n");
    return -1;
  }

  // parse x and sanity check result
  char interval_str[10];
  int j = 0, k = 0;
  while (isdigit(shorthand[j])) {
    interval_str[k++] = shorthand[j++];
  }
  *interval = atoi(interval_str);
  if (*interval < 1 || 80 < *interval) {
    printf(
        "tabber: error - invalid interval for '-m'; must be between 1 and "
        "80.\n");
    return -1;
  }

  // ensure + symbol exists
  if (shorthand[j++] != '+') {
    printf(
        "tabber: error - invalid syntax for '-m'; use <interval+offset> .\n");
    return -1;
  }

  // parse y and sanity check result
  char offset_str[10];
  int l = 0;
  while (isdigit(shorthand[j])) {
    offset_str[l++] = shorthand[j++];
  }
  *offset = atoi(offset_str);
  if (*offset < 0 || 80 < *offset) {
    printf(
        "tabber: error - invalid offset for '-m'; must be between 0 and 80.\n");
    return -1;
  }

  return 0;
}

// parse_l(): handle -l <list of tab stops>
static int parse_l(const int* i, const bool* const seen_m,
                   const bool* const seen_l, int** tab_stops,
                   int* stop_list_len) {
  if (seen_l) {
    printf("tabber: error - duplicate '-l' args.\n");
    return -1;
  }
  if (seen_m) {
    printf("tabber: error - '-m' and '-l' are mutually exclusive.\n");
    return -1;
  }

  seen_l = true;

  return 0;
}

int parse_flags(const int argc, char** const argv, int** tab_stops,
                int* stop_list_len) {
  bool seen_b = false;
  bool seen_m = false;
  bool seen_l = false;
  int start = 0;
  int interval = 0;
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
        if (parse_b(&i, argv, &seen_b, &behavior) == -1) {
          return -1;
        }
        break;
      case 'm':
        if (parse_m(&i, argv, &seen_b, &seen_l, &start, &interval) == -1) {
          return -1;
        }
        break;
      case 'l':
        if (parse_l(&i, argv, &seen_b, &seen_l, tab_stops) == -1) {
          return -1;
        }
        break;
      default:
        printf("tabber: error - invalid flag %s\n", current_arg);
        return -1;
    }
  }

  if (tab_stops = NULL) {
    if (generate_stop_list(start, interval, tab_stop, stop_list_len) == -1) {
      return -1;
    }
  }

  return behavior;
}
