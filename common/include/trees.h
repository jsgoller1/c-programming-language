#pragma once
#include <stddef.h>

typedef struct tnode {
  struct tnode* left;
  struct tnode* right;
  void* data;
} tnode;

// basic tree methods
tnode* tree_insert(tnode* const node, const void* const value,
                   const size_t size,
                   int (*compare)(const void* const, const void* const));
tnode* tree_search(const tnode* const node, const void* const value,
                   int (*compare)(const void* const, const void* const));

// memory management
tnode* tnode_alloc(const void* const data, const size_t size);
void tnode_free(tnode* node);
void tree_cleanup(tnode* node, void (*cleanup)(void*));

// traversal
void trav_postorder(const tnode* const node,
                    void (*display)(const tnode* const));
void trav_preorder(const tnode* const node,
                   void (*display)(const tnode* const));
void trav_inorder(const tnode* const node, void (*display)(const tnode* const));
