#include <stdio.h>

#include "wordcount.h"

tnode* create_count_tree(const tnode* const word_tree) {
  tnode* count_tree = NULL;
  trav_inorder(word_tree, word_count_extractor);
  return count_tree;
}

tnode* create_word_tree(tnode* tree) {
  int i;
  char word[MAXLEN] = {0};
  tnode* current = NULL;
  tnode* tree = NULL;
  word_count* wdc;

  while ((i = getword(word, MAXLEN)) > 0) {
    if (tree == NULL) {
      wdc = word_count_alloc(word);
      tree = tree_insert(tree, wdc, i, word_cmp);
    }

    // Increment word counter if in tree, add word
    // if not.
    if ((current = tree_search(tree, word, word_cmp)) != NULL) {
      current->data->count++;
    } else {
      wdc = word_count_alloc(word);
      tree = tree_insert(tree, wdc, i, word_cmp);
    }
  }

  return tree;
}
