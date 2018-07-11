#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "entab.h"

static char usage[] =
    "usage: $tabber -b <entab|detab> -m <interval+start> -l <stops>\n";

// flags for keeping track of what args we've already seen
static bool seen_b = false;
static bool seen_l = false;
static bool seen_m = false;

// parse_b(): handle -b detab|entab
static int parse_b(int* const i, char** const argv, int* const behavior) {
  printf("parse_b() | argv[%d] - %s\n", *i, argv[*i]);

  if (seen_b) {
    printf("tabber: error - duplicate '-b' args.\n");
    return -1;
  }
  seen_b = true;

  char* behavior_str = argv[++(*i)];
  if (behavior_str == NULL || strlen(behavior_str) != 5) {
    printf("tabber: error - invalid behavior (-b %s)\n", argv[*i]);
    return -1;
  }

  if (strcmp("entab", behavior_str) == 0) {
    *behavior = USE_ENTAB;
    printf("parse_b() | using entab()\n");
  } else if (strcmp("detab", behavior_str) == 0) {
    *behavior = USE_DETAB;
    printf("parse_b() | using detab()\n");
  } else {
    printf("tabber: error - invalid behavior (-b %s)\n", argv[*i]);
    return -1;
  }
  return 0;
}

// parse_m(): handle shorthand -m x+y for tab stops every x columns, starting at
// column y
static int parse_m(int* const i, char** const argv, int* const start,
                   int* const interval) {
  printf("parse_m() | argv[%d] - %s\n", *i, argv[*i]);

  // Determine if -m flag is valid given the other flags we've seen
  if (seen_m) {
    printf("tabber: error - duplicate '-m' args.\n");
    return -1;
  }
  if (seen_l) {
    printf("tabber: error - '-m' and '-l' are mutually exclusive.\n");
    return -1;
  }
  seen_m = true;

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
    printf("tabber: error - invalid syntax for '-m'; use <interval+start> .\n");
    return -1;
  }

  // parse y and sanity check result
  char start_str[10];
  int l = 0;
  while (isdigit(shorthand[j])) {
    start_str[l++] = shorthand[j++];
  }
  *start = atoi(start_str);
  if (*start < 0 || 80 < *start) {
    printf(
        "tabber: error - invalid start for '-m'; must be between 0 and 80.\n");
    return -1;
  }

  return 0;
}

// parse_l(): handle -l <list of tab stops>
static int parse_l(int* const i, const int argc, char** const argv,
                   int** tab_stops, int* const tab_stops_len) {
  printf("parse_l() | argv[%d] - %s\n", *i, argv[*i]);

  // determine if -l flag is valid given other flags we've seen
  if (seen_l) {
    printf("tabber: error - duplicate '-l' args.\n");
    return -1;
  }
  if (seen_m) {
    printf("tabber: error - '-m' and '-l' are mutually exclusive.\n");
    return -1;
  }
  seen_l = true;

  int* stop_list = NULL;
  int stop_list_len = 0;

  // Allocate buffer for tab stops; we shouldn't have more than 80 tab stops if
  // no tab stops are allowed after 80 chars
  if ((stop_list = malloc(sizeof(int) * 80)) == NULL) {
    return -1;
  }

  // Read list of tab stop elements; verify that each tabstop is a number,
  // returning when we find the first one that isn't. Start at arg
  // immediately following -l
  char* current_stop = argv[++(*i)];
  while (*i < argc) {
    printf("parse_l() | current stop: %s\n", current_stop);
    // verify current stop is a number; quit if not.
    for (int k = 0; k < (int)strlen(current_stop); k++) {
      if (isdigit(current_stop[k]) != 1) {
        return 0;
      }
    }
    // copy stop to stop list, advance to next arg
    stop_list[stop_list_len++] = atoi(current_stop);
    current_stop = argv[++(*i)];
  }

  *tab_stops = stop_list;
  *tab_stops_len = stop_list_len;
  return 0;
}

int parse_flags(const int argc, char** const argv, int** tab_stops,
                int* const tab_stops_len) {
  int start = 0;
  int interval = 0;
  int behavior = 0;

  if (argc == 1) {
    printf("%s", usage);
    return -1;
  }

  for (int i = 1; i < argc; i++) {
    char* current_arg = argv[i];
    char flag = current_arg[1];  // ignore "-"
    printf("parse_flags() | %s\n", current_arg);
    switch (flag) {
      case 'b':
        if (parse_b(&i, argv, &behavior) == -1) {
          return -1;
        }
        break;
      case 'm':
        if (parse_m(&i, argv, &start, &interval) == -1) {
          return -1;
        }
        break;
      case 'l':
        if (parse_l(&i, argc, argv, tab_stops, tab_stops_len) == -1) {
          return -1;
        }
        break;
      default:
        printf("tabber: error - invalid flag %s\n", current_arg);
        return -1;
    }
  }

  printf("parse_flags() | parsed all args.\n");

  // if no tabstops are given, default to a stop every 5 chars
  if (interval == 0) {
    interval = 5;
  }
  if (*tab_stops == NULL) {
    if (generate_stop_list(start, interval, tab_stops, tab_stops_len) == -1) {
      return -1;
    }
  }

  return behavior;
}
