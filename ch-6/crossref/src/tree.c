#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "crossref.h"

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

word_node* tree_insert(char* word, word_node* node) {
  if (node == NULL) {
    return NULL;
  }

  word_node* ret_node = NULL;
  int result = strcmp(node->word, word);
  // Word is already present in tree
  if (result == 0) {
    ret_node = node;
  }  // left subtree
  else if (result < 0) {
    if (node->left == NULL) {
      node->left = create_node(word);
      ret_node = node->left;
    } else {
      ret_node = tree_insert(word, node->left);
    }
  }  // right subtree
  else {
    if (node->right == NULL) {
      node->right = create_node(word);
      ret_node = node->right;
    } else {
      ret_node = tree_insert(word, node->right);
    }
  }
  return ret_node;
}

word_node* tree_search(char* word, word_node* node) {
  // if the node isn't present in the tree
  if (node == NULL) {
    return NULL;
  }

  // walk tree based on comparison to word
  int result = strcmp(node->word, word);
  if (result == 0) {
    return node;
  } else if (result < 0) {
    tree_search(word, node->left);
  } else if (result > 0) {
    tree_search(word, node->right);
  }

  // Node not present in tree
  return NULL;
}

void tree_walk(word_node* head) {
  if (head == NULL) {
    return;
  }

  tree_walk(head->left);
  printf("%s: ", head->word);
  for (int i = 0; i < head->lines_n; i++) {
    printf("%d ", head->lines[i]);
  }
  printf("\n");
  tree_walk(head->right);
}

void tree_cleanup(word_node* head) {
  if (head->left != NULL) {
    tree_cleanup(head->left);
  } else if (head->right != NULL) {
    tree_cleanup(head->right);
  } else {
    free(head->word);
    free(head->lines);
    free(head);
  }
}
