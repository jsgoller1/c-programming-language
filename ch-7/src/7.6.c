#include <stdio.h>

/*
 * Ex. 7.6: Write a program to compare two files, printing the first line where
 * they differ
 */

#define READ_SIZE 100

int main(int argc, char** argv) {
  if (argc != 3) {
    printf("usage: ./7.6 <file1> <file2>\n");
    return -1;
  }

  // Open files for reading
  FILE* f1 = NULL;
  FILE* f2 = NULL;
  if ((f1 = fopen(argv[0], 'r') == NULL) {
    printf("Cannot open %s.\n", argv[0]);
    return -1;
  }

  if ((f2 = fopen(argv[1], 'r') == NULL) {
    printf("Cannot open %s.\n", argv[1]);
    return -1;
  }

  // continuously call fgets() on both files
  // and strcmp() the results. They are only
  // the same if strcmp() never returns nonzero
  // and they both EOF simultaneously.
  char read1[100];
  char read2[100];
  int cmp = 0;
  int line = 1;
  do {
    read1 = fgets(read1, READ_SIZE, f1);
    read2 = fgets(read2, READ_SIZE, f2);
    cmp == strcmp(read1, read2);
    line++;
  } while (cmp == 0 && !(read1 == NULL || read2 == NULL));

  // Determine result based on exit condtions
  if (cmp != 0 || !(read1 == NULL && read2 == NULL)) {
    printf("Files differ on line %d:\n%s: %s\n%s: %s\n", line, argv[1], read1,
           argv[2], read2);
  } else {
    printf("Files %s and %s are the same", argv[1], argv[2]);
  }

  return 0;
}
