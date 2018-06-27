#include <alloca.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "crossref.h"

// create_node(): allocate a new node
word_node* create_node(char* word) {
  word_node* new_node = malloc(sizeof(word_node));

  // set up string
  int word_len = (int)strlen(word);
  new_node->word = malloc((unsigned long)(word_len + 1));
  if (new_node->word == NULL) {
    free(new_node);
    return NULL;
  }
  strcpy(new_node->word, word);
  new_node->word[word_len] = '\0';

  // set up lines array
  new_node->lines = malloc(INIT_LINES);
  if (new_node->lines == NULL) {
    free(new_node->word);
    free(new_node);
    return NULL;
  }
  new_node->lines_n = 0;
  new_node->lines_max = INIT_LINES;

  // assign other values
  new_node->left = NULL;
  new_node->right = NULL;

  return new_node;
}

// resize_line_arr(): dynamically resize node's line array
int resize_line_arr(word_node* node) {
  // create larger buffer
  int old_max = node->lines_max;
  node->lines_max *= 2;
  int* new_lines = malloc((unsigned long)node->lines_max);
  if (new_lines == NULL) {
    printf("resize_line_arr() | cannot resize line arr for %s, quitting.\n",
           node->word);
    return -1;
  }

  // copy chars in old buffer to new buffer
  for (int i = 0; i < old_max; i++) {
    new_lines[i] = node->lines[i];
  }

  // free old buffer and assign new one
  free(node->lines);
  node->lines = new_lines;
  return 0;
}

// add_line(): add a line number to a node's list of lines
int add_line(word_node* node, int line_no) {
  if (node == NULL) {
    return -1;
  }

  // check to see if the word is already on the line
  for (int i = 0; i < node->lines_n; i++) {
    if (node->lines[i] == line_no) {
      return 0;
    }
  }

  // resize lines arr if necessary
  // (if lines_max is 5, last usable one is lines[4])
  if (node->lines_n == node->lines_max - 1) {
    printf("Calling resize...\n");
    if (resize_line_arr(node) == -1) {
      return -1;
    }
  }

  // add line to lines arr
  node->lines[node->lines_n++] = line_no;
  return 0;
}

// display_line(): display all lines in line buffer
void display_lines(word_node* node, int* arr) {
  printf("%s (n: %d, max: %d): ", node->word, node->lines_n, node->lines_max);
  for (int i = 0; i < node->lines_n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
