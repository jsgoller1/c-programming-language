#include <stdio.h>

/*
In case I forget, here's a quick demo of the sizes
of each type on my machine (an Intel 6800k running x64 Ubuntu 17.10)
*/

int main() {
  printf("char: %lu bytes, %lu bits\n", sizeof(char), sizeof(char) * 8);
  printf("short: %lu bytes, %lu bits\n", sizeof(short), sizeof(short) * 8);
  printf("int: %lu bytes, %lu bits\n", sizeof(int), sizeof(int) * 8);
  printf("long: %lu bytes, %lu bits\n", sizeof(long), sizeof(long) * 8);
  printf("long long: %lu bytes, %lu bits\n", sizeof(long long),
         sizeof(long long) * 8);
  printf("float: %lu bytes, %lu bits\n", sizeof(float), sizeof(float) * 8);
  printf("double: %lu bytes, %lu bits\n\n", sizeof(double), sizeof(double) * 8);

  // What about pointers? They're addresses, their size is the wordsize for your
  // CPU.
  char* x;
  printf("long pointer: %lu bytes, %lu bits\n", sizeof(x), sizeof(x) * 8);
  long* y;
  printf("long pointer: %lu bytes, %lu bits\n\n", sizeof(y), sizeof(y) * 8);

  // What about structs? Depends what you put in them!
  struct smalls {
    char a;
    char b;
  };

  struct bigs {
    long a;
    long b;
  };

  // Structs of mixed types can have weird results depending on
  // how the compiler handles padding; this will sometimes throw
  // warnings (which are currently disabled via -Wno-padded in the
  // Makefile)
  struct mixed1 {
    char a;
    char b;
    char c;
  };

  struct mixed2 {
    float c;
    char a;
    char b;
  };
  printf("smalls: %lu bytes, %lu bits\n", sizeof(struct smalls),
         sizeof(struct smalls) * 8);
  printf("bigs: %lu bytes, %lu bits\n", sizeof(struct bigs),
         sizeof(struct bigs) * 8);
  printf("mixed1: %lu bytes, %lu bits\n", sizeof(struct mixed1),
         sizeof(struct mixed1) * 8);
  printf("mixed2: %lu bytes, %lu bits\n\n", sizeof(struct mixed2),
         sizeof(struct mixed2) * 8);

  return 0;
}
