#include <stdio.h>

// What does an "empty" value look like in an array?

int main() {
  char chars[4] = {'a', 'b', 'c', 'd'};
  chars[1] = "";
  // prints "acd"
  printf("%s\n", chars);
  return 0;
}