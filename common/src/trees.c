#pragma clang diagnostic ignored "-Wcast-qual"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trees.h"

/*
 * A small BST library I wrote, mostly for chapter 6. Some assumptions:
 * - The user will provide compare(void*, void*) callback for traversing the
 * tree - the arguments are the data portion of the node, and data passed to the
 * search function.
 * - The user will also provide an optional cleanup(void*) callback for how to
 * deal with freeing data stored in the tree; this can be NULL, which will cause
 * no additional behavior.
 * - The tree functions themselves have no idea how to handle the data stored in
 * the tree, and delegate this knowledge to compare() and cleanup().
 * - The user does not need to create or free nodes - the tree handles this.
 * The user only needs to supply the necessary callbacks and supply the tree
 * functions with data.
 * - It's OK for trees to have two nodes with the same key; the key of a left
 * child is <= the parent, and a right node is > the parent.
 */

// tree_insert(): insert data in tree. tree_insert() has no idea what data is,
// and relies on compare to deal with it. Returns the node created, or NULL on
// error.
tnode* tree_insert(tnode* const node, const void* const data, const size_t size,
                   int (*compare)(const void* const, const void* const)) {
  if (node == NULL) {
    return tnode_alloc(data);
  }

  int result = compare(node->data, data);
  // Left subtree
  if (result <= 0) {
    if (node->left == NULL) {  // is this if block actually necessary given the
                               // base case caught above? Can it be compressed?
      node->left = tnode_alloc(data);
      return node->left;
    } else {
      return tree_insert(node->left, data, size, compare);
    }
  }  // Right subtree
  else {
    if (node->right == NULL) {
      node->right = tnode_alloc(data);
      return node->right;
    } else {
      return tree_insert(node->right, data, size, compare);
    }
  }
}

// tree_search(): find data in the tree, or return null if it isn't present.
// tree_search() knows nothing about data, and relies on compare to deal with
// it. Returns the node containing matched data, or NULL.
tnode* tree_search(const tnode* const node, const void* const data,
                   int (*compare)(const void* const, const void* const)) {
  if (node == NULL) {
    return NULL;
  }
  if (node->data == NULL) {
    printf("tree_search(): node is invalid.\n");
    return NULL;
  }

  // walk tree based on comparison to word
  int result = compare(node->data, data);
  if (result == 0) {
    // explicit cast to non-const; pragma at top is for this given -Weverything
    return (tnode*)node;
  } else if (result < 0) {
    return tree_search(node->left, data, compare);
  } else {
    return tree_search(node->right, data, compare);
  }
}

// tnode_alloc(): function for creating nodes to insert into tree.
tnode* tnode_alloc(const void* const data) {
  tnode* node = malloc(sizeof(tnode));
  if (node == NULL) {
    return NULL;
  }

  node->data = (void*)data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// tnode_free(): de-allocates a tnode; does NOT handle BST deletion, just memory
// management.
void tnode_free(tnode* node, void (*cleanup)(void*)) {
  if (node == NULL) {
    return;
  }

  if (cleanup != NULL) {
    cleanup(node->data);
  }

  free(node);
}

// tree_cleanup(): recursively free each node in the tree
void tree_cleanup(tnode* node, void (*cleanup)(void*)) {
  if (node == NULL) {
    return;
  }
  if (node->left != NULL) {
    // printf("tree_cleanup() | traversing left.\n");
    tree_cleanup(node->left, cleanup);
  }

  if (node->right != NULL) {
    // printf("tree_cleanup() | traversing right.\n");
    tree_cleanup(node->right, cleanup);
  }
  // printf("tree_cleanup() | freeing node.\n");
  tnode_free(node, cleanup);
}

/*
 * DFS tree traversal methods; see
 * https://en.wikipedia.org/wiki/Tree_traversal#Depth-first_search
 * for details
 */
void trav_postorder(const tnode* const node,
                    void (*display)(const tnode* const)) {
  if (node == NULL) {
    return;
  }
  trav_postorder(node->right, display);
  display(node);
  trav_postorder(node->left, display);
}

void trav_preorder(const tnode* const node,
                   void (*display)(const tnode* const)) {
  if (node == NULL) {
    return;
  }
  display(node);
  trav_preorder(node->right, display);
  trav_preorder(node->left, display);
}

void trav_inorder(const tnode* const node,
                  void (*display)(const tnode* const)) {
  if (node == NULL) {
    return;
  }

  trav_inorder(node->left, display);
  display(node);
  trav_inorder(node->right, display);
}
