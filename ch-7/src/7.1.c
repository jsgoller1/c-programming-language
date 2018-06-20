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

// static char* resize_string() {}

static char* parse_string() {
  int i = 0;
  int c = 0;
  char* string = (char*)calloc(1, 100);  // TODO: resize if too small
  while ((c = getchar()) != EOF) {
    string[i++] = (char)c;
  }
  return string;
}

int main(int argc, char** argv) {
  /*
    printf("argc: %d\n", argc);
    for (int i = 0; i < argc; i++) {
      printf("arg %d: %s\n", i, argv[i]);
    }
  */

  char* case_flag;
  char* in_string;
  bool alloc = false;

  switch (argc) {
    case 2:
      alloc = true;
      in_string = parse_string();
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

  if (strcmp("-u", case_flag) == 0) {
    for (size_t i = 0; i < strlen(in_string); i++) {
      putchar(toupper(in_string[i]));
    }
  } else if (strcmp("-l", case_flag) == 0) {
    for (size_t i = 0; i < strlen(in_string); i++) {
      putchar(tolower(in_string[i]));
    }
  } else {
    printf("usage: caser -[ul] <string>\n");
    return -1;
  }
  putchar('\n');

  if (alloc) {
    free(in_string);
  }

  return 0;
}
