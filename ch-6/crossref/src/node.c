#include <alloca.h>
#include <stdlib.h>

#include "crossref.h"

int resize_line_arr(word_node* node) {
  // copy old chars to temp array
  int* temp = alloca(node->lines_max);
  for (int i = 0; i < node->lines_n; i++) {
    temp[i] = node->lines[i];
  }

  // resize old array to 2x
  node->lines_max *= 2;
  free(node->lines);
  node->lines = malloc((unsigned long)(node->lines_max * 2));

  // copy old chars to new array
  for (int i = 0; i < node->lines_n; i++) {
    node->lines[i] = temp[i];
  }

  return 0;
}

int add_line(word_node* node, int line_no) {
  // check to see if the word is already on the line
  for (int i = 0; i < node->lines_n; i++) {
    if (node->lines[i] == line_no) {
      return 0;
    }
  }

  // resize lines arr if necessary
  if (!(node->lines_n < node->lines_max)) {
    if (resize_line_arr(node) == -1) {
      return -1;
    }
  }

  // add line to lines arr
  node->lines[node->lines_n++] = line_no;
  return 0;
}
