typedef struct tnode {
  struct tnode* left;
  struct tnode* right;
  void* data;
} tnode;

// basic tree methods
tnode* tree_insert(tnode* node, void* value, size_t size,
                   int (*compare)(void*, void*));
tnode* tree_search(tnode* node, void* value, int (*compare)(void*, void*));

// memory management
tnode* tnode_alloc(void* data, size_t size);
void tnode_free(tnode* node);
void tree_cleanup(tnode* node);

// traversal
void tree_walk_postorder(tnode* node, void (*display)(tnode*));
void tree_walk_preorder(tnode* node, void (*display)(tnode*));
void tree_walk_inorder(tnode* node, void (*display)(tnode*));
