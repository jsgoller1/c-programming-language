#include <stdio.h>

// Verify that the expression `getchar() != EOF` is 0 or 1.

int main() {

   int foo = (getchar() != EOF);
   if (foo == 1 || foo == 0) {
       return 0; // somewhat confusing, but this is supposed to be unix style for "this worked correctly"
   } else {
       return 1;
   }
}