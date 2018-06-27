#define MAX_WORD 100
#define INIT_LINES 5

typedef struct word_node {
  char* word;
  size_t* lines;
  size_t lines_n;
  size_t lines_max;
  struct word_node* left;
  struct word_node* right;
} word_node;

// io.c
int getword(char* word);

// node.c
int add_line(word_node* node, size_t line_no);
void display_lines(word_node* node);

// tree.c
word_node* create_node(char* word);
word_node* tree_insert(char* word, word_node* node);
word_node* tree_search(char* word, word_node* node);
void tree_walk(word_node* head);
void tree_cleanup(word_node* head);
