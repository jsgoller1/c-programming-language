#include <stdio.h>
#include <string.h>

#include "common.h"
#include "trees.h"
#include "wordcount.h"

tnode* word_tree = NULL;
tnode* count_tree = NULL;

int main() {
  word_tree = create_word_tree();
  trav_preorder(word_tree);

  // create_count_tree(word_tree);
  // trav_preorder(count_tree, result_print);

  return 0;
}
