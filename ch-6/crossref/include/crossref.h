#define MAX_WORD 100
#define INIT_LINES 25

typedef struct word_node {
  char* word;
  int* lines;
  int lines_n;
  int lines_max;
  struct word_node* left;
  struct word_node* right;
} word_node;

// io.c
int getword(char* word);

// node.c
int resize_line_arr(word_node* node);
int add_line(word_node* node, int line_no);

// tree.c
word_node* create_node(char* word);
word_node* tree_insert(char* word, word_node* node);
word_node* tree_search(char* word, word_node* node);
void tree_walk(word_node* head);
void tree_cleanup(word_node* head);
