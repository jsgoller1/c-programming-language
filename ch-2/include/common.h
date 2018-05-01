#include <stdbool.h>

#define MAXLINE 1000  // maximum input line size

int powi(int base, int exp);
int create_mask(const int n, const int position, int* const mask,
                const bool inverted);
int clear_bitfield(int* x, const int position, const int n);
