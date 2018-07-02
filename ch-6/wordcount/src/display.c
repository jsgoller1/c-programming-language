#include <stdio.h>

#include "wordcount.h"

void word_count_extractor(const tnode* const node) {
  if (count_tree == NULL) {
    count_tree =
        tree_insert(count_tree, node->data, sizeof(word_count), count_cmp);
  } else {
    tree_insert(count_tree, node->data, sizeof(word_count), count_cmp);
  }
}

void result_print(const tnode* const node) {
  word_count* data = (word_count*)node->data;
  printf("%s: %lu\n", data->word, data->count);
}
