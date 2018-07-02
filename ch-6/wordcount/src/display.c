#include <stdio.h>

#include "wordcount.h"

void word_count_extractor(const tnode* const node) {
  // deep copy node data
  char* word = ((word_count*)(node->data))->word;
  size_t count = ((word_count*)(node->data))->count;
  word_count* wc = word_count_alloc(word);
  wc->count = count;

  // insert node data
  if (count_tree == NULL) {
    count_tree = tree_insert(count_tree, wc, sizeof(word_count), count_cmp);
  } else {
    tree_insert(count_tree, wc, sizeof(word_count), count_cmp);
  }
}

void result_print(const tnode* const node) {
  word_count* data = (word_count*)node->data;
  printf("%s: %lu\n", data->word, data->count);
}
