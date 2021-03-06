#include <stdbool.h>

typedef struct input_flags {
  bool directory;
  bool fold;
  bool numeric;
  bool reverse;
  bool in_use;
  char _align[3];
} input_flags;

// input
int parse_args(const int argc, char** const argv, input_flags* const p_flags,
               input_flags* const s_flags);

// sort
void myqsort(char** strings, int left, int right, input_flags* flags,
             int (*comp)(void*, void*));
void swap_strs(char** v, const int i, const int j);

// compare
int dircmp(const char* const s1, const char* const s2);
int foldcmp(const char* const s1, const char* const s2);
int numcmp(const char* const s1, const char* const s2);
void dir_strip(char* const dest, const char* const src, const int n);

// strings
int split(char* string, int offset, char splitchar, char** substrings);
int join(char** substrings, int count, char* joinstr, char* string);
int indexof(char* string, char character);
