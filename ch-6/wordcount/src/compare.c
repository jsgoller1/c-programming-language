#include <stdint.h>
#include <string.h>

#include "wordcount.h"

ssize_t count_cmp(const void* const node1, const void* const node2) {
  // TODO: NULL checks
  // cast inputs to usable types
  const tnode* const n1 = (const tnode*)node1;
  const tnode* const n2 = (const tnode*)node2;
  word_count* wc1 = (word_count*)(n1->data);
  word_count* wc2 = (word_count*)(n2->data);

  if (wc1->count == wc2->count) {
    return 0;
  } else if (wc1->count < wc2->count) {
    return -1;
  } else {
    return 1;
  }
}

ssize_t word_cmp(const void* const node1, const void* const node2) {
  // TODO: NULL checks
  // cast inputs to usable types
  const tnode* const n1 = (const tnode*)node1;
  const tnode* const n2 = (const tnode*)node2;
  word_count* wc1 = (word_count*)(n1->data);
  word_count* wc2 = (word_count*)(n2->data);

  return strcmp(wc1->word, wc2->word);
}
