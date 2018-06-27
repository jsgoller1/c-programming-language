#include <alloca.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "crossref.h"

// create_node(): allocate a new node
word_node* create_node(char* word) {
  if (word == NULL) {
    printf("create_node() | cannot create node for null string.\n");
    return NULL;
  }

  word_node* new_node = malloc(sizeof(word_node));
  if (new_node == NULL) {
    printf("create_node() | couldn't allocate node.\n");
    return NULL;
  }

  // set up string
  size_t word_len = strlen(word);
  new_node->word = malloc((word_len + 1) * sizeof(char));
  if (new_node->word == NULL) {
    printf("create_node() | couldn't allocate word buffer.\n");
    free(new_node);
    return NULL;
  }
  strncpy(new_node->word, word, word_len);
  new_node->word[word_len] = '\0';

  // set up lines array
  new_node->lines = malloc(INIT_LINES * sizeof(size_t));
  if (new_node->lines == NULL) {
    printf("create_node() | couldn't allocate lines buffer.\n");
    free(new_node->word);
    free(new_node);
    return NULL;
  }
  new_node->lines_n = 0;
  new_node->lines_max = INIT_LINES;

  // assign other values
  new_node->left = NULL;
  new_node->right = NULL;

  printf("create_node() | created node for %s.\n", new_node->word);
  return new_node;
}

// add_line(): add a line number to a node's list of lines
int add_line(word_node* node, size_t line_no) {
  if (node == NULL) {
    return -1;
  }

  // check to see if the word is already on the line
  for (size_t i = 0; i < node->lines_n; i++) {
    if (node->lines[i] == line_no) {
      return 0;
    }
  }

  // resize lines arr if necessary
  // (if lines_max is 5, last usable one is lines[4])
  if (node->lines_n == node->lines_max - 1) {
    printf("add_lines() | resizing %s\n", node->word);
    display_lines(node);
    node->lines_max *= 2;
    node->lines = realloc(node->lines, node->lines_max * sizeof(size_t));
    if (node->lines == NULL) {
      printf("add_line() | couldn't resize buffer, quitting.\n");
      return -1;
    } else {
      printf("add_lines() | resized.\n");
      display_lines(node);
      printf("\n");
    }
  }
  // add line to lines arr
  printf("add_lines() | writing %lu to %s->lines[%lu]\n", line_no, node->word,
         node->lines_n);
  node->lines[node->lines_n++] = line_no;
  return 0;
}

// display_line(): display all lines in line buffer
void display_lines(word_node* node) {
  printf("%s (n: %lu, max: %lu): ", node->word, node->lines_n, node->lines_max);
  for (size_t i = 0; i < node->lines_n; i++) {
    printf("%lu ", node->lines[i]);
  }
  printf("\n");
}
