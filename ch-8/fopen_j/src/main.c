#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "fopen_j.h"

static void breakwrite(FILE_J* file, char* string) {
  for (int i = 0; i < (int)strlen(string); i++) {
    printf("writing %c\n", string[i]);
    putc_j(file, string[i]);
    if (!(i % 5)) {
      // printf("Halting til input.\n");
      // getchar();
      // print_buffer(file);
    }
  }
}

int main() {
  // char result[100];

  char filename[] = "test.txt";
  char mode = 'a';
  char* strings[] = {"abcdefghijklmnopqrstuvwxyz\0",
                     "AAAAAAAAAAAAAAAAAAAAAAAAAA\0",
                     "BBBBBBBBBBBBBBBBBBBBBBBBBB\0"};
  FILE_J* file = fopen_j(filename, &mode);
  if (file == NULL) {
    printf("main() | File couldn't be opened.\n");
    return -1;
  }
  breakwrite(file, strings[0]);

  fseek_j(file, 0, SEEK_SET);

  // breakwrite(file, strings[1]);

  // fseek_j(file, 27, SEEK_SET);
  // breakwrite(file, strings[2]);

  fclose_j(file);
}
