#include <limits.h>
#include <stdio.h>

/*
Write a program to calculate the largest and smallest char, short, int, and
long variables, signed and unsigned.
---
Although the C spec determines what the max / min sizes for each type is, this
program is not portable; I am working on an Intel Core i7-6800K CPU, and:
$ arch
x86_64
$ getconf CHAR_BIT
8
$ getconf WORD_BIT
32
$ getconf LONG_BIT
64
*/

#define WORD_BIT 32
#define LONG_BIT 64

int main() {
  char max_char = 0x7F, min_char = (char)0x80;
  unsigned char ucmax = (unsigned char)0xFF;

  printf("Char size: %d, max: %d, min: %d\n", CHAR_BIT, CHAR_MAX, CHAR_MIN);
  printf("Max char: %d == 0x%x\n", max_char, max_char);
  printf("Min char: %d == 0x%x\n", min_char, min_char);
  printf("Max uchar: %u == 0x%x\n\n", ucmax, ucmax);

  short max_shrt = 0x7FFF, min_shrt = (short)0x8000;
  unsigned short usmax = (unsigned short)0x7FFF;

  printf("Short size: %d, max: %d, min: %d\n", WORD_BIT / 2, SHRT_MAX,
         SHRT_MIN);
  printf("Max short: %d == 0x%x\n", max_shrt, max_shrt);
  printf("Min short: %d == 0x%x\n", min_shrt, min_shrt);
  printf("Max ushort: %u == 0x%x\n\n", usmax, usmax);

  int max_int = 0x7FFFFFFF, min_int = (int)0x80000000;
  unsigned int umax = (unsigned int)0xFFFFFFFF;

  printf("Int size: %d, max: %d, min: %d\n", WORD_BIT, INT_MAX, INT_MIN);
  printf("Max int: %d == 0x%x\n", max_int, max_int);
  printf("Min int: %d == 0x%x\n", min_int, min_int);
  printf("Max uint: %u == 0x%x\n\n", umax, umax);

  long max_long = 0x7FFFFFFFFFFFFFFF, min_long = (long)0x8000000000000000;
  unsigned long ulmax = (unsigned long)0xFFFFFFFFFFFFFFFF;

  printf("Long size: %d, max: %ld, min: %ld\n", LONG_BIT, LONG_MAX, LONG_MIN);
  printf("Max long: %ld == 0x%lx\n", max_long, max_long);
  printf("Min long: %ld == 0x%lx\n", min_long, min_long);
  printf("Max ulong: %lu == 0x%lx\n", ulmax, ulmax);

  return 0;
}
