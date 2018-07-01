#include <stdio.h>

#include "common.h"
#include "wordcount.h"

tnode* create_count_tree(const tnode* const word_tree_head) {
  tnode* count_tree_head = NULL;
  trav_inorder(word_tree_head, word_count_extractor);
  return count_tree_head;
}

tnode* create_word_tree(tnode* tree) {
  int i;
  char word[MAXLEN] = {0};
  tnode* current = NULL;
  word_count* wdc;

  printf("create_word_tree() | creating tree...\n");
  while ((i = getword(word, MAXLEN)) > 0) {
    printf("create_word_tree() | got word %s\n", word);
    if (tree == NULL) {
      printf("create_word_tree() | setting up word tree root.\n");
      wdc = word_count_alloc(word);
      tree = tree_insert(tree, wdc, (size_t)i,
                         word_cmp);  // as long as i > 0, cast to size_t is ok
      printf("create_word_tree() | root established \n");
      continue;
    }

    // Increment word counter if in tree, add word
    // if not.
    printf("create_word_tree() | searching for %s\n", word);
    if ((current = tree_search(tree, word, word_cmp)) != NULL) {
      ((word_count*)(current->data))->count++;
    } else {
      wdc = word_count_alloc(word);
      tree = tree_insert(tree, wdc, (size_t)i, word_cmp);
      printf("create_word_tree() | inserted %s\n", wdc->word);
    }
  }

  return tree;
}
