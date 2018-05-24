#include <stdbool.h>

typedef struct input_flags {
  bool directory;
  bool fold;
  bool numeric;
  bool reverse;
} input_flags;

// input
int parse_args(const int argc, char** const argv, input_flags* const flags);

void swap_strs(char** v, const int i, const int j);
void myqsort(char** strings, int left, int right, input_flags* flags,
             int (*comp)(void*, void*));
int numcmp(const char* const s1, const char* const s2);
int foldcmp(const char* const s1, const char* const s2);
