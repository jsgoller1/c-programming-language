#include <stdio.h>

#include "common.h"

static kv* hashtab[HASHSIZE];

int main() {
  char c1, c2, c3;
  char word[MAXWORD];
  char key[MAXWORD];
  char value[MAXWORD];
  while ((c = getword(word)) != EOF) {
    if (strcmp(word, "#define") == 0) {
      c2 = getword(key);
      c3 = getword(value);
      if (c2 != EOF || c3 != EOF) {
        define(key, value);
      }
    } else if (strcmp(word, "#undef") == 0) {
      c2 = getword(key);
      if (c2 != EOF) {
        undefine(key);
      }
    } else {
      // lookup and print val or word
      printf(word);
    }
    install("name", "joshua");
    test = lookup("name");
    printf("name is %s\n", test->defn);

    return 0;
  }
}
