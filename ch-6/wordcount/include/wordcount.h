#include <stdint.h>

#include "trees.h"

typedef struct word_count {
  char* word;
  size_t count;
} word_count;

extern tnode* word_tree;
extern tnode* count_tree;

// mem.c
word_count* word_count_alloc(const char* const word);
void word_count_free(word_count* wc);

// compare.c
ssize_t count_cmp(const void* const node1, const void* const node2);
ssize_t word_cmp(const void* const node1, const void* const node2);

// trees.c
tnode* create_count_tree(const tnode* const word_tree);
tnode* create_word_tree(tnode* const tree);

// display.c
void word_count_extractor(const tnode* const node);
void result_print(const tnode* const node);
