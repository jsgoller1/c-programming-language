#include <stdio.h>

// Historically, I've included a 'char _align[n]' element in structs that didn't
// perfectly align to word boundaries; clang would throw a -Wpadded error if
// not. I think the right way to handle this is to just disable the warning /
// let the compiler handle the padding, but can you use bit fields to do
// padding?

struct weird {
  int x;   // 4
  char y;  // 1
  int z : 24;
};

int main() {
  struct weird w = {10, 'a'};
  printf("%d\n", w.x);
}
