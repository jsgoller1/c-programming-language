#include <alloca.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

static word_node* create_node(char* word) {
  word_node* new_node = malloc(sizeof(word_node));

  // set up string
  int word_len = (int)strlen(word);
  new_node->word = malloc((unsigned long)(word_len + 1));
  if (new_node->word == NULL) {
    free(new_node);
    return NULL;
  }
  strcpy(new_node->word, word);
  new_node->word[word_len] = '\0';

  // set up lines array
  new_node->lines = malloc(INIT_LINES);
  if (new_node->lines == NULL) {
    free(new_node->word);
    free(new_node);
    return NULL;
  }
  new_node->lines_n = 0;
  new_node->lines_max = INIT_LINES;

  // assign other values
  new_node->left = NULL;
  new_node->right = NULL;

  return new_node;
}

static word_node* tree_insert(char* word, word_node* node) {
  if (node == NULL) {
    return NULL;
  }

  int result = strcmp(node->word, word);
  // Word is already present in tree
  if (result == 0) {
    return node;
  }  // left subtree
  else if (result < 0) {
    if (node->left == NULL) {
      node->left = create_node(word);
      return node->left;
    } else {
      tree_insert(word, node->left);
    }
  }  // right subtree
  else {
    if (node->right == NULL) {
      node->right = create_node(word);
      return node->right;
    } else {
      tree_insert(word, node->right);
    }
  }
  // Should never reach here; silence compiler error
  return NULL;
}

static word_node* tree_search(char* word, word_node* node) {
  // if the node isn't present in the tree
  if (node == NULL) {
    return NULL;
  }

  // walk tree based on comparison to word
  int result = strcmp(node->word, word);
  if (result == 0) {
    return node;
  } else if (result < 0) {
    tree_search(word, node->left);
  } else if (result > 0) {
    tree_search(word, node->right);
  }

  // Node not present in tree
  return NULL;
}

static void tree_walk(word_node* head) {
  if (head == NULL) {
    return;
  }

  tree_walk(head->left);
  printf("%s\n", head->word);
  tree_walk(head->right);
}

static void tree_cleanup(word_node* head) {
  if (head->left != NULL) {
    tree_cleanup(head->left);
  } else if (head->right != NULL) {
    tree_cleanup(head->right);
  } else {
    free(head->word);
    free(head->lines);
    free(head);
  }
}

static int resize_line_arr(word_node* node) {
  // copy old chars to temp array
  int* temp = alloca(node->lines_max);
  for (int i = 0; i < node->lines_n; i++) {
    temp[i] = node->lines[i];
  }

  // resize old array to 2x
  node->lines_max *= 2;
  free(node->lines);
  node->lines = malloc((unsigned long)(node->lines_max * 2));

  // copy old chars to new array
  for (int i = 0; i < node->lines_n; i++) {
    node->lines[i] = temp[i];
  }

  return 0;
}

static int add_line(word_node* node, int line_no) {
  // check to see if the word is already on the line
  for (int i = 0; i < node->lines_n; i++) {
    if (node->lines[i] == line_no) {
      return 0;
    }
  }

  // resize lines arr if necessary
  if (!(node->lines_n < node->lines_max)) {
    if (resize_line_arr(node) == -1) {
      return -1;
    }
  }

  // add line to lines arr
  node->lines[node->lines_n++] = line_no;
  return 0;
}

/*
static int is_noise_word( char*  word, word_node* noise_words) {
  if (tree_search(word, noise_words) != NULL) {
    return 1;
  } else {
    return 0;
  }
}
*/

// getword(): get the next word from input;
static int getword(char* word) {
  int i = 0;
  int c = 0;
  c = getchar();
  while (i < MAX_WORD - 1 && isalnum(c) && c != EOF) {
    word[i] = (char)c;
    i++;
    c = getchar();
  }
  word[i] = '\0';
  return c;
}

int main() {
  int c = 0;
  int line_count = 1;
  char word[MAX_WORD];
  word_node* head = NULL;
  word_node* current = NULL;

  while ((c = getword(word)) != EOF) {
    printf("main() | got word: %s\n", word);
    if (head == NULL) {
      head = create_node(word);
    }

    // see if we've encountered the word before
    if ((current = tree_search(word, head)) == NULL) {
      current = tree_insert(word, head);
    }

    // add this line to the word's list of lines
    add_line(current, line_count);

    // bump line count if we are going to the next line
    if (c == '\n') {
      line_count++;
    }
  }

  // display tree contents, then cleanup and exit
  tree_walk(head);
  tree_cleanup(head);
  return 0;
}
