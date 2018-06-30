#include <stdio.h>

#include "wordcount.h"

void word_count_extractor(const tnode* const node) {
  size_t count = count_tree->data->count;
  tree_insert(count_tree, count, sizeof(count), intcmp);
}

void result_print(const tnode* const node) {
  printf("%s: %ul\n", node->data->word, node->data->count);
}
