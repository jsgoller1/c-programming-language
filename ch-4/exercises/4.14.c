#include <stdio.h>

/*
Define a macro swap(t,x,y) that interchanges two arguments of type t. I'm going to assume
for this exercise that you would invoke it like this:
int len = 0;
int index = 1;
swap(int, len, index);

After which len would equal 1 and index would equal 2.
*/

#define SWAP(t, x, y) \
  t tmp = x;          \
  x = y;              \
  y = tmp;

int main()
{
  int one = 1;
  int two = 2;
  printf("one: %d\ntwo: %d\n", one, two);
  SWAP(int, one, two);
  printf("one: %d\ntwo: %d\n", one, two);

  return 0;
}
