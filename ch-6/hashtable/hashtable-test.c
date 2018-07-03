#include <stdio.h>

#define test1 100
#define test2 200
#define test3 300
#define foobar baz

int main() {
  int baz = 5;
  printf("%d\n", foobar + baz);
#undef foobar
  int foobar = 110;
  return foobar;
}
