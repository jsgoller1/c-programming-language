#include <stdio.h>
#include <string.h>

#include "common.h"
#include "hashtable.h"

kv* hashtab[HASHSIZE];

int main() {
  int c = 0;
  char word[MAXLEN] = {0};
  while ((c = getword(word, MAXLEN)) > 0) {
    if (strcmp(word, "#define") == 0) {
      define(word);
    } else if (strcmp(word, "#undef") == 0) {
      undef(word);
    } else {
      // lookup and print val or word
      kv* entry;
      if ((entry = lookup(word)) != NULL) {
        printf("%s", entry->value);
      } else {
        printf("%s", word);
      }
    }
  }
  return 0;
}
