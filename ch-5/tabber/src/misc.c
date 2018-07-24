#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "tabber.h"

int generate_stop_list(const int start, const int interval, int** tab_stops,
                       int* const tab_stops_len) {
  int* stop_list;
  int stop_list_len;

  if (*tab_stops != NULL || *tab_stops_len != 0) {
    printf(
        "generate_stop_list() | error - tab stops have already been generated; "
        "quitting.\n");
    return -1;
  }

  if ((stop_list = malloc(sizeof(int) * 80)) == NULL) {
    printf("generate_stop_list() | couldn't allocate stop list.\n");
    return -1;
  }

  stop_list_len = 0;
  for (int i = start; i < 80; i++) {
    if ((i % interval) == 0) {
      stop_list[stop_list_len++] = i;
    }
  }

  *tab_stops = stop_list;
  *tab_stops_len = stop_list_len;
  return 0;
}

// next_tab_stop(): given a list of tab stops and a current
// column, determine what the next tab stop is
int next_tab_stop(const int* const tab_stops, const int tab_stops_len,
                  const int column) {
  if (tab_stops == NULL || tab_stops_len < 1) {
    return -1;
  }
  if (tab_stops_len == 1) {
    return tab_stops[0];
  }

  int prev_stop = 0;
  int next_stop = 0;
  for (int i = 0; i < tab_stops_len; i++) {
    next_stop = tab_stops[i];
    if ((prev_stop <= column) && (column < next_stop)) {
      // printf("next_tab_stop() | column: %d, next_stop: %d\n", column,
      // next_stop);
      return next_stop;
    }
    prev_stop = next_stop;
  }

  return -1;
}

// isdigits(): if string contains only digits, return 1;
// otherwise return 0.
int isdigits(const char* const string, const int len) {
  for (int i = 0; i < len; i++) {
    if (isdigit(string[i]) == 0) {
      return 0;
    }
  }
  return 1;
}
