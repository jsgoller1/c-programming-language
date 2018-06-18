#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "fopen_j.h"

static void debug_read(FILE_J* file, char* string, int len) {
  for (int i = 0; i < len; i++) {
    // printf("debug_read() | reading %c to file\n", string[i]);
    string[i] = (char)getc_j(file);
    // if (!(i % 5)) {
    // printf("Halting til input.\n");
    // getchar();
  }
}

static void debug_write(FILE_J* file, char* string) {
  for (int i = 0; i < (int)strlen(string); i++) {
    // printf("debug_write() | writing %c\n", string[i]);
    putc_j(file, string[i]);
    // if (!(i % 5)) {
    // printf("Halting til input.\n");
    // getchar();
  }
}

int main() {
  char result[100] = {0};

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
  debug_write(file, strings[0]);
  fseek_j(file, 0, SEEK_SET);
  debug_read(file, result, 26);
  printf("main() | wrote %s to file.\nmain() | Read %s\n\n", strings[0],
         result);
  fseek_j(file, 0, SEEK_SET);
  debug_write(file, strings[1]);
  fseek_j(file, 0, SEEK_SET);
  fflush_j(file);
  fflush_j(file);
  debug_read(file, result, 26);
  printf("main() | wrote %s to file.\nmain() | Read %s\n\n", strings[1],
         result);

  fclose_j(file);
}
