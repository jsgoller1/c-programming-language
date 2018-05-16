#include "5.13.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

/*
 * Exercise 5-13. Write the program tail, which prints the last n lines of its
 * input. By default, n is 10, let us say, but it can be changed by an optional
 * argument, so that tail -n prints the last n lines. The program should behave
 * rationally no matter how unreasonable the input or the value of n. Write the
 * program so it makes the best use of available storage; lines should be stored
 * as in the sorting program of Section 5.6, not in a two-dimensional array of
 * fixed size.
 * ----------------------------------
 * We will use a queue, and automatically free the nodes exceeding n.
 */

// tail(): print the last n lines from input
int main(int argc, char** argv) {
  int line_num;
  if (!(line_num = check_input(argc, (const char* const*)argv))) {
    return -1;
  }

  printf("n lines: %d\n", line_num);

  // char* lines[line_num];
  // char temp_line[MAXLINE];

  return 0;
}

int check_input(const int argc, const char* const* const argv) {
  // if -n is not given, default to 10
  if (argc == 1) {
    return 10;
  }
  // If we get more than 1 arg, ensure that arg 2
  // is "-n" and arg 3 is a valid number, then return
  // arg3 as an int.
  else if (argc == 3 && !(strncmp(argv[1], "-n", 2))) {
    const char* const count = argv[2];
    const int arg_size = (int)strlen(count);

    for (int i = 0; i < arg_size; i++) {
      if (!(isdigit(count[i]))) {
        printf("usage: tail -n <line count>\n");
        return -1;
      }
    }
    return (int)atoi(argv[2]);
  } else {
    printf("usage: tail -n <line count>\n");
    return -1;
  }
}
