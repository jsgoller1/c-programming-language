#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma clang diagnostic ignored "-Wcast-qual"

#include "crossref.h"

// tree_insert(): insert word in tree
word_node* tree_insert(const char* const word, word_node* const node) {
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

// tree_search(): return node in tree storing word, or NULL
word_node* tree_search(const char* const word, const word_node* const node) {
  if (node == NULL) {
    return NULL;
  }

  // walk tree based on comparison to word
  int result = strcmp(node->word, word);
  if (result == 0) {
    return (word_node*)node;
  } else if (result < 0) {
    return tree_search(word, node->left);
  } else {
    return tree_search(word, node->right);
  }
}

// tree_walk(): post-order walk the tree, printing strings and line buffers
void tree_walk(const word_node* const head) {
  if (head == NULL) {
    return;
  }
  tree_walk(head->right);
  display_lines(head);
  tree_walk(head->left);
}

// tree_cleanup(): recursively free each node in the tree
void tree_cleanup(word_node* node) {
  if (node->left != NULL) {
    tree_cleanup(node->left);
  }
  if (node->right != NULL) {
    tree_cleanup(node->right);
  }
  free(node->word);
  free(node->lines);
  free(node);
}
