#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "fopen_j.h"

// debug_read(); reads len characters from file to str,
// with useful segment for interrupting on a regular interval
static void debug_read(FILE_J* file, char* string, int len) {
  for (int i = 0; i < len; i++) {
    string[i] = (char)getc_j(file);
    // if (!(i % 5)) {
    //  printf("Halting til input at %lu.\n", lseek(file->fd, 0, SEEK_CUR));
    //  print_buffer(file);
    //  getchar();
    //}
  }
}

// debug_write(); writes string to file with useful
// segment for interrupting on a regular interval
static void debug_write(FILE_J* file, char* string) {
  for (int i = 0; i < (int)strlen(string); i++) {
    putc_j(file, string[i]);
    //    if (!(i % 5)) {
    //      printf("Halting til input at %lu.\n", lseek(file->fd, 0, SEEK_CUR));
    //      print_buffer(file);
    //      getchar();
    //  }
  }
}

int main() {
  char* strings[] = {"abcdefghijklmnopqrstuvwxyz\0",
                     "AAAAAAAAAAAAAAAAAAAAAAAAAA\0",
                     "BBBBBBBBBBBBBBBBBBBBBBBBBB\0"};
  char result[100] = {0};

  // open the file
  char filename[] = "test.txt";
  char mode = 'a';
  FILE_J* file = fopen_j(filename, &mode);
  if (file == NULL) {
    printf("main() | File couldn't be opened.\n");
    return -1;
  }

  // write first string, seek back, read, print
  debug_write(file, strings[0]);
  fseek_j(file, 0, SEEK_SET);
  debug_read(file, result, 26);
  printf("main() | Wrote %s to file.\nmain() | Read  %s from file.\n\n",
         strings[0], result);

  // write second string at start, seek back to start,
  // and read it out again. Call flush frequently to
  // ensure it has no impact on normal program execution.
  fseek_j(file, 0, SEEK_SET);
  fflush_j(file);
  debug_write(file, strings[1]);
  fflush_j(file);
  fseek_j(file, 0, SEEK_SET);
  fflush_j(file);
  debug_read(file, result, 26);
  fflush_j(file);
  printf("main() | Wrote %s to file.\nmain() | Read  %s from file.\n\n",
         strings[1], result);

  fclose_j(file);
}
