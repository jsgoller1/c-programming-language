#include <string.h>

#include "wordcount.h"

int count_cmp(const tnode* const node1, const tnode* const node2) {
  int count1 = node1->data->count;
  int count2 = node2->data->count;
  if (count1 == count2) {
    return 0;
  } else if (count1 < count2) {
    return -1;
  } else {
    return 1;
  }
}

int word_cmp(const tnode* const node1, const tnode* const node2) {
  char* word1 = node1->data->word;
  char* word2 = node2->data->word;
  return strcmp(word1, word2);
}
