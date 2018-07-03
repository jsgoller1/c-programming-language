
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// hash(): form hash value for string s
size_t hash(const char* const str) {
  const char* s = str;
  size_t hashval;

  for (hashval = 0; *s != '\0'; s++) {
    hashval += (size_t)(*s) + 31 * hashval;
  }

  // printf("hash() | hashed %s to %d\n", str, hashval % HASHSIZE);
  return hashval % HASHSIZE;
}

kv* lookup(const char* const str) {
  kv* entry;
  for (entry = hashtab[hash(s)]; entry != NULL; entry = entry->next) {
    if (strcmp(s, entry->name) == 0) {
      return entry;  // found
    }
  }
  return NULL;  // not found
}

kv* install(const char* const name, const char* const defn) {
  kv* entry;
  size_t hashval;

  if ((entry = lookup(name)) == NULL) {
    // new entry
    entry = (kv*)malloc(sizeof(kv));
    if (entry == NULL || (entry->name = strdup(name)) == NULL) {
      return NULL;
    }
    hashval = hash(name);
    entry->next = hashtab[hashval];
    hashtab[hashval] = entry;
  } else {
    // already there
    free((void*)entry->defn);
    if ((np->defn = strdup(defn)) == NULL) {
      return NULL;
    }
    return np;
  }
