#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "crossref.h"

// tree_insert(): insert word in tree
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

// tree_search(): return node in tree storing word, or NULL
word_node* tree_search(char* word, word_node* node) {
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

// tree_walk(): post-order walk the tree, printing strings and line buffers
void tree_walk(word_node* head) {
  if (head == NULL) {
    return;
  }
  tree_walk(head->right);
  display_lines(head);
  tree_walk(head->left);
}

// tree_cleanup(): recursively free each node in the tree
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
