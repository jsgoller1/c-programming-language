#include <stdlib.h>

#include "hashtable.h"

// free_entry(): handles de-allocation for a hashtable entry.
// Returns a pointer to the next entry in the linked list, or null if there
// isn't one.
kv* free_entry(kv* entry) {
  if (entry == NULL) {
    return NULL;
  }
  kv* next = entry->next;
  free(entry->key);
  free(entry->value);
  free(entry);
  return next;
}

kv* alloc_entry(const char* const key, const char* const value) {
  kv* entry;

  if ((entry = (kv*)malloc(sizeof(kv))) == NULL) {
    return NULL;
  }

  if ((entry->key = strdup(key)) == NULL) {
    free(entry);
    return NULL;
  }

  if ((entry->value = strdup(value)) == NULL) {
    free(entry->key);
    free(entry);
    return NULL;
  }

  return entry;
}
