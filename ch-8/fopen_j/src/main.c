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
  char string2[] = "AAAAAAAAAAAAAAAAAAAAAAAAAA\0";
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

  fseek_j(file, 0, SEEK_SET);

  for (int i = 0; i < (int)strlen(string2); i++) {
    printf("writing %c\n", string2[i]);
    putc_j(file, string2[i]);
  }

  fclose_j(file);
}
