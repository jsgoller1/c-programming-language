#include <stdio.h>

#include "common.h"
#include "hashtable.h"

// define(): read the two following words, and use them
// for installation in the hashtable.
int define(const char* const word) {
  int c1 = 0;
  int c2 = 0;
  kv* entry = NULL;
  char key[MAXLEN] = {0};
  char value[MAXLEN] = {0};

  printf("%s", word);
  printf("%c", getchar());  // skip whitespace between "#define" and key
  c1 = getword(key, MAXLEN);
  printf("%s", key);
  printf("%c", getchar());  // skip whitespace between key and value
  c2 = getword(value, MAXLEN);
  printf("%s", value);

  if (c1 != EOF || c2 != EOF) {
    entry = install(key, value);
  }
  // printf("install() | installed %s as %s\n", entry->key, entry->value);
  return 0;
}

// undefine(): read the next word after
int undef(const char* const word) {
  int c;
  char key[MAXLEN] = {0};

  printf("%s", word);
  getchar();  // skip whitespace between "#undef" and key
  c = getword(key, MAXLEN);
  printf("%s", key);

  if (c != EOF) {
    uninstall(key);
  }
  return 0;
}
