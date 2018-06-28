typedef struct tnode {
  struct tnode* left;
  struct tnode* right;
  void* data;
} tnode;

// basic tree methods
tnode* tree_insert(tnode* node, void* value, size_t size;
                   size_t(*compare)(void*, void*));
tnode* tree_search(tnode* node, void* value, size_t (*compare)(void*, void*));

// memory management
tnode* tnode_alloc(void* data, size_t size);
void tnode_free(tnode* node);
void tree_cleanup(tnode* node);

// traversal
void tree_walk_postorder(void* node, void (*display)(void*));
void tree_walk_preorder(void* node, void (*display)(void*));
void tree_walk_inorder(void* node, void (*display)(void*));
