typedef struct word_count {
  char* word;
  int count;
} word_count;

extern tnode* word_tree;
extern tnode* count_tree;

// mem.c
word_count* word_count_alloc(const char* const word);
void word_count_free(const word_count* const wc);

// compare.c
int count_cmp(const tnode* const node1, const tnode* const node2);
int word_cmp(const tnode* const node1, const tnode* const node2);

// trees.c
word_count* create_count_tree(const tnode* const word_tree);
word_count* create_tree(tnode* tree);

// display.c
void word_count_extractor(const tnode* const node);
void result_print(const tnode* const node);
