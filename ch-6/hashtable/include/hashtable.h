#define HASHSIZE 101

// table entry
typedef struct kv {
  struct kv* next;  // next entry in chain
  char* name;       // defined name
  char* defn;       // replacement text
} kv;

extern kv* hashtab;
