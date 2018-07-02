
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101

// table entry
typedef struct kv {
  struct kv* next;  // next entry in chain
  char* name;       // defined name
  char* defn;       // replacement text
} kv;

static kv* hashtab[HASHSIZE];

// hash(): form hash value for string s
static unsigned hash(const char* const str) {
  const char* s = str;
  unsigned hashval;

  for (hashval = 0; *s != '\0'; s++) {
    hashval += (unsigned)(*s) + 31 * hashval;
  }

  // printf("hash() | hashed %s to %d\n", str, hashval % HASHSIZE);
  return hashval % HASHSIZE;
}

static kv* lookup(char* s) {
  kv* np;
  for (np = hashtab[hash(s)]; np != NULL; np = np->next) {
    if (strcmp(s, np->name) == 0) {
      return np;  // found
    }
  }
  return NULL;  // not found
}

static kv* install(char* name, char* defn) {
  kv* np;
  unsigned hashval;

  if ((np = lookup(name)) == NULL) {
    np = (kv*)malloc(sizeof(*np));
    if (np == NULL || (np->name = strdup(name)) == NULL) {
      return NULL;
    }
    hashval = hash(name);
    np->next = hashtab[hashval];
    hashtab[hashval] = np;
  } else {  // already there
    free((void*)np->defn);
  }
  if ((np->defn = strdup(defn)) == NULL) {
    return NULL;
  }
  return np;
}

int main() {
  kv* test;
  install("name", "joshua");
  test = lookup("name");
  printf("name is %s\n", test->defn);

  return 0;
}
