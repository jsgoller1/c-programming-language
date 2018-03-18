#include <limits.h>
#include <stdio.h>

// Write a program to calculate the largest and smallest char, short, int, and
// long variables, signed and unsigned.
int pow2(int pow);
long lpow2(int pow);

int main() {
  int i, max_pow, max_int, min_int = 0;
  unsigned int umax = 0;
  char max_char, min_char = 0;
  unsigned char ucmax = 0;
  short max_shrt, min_shrt = 0;
  unsigned short usmax = 0;
  long max_long, min_long, max_lpow = 0;
  unsigned long ulmax = 0.0;

#define WORD_BIT 32
  for (i = 0; i < WORD_BIT; i++) {
    max_pow = max_pow | pow2(i);
    max_int = max_pow ^ pow2(WORD_BIT - 1);
    min_int = ~max_int;
    umax = max_pow;
  }
  printf("Int size, max, min: %d, %d, %d\n", WORD_BIT, INT_MAX, INT_MIN);
  printf("Max int: %d == 0x%x\n", max_int, max_int);
  printf("Min int: %d == 0x%x\n", min_int, min_int);
  printf("Max uint: %u == 0x%x\n\n", umax, umax);

  max_pow = 0;
  for (i = 0; i < CHAR_BIT; i++) {
    max_pow = max_pow | pow2(i);
    max_char = max_pow ^ pow2(CHAR_BIT - 1);
    min_char = ~max_char;
    ucmax = max_pow;
  }
  printf("Char size, max, min: %d, %d, %d\n", CHAR_BIT, CHAR_MAX, CHAR_MIN);
  printf("Max char: %d == 0x%x\n", max_char, max_char);
  printf("Min char: %d == 0x%x\n", min_char, min_char);
  printf("Max uchar: %u == 0x%x\n\n", ucmax, ucmax);

  max_pow = 0;
  for (i = 0; i < WORD_BIT / 2; i++) {
    max_pow = max_pow | pow2(i);
    max_shrt = max_pow ^ pow2(WORD_BIT / 2 - 1);
    min_shrt = ~max_shrt;
    usmax = max_pow;
  }
  printf("Short size, max, min: %d, %d, %d\n", WORD_BIT / 2, SHRT_MAX,
         SHRT_MIN);
  printf("Max short: %d == 0x%x\n", max_shrt, max_shrt);
  printf("Min short: %d == 0x%x\n", min_shrt, min_shrt);
  printf("Max ushort: %u == 0x%x\n\n", usmax, usmax);

#define LONG_SIZE 64
  max_lpow = 0;
  for (i = 0; i < LONG_SIZE; i++) {
    max_lpow = max_lpow | lpow2(i);
    max_long = max_lpow ^ lpow2(LONG_SIZE - 1);
    min_long = ~max_long;
    ulmax = max_lpow;
  }
  printf("Long size, max, min: %d, %lx, %lx\n", LONG_SIZE, LONG_MAX, LONG_MIN);
  printf("Max long: %ld == 0x%lx\n", max_long, max_long);
  printf("Min long: %ld == 0x%lx\n", min_long, min_long);
  printf("Max ulong: %lu == 0x%lx\n", ulmax, ulmax);

  return 0;
}

int pow2(int pow) {
  if (pow == 0) {
    return 1;
  } else {
    return 2 * pow2(pow - 1);
  }
}

long lpow2(int pow) {
  if (pow == 0) {
    return (long)1;
  } else {
    return (long)2 * lpow2(pow - 1);
  }
}