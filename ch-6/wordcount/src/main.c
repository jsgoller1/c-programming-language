#include <stdio.h>
#include <string.h>

#include "common.h"
#include "trees.h"
#include "wordcount.h"

tnode* word_tree = NULL;
tnode* count_tree = NULL;

int main() {
  word_tree = create_word_tree(word_tree);
  create_count_tree(word_tree);
  trav_inorder(count_tree, result_print);
  tree_cleanup(word_tree, word_count_free);
  tree_cleanup(count_tree, word_count_free);

  return 0;
}
