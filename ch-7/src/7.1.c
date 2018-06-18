#include <ctype.h>
#include <stdio.h>
#include <string.h>

/* Write a program that converts upper case to lower
 * or lower case to upper, depending on the name it
 * is invoked with, as found in argv[0].
 */

int main(int argc, char** argv) {
  if (argc < 1) {
    printf("usage: caser -[ul] <string>");
    return -1;
  }

  char* case_flag = argv[1];
  char* in_string = argv[2];

  if (strcmp("-u", case_flag)) {
    for (size_t i = 0; i < strlen(in_string); i++) {
      putchar(toupper(in_string[i]));
    }
  } else if (strcmp("-l", case_flag)) {
    for (size_t i = 0; i < strlen(in_string); i++) {
      putchar(tolower(in_string[i]));
    }
  } else {
    printf("usage: caser -[ul] <string>");
    return -1;
  }
  return 0;
}
