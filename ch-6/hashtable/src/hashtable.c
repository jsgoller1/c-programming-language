
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
    if ((entry = alloc_entry(key, value)) != NULL) {
      hashval = hash(key);
      entry->next = hashtab[hashval];
      hashtab[hashval] = entry;
    } else {
      // couldn't allocate
      return NULL;
    }
  } else {
    // already there
    free((void*)entry->value);
    if ((entry->value = strdup(value)) == NULL) {
      return NULL;
    }
  }
  return entry;
}

void uninstall(const char* const key) {
  kv* entry = NULL;
  kv* next = NULL;
  if ((entry = lookup(key)) != NULL) {
    while (entry->next != NULL) {
      if (strcmp(key, entry->next->key) == 0) {
        next = free_entry(entry);
        entry->next = next;
      } else {
        entry = entry->next;
      }
    }
  }
}
