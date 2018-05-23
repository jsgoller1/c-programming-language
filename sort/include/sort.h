#include <stdbool.h>

void swap_strs(char** v, const int i, const int j);
void myqsort(char** strings, int left, int right, int (*comp)(void*, void*));
int numcmp(const char* const s1, const char* const s2);

typedef struct input_flags {
  bool directory;
  bool fold;
  bool numeric;
  bool reverse;
} input_flags;
