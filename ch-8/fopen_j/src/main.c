#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "fopen_j.h"

int main() {
  char string1[] = "abcdefghijklmnopqrstuvwxyz\0";
  // char string2[] = "124567890";
  // char result[100];

  char filename[] = "test.txt";
  char mode = 'a';
  FILE_J* file = fopen_j(filename, &mode);
  if (file == NULL) {
    printf("main() | File couldn't be opened.\n");
    return -1;
  }

  for (int i = 0; i < (int)strlen(string1); i++) {
    printf("writing %c\n", string1[i]);
    putc_j(file, string1[i]);
  }
  // print_buffer(file);
  fclose_j(file);

  /*
  file = fopen_j(filename, &mode);

  for (int i = 0; i < (int)strlen(string1); i++) {
    result[i] = getc_j(string1[i], file);
  }

  getc_j(contents1, 1, 10, file);
  fclose_j(file);
*/
}
