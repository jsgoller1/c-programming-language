#include <stdio.h>
#include <stdlib.h>

#include "entab.h"

int generate_stop_list(const int start, const int interval, int* tab_stops,
                       int* const tab_stops_len) {
  int* stop_list;

  if (tab_stops != NULL || tab_stops_len != NULL) {
    printf(
        "generate_stop_list() | error - tab stops have already been generated; "
        "quitting.\n");
    return -1;
  }

  if ((stop_list = malloc(sizeof(int) * 80)) == NULL) {
    return -1;
  }

  *tab_stops_len = 0;
  for (int i = start; i < 80; i++) {
    if ((i % interval) == 0) {
      stop_list[(*tab_stops_len)++] = i;
    }
  }

  return 0;
}
