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
int getword(char* const word);

// node.c
word_node* create_node(const char* const word);
int add_line(word_node* const node, const size_t line_no);
void display_lines(const word_node* const node);

// tree.c
word_node* tree_insert(const char* const word, word_node* const node);
word_node* tree_search(const char* const word, const word_node* const node);
void tree_walk(const word_node* const head);
void tree_cleanup(word_node* head);
