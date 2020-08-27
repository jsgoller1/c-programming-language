#include <stdio.h>

// What is the correct way in C to initialize a literal string?
// https://softwareengineering.stackexchange.com/a/183862

int main() {
  /*
  Suppose I want to declare the contents of a string at compile time.
  I can use a string literal to do this.
  */
  char name[14] = {"JOSHUA GOLLER"};
  char name2[] = {"Luke Skywalker"};
  // Note that "JOSHUA GOLLER" has 13 characters, and
  // so we initialize an array of 14 chars to include the \0.
  // In the second case, the size of the array is taken from the initializer.

  int i = 0;
  for (i = 0; i < 13; i++) {
    printf("%d, %c\n", name[i], name[i]);
  }
  printf("\n");

  // Although the initializer will put a \0
  // at the end of name2, this looping method
  // is less safe; it's better to be explicit
  // about the length of a string than not
  // know but assume it's null terminated.
  i = 0;
  while (name2[i] != '\0') {
    printf("%d, %c\n", name2[i], name2[i]);
    i++;
  }
  printf("\n");
  return 0;
}
