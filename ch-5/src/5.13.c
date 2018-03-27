#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "5-common.h"

/*
Exercise 5-13. Write the program tail, which prints the last n lines of its
input. By default, n is 10, let us say, but it can be changed by an optional
argument, so that
tail -n
prints the last n lines. The program should behave rationally no matter how
unreasonable the input or the value of n. Write the program so it makes the
best use of available storage; lines should be stored as in the sorting program
of Section 5.6, not in a two-dimensional array of fixed size.
*/

// the maximum character count of a line given to tail()
#define MAXLINE 1000

// tail(): print the last n lines from input
int main(int argc, char* argv[]) {
  printf("%d\n", argc);
  int line_num = 0;
  if (argc == 1) {
    line_num = 10;
  }
  // If we get more than 1 arg, ensure that arg 2 is "-n" and arg 3 is a valid
  // number
  else if (argc == 3 && !(strncmp(argv[1], "-n", 2))) {
    char c;
    for (int i = 0; (c = argv[2][i]) != '\0'; i++) {
      if (!(isdigit(c))) {
        printf("usage: tail -n <line count>\n");
        return -1;
      }
    }
    line_num = atoi(argv[2]);
  } else {
    printf("usage: tail -n <line count>\n");
    return -1;
  }

  // begin reading lines in; temporarily
  // store lines in the temp_line buffer and
  // copy them out to actual heap lines, and
  // push those into a queue of lines that will be printed at the end.
  char* lines[line_num];
  char temp_line[MAXLINE];

  return 0;
}
