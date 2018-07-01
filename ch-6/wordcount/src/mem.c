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

  wc->word = malloc(len * sizeof(char));
  if (wc->word == NULL) {
    free(wc);
    return NULL;
  }

  strcpy(wc->word, word);
  return wc;
}

void word_count_free(word_count* wc) {
  if (wc == NULL) {
    return;
  }

  free(wc->word);
  free(wc);
}
