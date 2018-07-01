#include <stdio.h>

#include "wordcount.h"

void word_count_extractor(const tnode* const node) {
  size_t count = ((word_count*)(node->data))->count;

  // NOTE: tree_insert() returns the node inserted.
  // NOTE: count will be memcpy'd, so passing the addr is ok.
  // TODO: The sizeof(count) is definitely wrong. This will bubble down to a
  // malloc that expects it to be the exact number of bytes -
  tree_insert(count_tree, &count, sizeof(count), count_cmp);
}

void result_print(const tnode* const node) {
  word_count* data = (word_count*)node->data;
  printf("%s: %lu\n", data->word, data->count);
}
