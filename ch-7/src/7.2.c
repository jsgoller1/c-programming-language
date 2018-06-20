#include <ctype.h>
#include <stdio.h>

/*
 * 7.2: Write a program that will print arbitrary input in a sensible way. As a
 * minimum, it should print non-graphic characters in octal or hexadecimal
 * according to local custom, and break long text lines.
 * ---
 * I was not sure what this question was asking, but after checking out two
 * solutions, I think the question is "print non-graphical characters in hex or
 * octal, and print everything else not-insanely". Nongraphical characters can
 * be found using iscntrl() in ctype.h, which will also catch blanks, the delete
 * character, and any chars less than octal 040.
 * */

int main() {
  int i = 1;
  int c = 0;
  while ((c = getchar()) != EOF) {
    if (iscntrl(c) && c != ' ' && c != '\n') {
      printf("Ox%x ", c);
      i += 7;  // advance to compensate for "0xFFFF " at most.
    } else {
      printf("%c", c);
      i++;
    }

    // break if line is larger than 80 chars
    if (i > 80) {
      putchar('\n');
      i = 0;
    }
  }
  return 0;
}
