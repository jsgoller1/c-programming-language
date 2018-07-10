#include <stdio.h>

#include "entab.h"

int* generate_stop_list(const int start, const int interval) {
  int* stop_list;
  if ((stop_list = malloc(sizeof(int) * 80)) == NULL) {
    return -1;
  }

  for (int i = start, j = 0; i < 80; i++) {
    if ((i % interval) == 0) {
      stop_list[j++] = i;
    }
  }

  return stop_list;
}
