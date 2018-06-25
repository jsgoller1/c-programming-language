#include <stdio.h>

/*
 * Exercise 7.9: Functions like isupper can be implemented to save space or save
 * time. Explore both possibilities.
 * ---
 * I'm actually not sure why this could be space or time efficient. My
 * `isupper_best`, while specific to ASCII, is O(1) on time and space.
 * ---
 * Some interesting discussion here:
 * http://clc-wiki.net/wiki/K%26R2_solutions:Chapter_7:Exercise_9
 */

static int isupper_best(const char c) { return 'A' <= c && c <= 'Z'; }

int main() {
  printf("%c: %d\n", 'c', isupper_best('c'));
  printf("%c: %d\n", 'A', isupper_best('A'));
  printf("%c: %d\n", 'D', isupper_best('D'));
  printf("%c: %d\n", 'Z', isupper_best('Z'));
  printf("%c: %d\n", '1', isupper_best('1'));
  printf("%c: %d\n", ' ', isupper_best(' '));
}
