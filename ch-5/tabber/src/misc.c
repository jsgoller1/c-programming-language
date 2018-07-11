#include <stdio.h>
#include <stdlib.h>

#include "entab.h"

int generate_stop_list(const int start, const int interval, int** tab_stops,
                       int* const tab_stops_len) {
  int* stop_list;
  int stop_list_len;

  if (tab_stops != NULL || *tab_stops_len != 0) {
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
