#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Write a program that converts upper case to lower
 * or lower case to upper, depending on the name it
 * is invoked with, as found in argv[0].
 * ---
 * If there's only 2 args (i.e. piped), get input from stdin
 */

// read_stdin(): helper function if program
// is called with piped input. Will not
// work if input is too large.
static char* read_stdin() {
  int i = 0;
  int c = 0;
  char* string = (char*)calloc(1, 1000);
  while ((c = getchar()) != EOF) {
    string[i++] = (char)c;
  }
  return string;
}

// main(): solves exercise
int main(int argc, char** argv) {
  char* case_flag = NULL;
  char* in_string = NULL;
  bool alloc = false;

  // set vars based on cli args;
  // read from stdin if we are piping
  switch (argc) {
    case 2:
      alloc = true;
      in_string = read_stdin();
      case_flag = argv[1];
      break;
    case 3:
      case_flag = argv[1];
      in_string = argv[2];
      break;
    default:
      printf("usage: caser -[ul] <string>\n");
      return -1;
  }

  // Transform string based on args
  if (strcmp("-u", case_flag) == 0) {
    for (size_t i = 0; i < strlen(in_string); i++) {
      putchar(toupper(in_string[i]));
    }
  } else if (strcmp("-l", case_flag) == 0) {
    for (size_t i = 0; i < strlen(in_string); i++) {
      putchar(tolower(in_string[i]));
    }
  } else {
    if (alloc) {
      free(in_string);
    }
    printf("usage: caser -[ul] <string>\n");
    return -1;
  }
  putchar('\n');

  if (alloc) {
    free(in_string);
  }

  return 0;
}
