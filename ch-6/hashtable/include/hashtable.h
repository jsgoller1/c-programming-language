#define HASHSIZE 101

// table entry
typedef struct kv {
  struct kv* next;  // next entry in chain
  char* key;        // defined name
  char* value;      // replacement text
} kv;

extern kv* hashtab[HASHSIZE];

// hashtable
size_t hash(const char* const str);
kv* lookup(const char* const str);
kv* install(const char* const name, const char* const defn);
void uninstall(const char* const key);

// preprocessor
int define(const char* const word);
int undef(const char* const word);

// mem
kv* free_entry(kv* entry);
kv* alloc_entry()
