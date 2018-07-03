
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashtable.h"

// hash(): form hash value for string s
size_t hash(const char* const key) {
  const char* s = key;
  size_t hashval;

  for (hashval = 0; *s != '\0'; s++) {
    hashval += (size_t)(*s) + 31 * hashval;
  }

  return hashval % HASHSIZE;
}

// free_entry(): handles de-allocation for a hashtable entry.
// Returns a pointer to the next entry in the linked list, or null if there
// isn't one.
kv* free_entry(kv* entry) {
  if (entry == NULL) {
    return NULL;
  }
}

kv* lookup(const char* const key) {
  kv* entry;
  for (entry = hashtab[hash(key)]; entry != NULL; entry = entry->next) {
    if (strcmp(key, entry->key) == 0) {
      return entry;  // found
    }
  }
  return NULL;  // not found
}

kv* install(const char* const key, const char* const value) {
  kv* entry;
  size_t hashval;

  if ((entry = lookup(key)) == NULL) {
    // new entry
    entry = (kv*)malloc(sizeof(kv));
    if (entry == NULL || (entry->key = strdup(key)) == NULL) {
      return NULL;
    }
    hashval = hash(key);
    entry->next = hashtab[hashval];
    hashtab[hashval] = entry;
  } else {
    // already there
    free((void*)entry->value);
  }
  if ((entry->value = strdup(value)) == NULL) {
    return NULL;
  }
  return entry;
}

void uninstall(const char* const key) {
  kv* entry;
  if ((entry = lookup(key)) != NULL) {
    if (strcmp(key, entry->key) == 0) {
    }
  }
}
