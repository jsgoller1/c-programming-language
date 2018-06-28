#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trees.h"

/*
 * A small BST library I wrote, mostly for chapter 6. Some assumptions:
 * - The user will provide compare(void*, void*) for comparing nodes in tree
 * traversal. Its arguments are the keys of nodes being compared, not the nodes
 * themselves.
 * - It's OK for trees to have two nodes with the same key; the key of a left
 * child is <= the parent, and a right node is > the parent.
 */

// tree_insert(): insert word in tree
tnode* tree_insert(tnode* node, void* value, size_t size,
                   int (*compare)(void*, void*)) {
  if (node == NULL) {
    return NULL;
  }

  int result = compare(node->data, value);
  // Left subtree
  if (result <= 0) {
    if (node->left == NULL) {
      node->left = tnode_alloc(value, size);
      return node->left;
    } else {
      return tree_insert(node->left, value, size, compare);
    }
  }  // Right subtree
  else {
    if (node->right == NULL) {
      node->right = tnode_alloc(value, size);
      return node->right;
    } else {
      return tree_insert(node->right, value, size, compare);
    }
  }
}

// tree_search(): return node in tree storing word, or NULL
tnode* tree_search(tnode* node, void* value, int (*compare)(void*, void*)) {
  if (node == NULL) {
    return NULL;
  }

  // walk tree based on comparison to word
  int result = compare(node->data, value);
  if (result == 0) {
    return node;
  } else if (result < 0) {
    return tree_search(node->left, value, compare);
  } else {
    return tree_search(node->right, value, compare);
  }
}

// tnode_alloc(): function for creating nodes to insert into tree.
tnode* tnode_alloc(void* data, size_t size) {
  tnode* node = malloc(sizeof(tnode));
  if (node == NULL) {
    return NULL;
  }

  node->data = malloc(size);
  if (node->data == NULL) {
    return NULL;
  }

  // NOTE: memcpy() should return node->data
  memcpy(node->data, data, size);
  return node;
}

// tnode_free(): de-allocates a tnode; does NOT handle BST deletion, just memory
// management
void tnode_free(tnode* node) {
  if (node == NULL) {
    return;
  }
  free(node->data);
  free(node);
}

// tree_cleanup(): recursively free each node in the tree
void tree_cleanup(tnode* node) {
  if (node->left != NULL) {
    tree_cleanup(node->left);
  } else if (node->right != NULL) {
    tree_cleanup(node->right);
  }
  tnode_free(node);
}

/*
 * DFS tree traversal methods; see
 * https://en.wikipedia.org/wiki/Tree_traversal#Depth-first_search
 * for details
 */
void tree_walk_postorder(tnode* node, void (*display)(tnode*)) {
  if (node == NULL) {
    return;
  }
  tree_walk_postorder(node->right, display);
  display(node);
  tree_walk_postorder(node->left, display);
}

void tree_walk_preorder(tnode* node, void (*display)(tnode*)) {
  if (node == NULL) {
    return;
  }
  display(node);
  tree_walk_preorder(node->right, display);
  tree_walk_preorder(node->left, display);
}

void tree_walk_inorder(tnode* node, void (*display)(tnode*)) {
  if (node == NULL) {
    return;
  }

  tree_walk_inorder(node->left, display);
  display(node);
  tree_walk_inorder(node->right, display);
}
