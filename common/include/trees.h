typedef struct tnode {
  struct tnode* left;
  struct tnode* right;
  void* data;
} tnode;

// Trees
void* tree_insert(char* word, void* node);
void* tree_search(char* word, void* node);
void tree_walk(void* head);
void tree_cleanup(void* head);
