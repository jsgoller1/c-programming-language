#include <stdio.h>

/*
K&R chapter 6.2 shows the function makepoint() as an example
on initializing structs. This felt like it had to be wrong since
temp would get cleaned up after the function returns. Does it?
When is it invalid to use stack memory from a function?

The answer here is that valued _passed as function arguments_ are
copied by the callee - unless you pass a pointer (in which case
the address is copied to the callee, which can be dereferenced to the
original value), modifying arguments of the function inside the function
body has no effect outside the function. On the other hand, returned
values are copied back to the caller.

Consider this - malloc()'s signature is void *malloc(size_t size). It
takes an int argument and returns a pointer. This means that somewhere
in the body, a void* is declared and then returned to the callee - so
the above statement about return values vs passed values must hold.
*/

struct point makepoint(int x, int y);
void bad_makepoint(struct point mystruct);

struct point {
  int x;
  int y;
};

// makepoint: make a point from x and y components
struct point makepoint(int x, int y) {
  struct point temp;
  temp.x = x;
  temp.y = y;
  return temp;
}

void bad_makepoint(struct point mystruct) {
  mystruct.x = 10;
  mystruct.y = 20;
}

int main() {
  // This is allowed; the struct is returned, so the values are copied from the
  // callee to the caller.
  struct point joshua;
  joshua = makepoint(15, 16);
  printf("joshua.x: %d, joshua.y: %d\n", joshua.x, joshua.y);

  // This is treif; the struct is copied to the callee and cleaned up after
  struct point nope;
  nope.x = 666;
  nope.y = 666;
  bad_makepoint(nope);
  printf(
      "The struct is unchanged by bad_makepoint() - nope.x: %d, nope.y: %d\n",
      nope.x, nope.y);
  return 0;
}
