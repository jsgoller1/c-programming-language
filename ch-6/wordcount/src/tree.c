#include <stdio.h>

#include "common.h"
#include "wordcount.h"

void create_count_tree(const tnode* const word_tree_head) {
  trav_inorder(word_tree_head, word_count_extractor);
}

tnode* create_word_tree(tnode* tree) {
  int i;
  char word[MAXLEN] = {0};
  tnode* current = NULL;
  word_count* wdc;

  while ((i = getword(word, MAXLEN)) > 0) {
    if (tree == NULL) {
      wdc = word_count_alloc(word);
      tree = tree_insert(tree, wdc, sizeof(word_count),
                         word_cmp);  // as long as i > 0, cast to size_t is ok
      continue;
    }

    // Increment word counter if in tree, add word
    // if not.
    word_count temp;
    temp.word = word;
    if ((current = tree_search(tree, &temp, word_cmp)) != NULL) {
      ((word_count*)(current->data))->count++;
    } else {
      wdc = word_count_alloc(word);
      tree_insert(tree, wdc, sizeof(word_count), word_cmp);
    }
  }

  return tree;
}
