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

static void display_word_count() {}

static word_count* word_count_alloc() {}

static word_count* word_count_free() {}

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
}

int main() {
  tnode* word_tree = NULL;
  tnode* count_tree = NULL;

  word_tree = create_word_tree();
  count_tree = create_count_tree(word_tree);
  trav_preorder(count_tree);

  return 0;
}
