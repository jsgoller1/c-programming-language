#include <alloca.h>
#include <stdio.h>

/*
 * Exercise 6-3. Write a cross-referencer that prints a list of all words in a
 * document, and, for each word, a list of the line numbers on which it occurs.
 * Remove noise words like "the," "and," and so on.
 * -----
 * We will keep a tree of words. Each node will contain an array of ints that
 * will store the line numbers the word occurs on. We will dynamically resize
 * these arrays as needed. We will read line by line from stdin, incrementing a
 * linecount each time we see a \n. At the end, we will walk the tree and print
 * the words and their counts.
 *
 * I will abuse alloca() to make this easier on myself.
 */

#define MAXWORD 100

typedef struct word_node {
  struct word_node* left;
  struct word_node* right;
  int* lines;
  int lines_n;
  int lines_max;
} word_node;

static word_node* tree_insert(const char* const word) {}
static word_node* tree_search(const char* const word) {}
static void tree_walk(word_node* head) {}
static void tree_cleanup(word_node* head) {}

static int add_line(word_node* node) {}
static int resize_line_arr(word_node* node) {}

int main() {
  char word[MAX_WORD];
  word_node* head;
  word_node* current;

  while (getword(word) != EOF) {
    // see if we've encountered the word before
    if ((current = tree_search(word)) == NULL) {
      current = tree_insert(word);
    }

    // add this line to the word's list of lines
    add_line(current);
  }

  // display tree contents, then cleanup and exit
  tree_walk(head);
  tree_cleanup(head);
  return 0;
}
