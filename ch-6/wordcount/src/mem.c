#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wordcount.h"

word_count* word_count_alloc(const char* const word) {
  word_count* wc = NULL;
  size_t len = strlen(word);

  wc = malloc(sizeof(word_count));
  if (wc == NULL) {
    return NULL;
  }

  wc->word = malloc(len * sizeof(char) + 1);
  if (wc->word == NULL) {
    free(wc);
    return NULL;
  }

  strcpy(wc->word, word);
  wc->count = 1;
  return wc;
}

void word_count_free(void* wc) {
  if (wc == NULL) {
    printf("word_count_free() | wc is null - nothing to free.\n");
    return;
  }

  word_count* word_c = (word_count*)wc;
  if (word_c->word == NULL) {
    printf("word_count_free() | error - no word to free.\n");
    return;
  }
  // printf("word_count_free() | freeing %s\n", word_c->word);
  free(word_c->word);
  free(word_c);
}
