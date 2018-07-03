#include <stdio.h>

#define test 100
#define foobar baz

int main() {
  int baz = 5;
  printf("%d\n", foobar + baz);
  return 0;
}
