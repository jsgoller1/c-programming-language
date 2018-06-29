#include <stdio.h>
#include <string.h>

#include "common.h"
#include "trees.h"

/*
6-4: Write a program that prints the distinct words in its input sorted into
decreasing order of frequency of occurrence. Precede each word by its count.
------
First, we need to go through the program and count words. We can use a tree
for storing words and retrieving them efficiently, borrowing from crossref.
The ordering of the tree will be by words (i.e. strcmp() results) and each node
will also store the number of occurences.

Second, we can walk the first tree, and create a second tree - this one
will be ordered by the number of occurrences, and each node will contain words.
Left nodes are <=, right nodes are >.

Third, we walk the second tree pre-order - this will print the nodes in order.
*/

typedef struct word_count {
  char* word;
  int count;
} word_count;

static tnode* word_tree = NULL;
static tnode* count_tree = NULL;

static void result_print(const tnode* const node) {
  printf("%s: %ul\n", node->data->word, node->data->count);
}

static int count_cmp(const tnode* const node1, const tnode* const node2) {
  int count1 = node1->data->count;
  int count2 = node2->data->count;
  if (count1 == count2) {
    return 0;
  } else if (count1 < count2) {
    return -1;
  } else {
    return 1;
  }
}

static int word_cmp(const tnode* const node1, const tnode* const node2) {
  char* word1 = node1->data->word;
  char* word2 = node2->data->word;
  return strcmp(word1, word2);
}

static word_count* word_count_alloc(const char* const word) {
  word_count* wc = NULL;
  char* string = NULL;
  int len = strlen(word);

  wc = malloc(sizeof(word_count));
  if (wc == NULL) {
    return NULL;
  }

  wc->word = malloc(len * sizeof(char));
  if (wc->word == NULL) {
    free(wc);
    return NULL;
  }

  strcpy(wc->word, word);
  return wc;
}

static void word_count_free(const word_count* const wc) {
  if (wc == NULL) {
    return;
  }

  free(wc->word);
  free(wc);
}

static void word_count_extractor(const tnode* const node) {
  size_t count = count_tree->data->count;
  tree_insert(count_tree, count, sizeof(count), intcmp);
}

static word_count* create_count_tree(const tnode* const word_tree) {
  tnode* count_tree = NULL;
  trav_inorder(word_tree, word_count_extractor);
  return count_tree;
}

static tnode* create_word_tree() {
  int i;
  char word[MAXLEN] = {0};
  tnode* current = NULL;
  tnode* tree = NULL;
  word_count* wdc;

  while ((i = getword(word, MAXLEN)) > 0) {
    if (tree == NULL) {
      wdc = word_count_alloc(word);
      tree = tree_insert(tree, wdc, i, strcmp);
    }

    // Increment word counter if in tree, add word
    // if not.
    if ((current = tree_search(tree, word, strcmp)) != NULL) {
      current->data->count++;
    } else {
      wdc = word_count_alloc(word);
      tree = tree_insert(tree, wdc, i, strcmp);
    }
  }

  return tree;
}

int main() {
  word_tree = create_word_tree();
  create_count_tree(word_tree);
  trav_preorder(count_tree, result_print);

  return 0;
}
