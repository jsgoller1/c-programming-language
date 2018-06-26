#include <ctype.h>
#include <stdio.h>

#include "crossref.h"

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
int getword(char* word) {
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
