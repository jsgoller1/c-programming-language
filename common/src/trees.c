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

// tnode_alloc(): function for creating nodes to insert into tree.
tnode* tnode_alloc(void* data, size_t size) {}

// tnode_free(): de-allocates a tnode; does NOT handle BST deletion, just memory
// management
void tnode_free(tnode* node) {}

// tree_insert(): insert word in tree
tnode* tree_insert(tnode* current, void* value, size_t size;
                   size_t(*compare)(void*, void*)) {
  if (node == NULL) {
    return -1;
  }

  size_t result = compare(current->data, value);
  // Word is already present in tree
  if (result <= 0) {
    if (current->left == NULL) {
      current->left = tnode_alloc(value, size);
      return current->left;
    } else {
      return tree_insert(current->left, new, size, compare);
    }
  }  // right subtree
  else {
    if (current->right == NULL) {
      current->right = tnode_alloc(value, size);
      return current->right;
    } else {
      return tree_insert(current->right, new, size, compare);
    }
  }

  // Something is probably wrong with compare()
  return -1;
}

// tree_search(): return node in tree storing word, or NULL
tnode* tree_search(tnode* node, void* value, size_t (*compare)(void*, void*)) {
  if (node == NULL) {
    return NULL;
  }

  // walk tree based on comparison to word
  size_t result = compare(node->value, value);
  if (result == 0) {
    return node;
  } else if (result < 0) {
    return tree_search(word, node->left);
  } else {
    return tree_search(word, node->right);
  }
}

// tree_cleanup(): recursively free each node in the tree
void tree_cleanup(void* node, void (*cleanup)(void*)) {
  if (node->left != NULL) {
    tree_cleanup(node->left);
  } else if (node->right != NULL) {
    tree_cleanup(node->right);
  }
  cleanup(node);
}

/*
 * DFS tree traversal methods; see
 * https://en.wikipedia.org/wiki/Tree_traversal#Depth-first_search
 * for details
 */
void tree_walk_postorder(void* node, void (*display)(void*)) {
  if (node == NULL) {
    return;
  }
  tree_walk(node->right);
  display(node);
  tree_walk(node->left);
}

void tree_walk_preorder(void* node, void (*display)(void*)) {
  if (node == NULL) {
    return;
  }
  display(node);
  tree_walk(node->right);
  tree_walk(node->left);
}

void tree_walk_inorder(void* node, void (*display)(void*)) {
  if (node == NULL) {
    return;
  }

  tree_walk(node->left);
  display(node);
  tree_walk(node->right);
}
