#include <stdio.h>
#include <string.h>

#include "wordcount.h"

int count_cmp(const void* const word_count1, const void* const word_count2) {
  if (word_count1 == NULL) {
    printf("word_cmp() | error - word_count1 is NULL.\n");
    return -1;
  } else if (word_count2 == NULL) {
    printf("word_cmp() | error - word_count2 is NULL.\n");
    return -1;
  }
  const word_count* const wc1 = (const word_count*)(word_count1);
  const word_count* const wc2 = (const word_count*)(word_count2);

  if (wc1->count == wc2->count) {
    return 0;
  } else if (wc1->count < wc2->count) {
    return -1;
  } else {
    return 1;
  }
}

int word_cmp(const void* const word_count1, const void* const word_count2) {
  if (word_count1 == NULL) {
    printf("word_cmp() | error - word_count1 is NULL.\n");
    return -1;
  } else if (word_count2 == NULL) {
    printf("word_cmp() | error - word_count2 is NULL.\n");
    return -1;
  }
  const word_count* const wc1 = (const word_count*)(word_count1);
  const word_count* const wc2 = (const word_count*)(word_count2);

  if (wc1->word == NULL) {
    printf("word_cmp() | error - node1->word_count->word is NULL.\n");
    return -1;
  } else if (wc2->word == NULL) {
    printf("word_cmp() | error - node1->word_count->word is NULL.\n");
    return -1;
  }

  // In our BST, we treat "coming after" alphabetically as "greater than";
  // if we insert "cat", "bat", and "hat", the result should be that "cat" is
  // the root, "bat" is its left child, and "hat" is its right child. However,
  // strcmp("cat", "hat") will return a negative because "hat" comes after
  // "cat", and this will cause the tree to make "hat" the left child of "bat"
  // instead, so we need to multiply the result by -1.
  return strcmp(wc1->word, wc2->word) * -1;
}
