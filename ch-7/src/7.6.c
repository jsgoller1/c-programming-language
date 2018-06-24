#include <stdio.h>
#include <string.h>

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
  if ((f1 = fopen(argv[1], "r")) == NULL) {
    printf("Cannot open %s.\n", argv[0]);
    perror("");
    return -1;
  }

  if ((f2 = fopen(argv[2], "r")) == NULL) {
    printf("Cannot open %s.\n", argv[1]);
    perror("");
    return -1;
  }

  // continuously call fgets() on both files
  // and strcmp() the results. They are only
  // the same if strcmp() never returns nonzero
  // and they both EOF simultaneously.
  char read1[READ_SIZE] = {0};
  char read2[READ_SIZE] = {0};
  char* ret1;
  char* ret2;
  int cmp = 0;
  int line = 0;
  do {
    ret1 = fgets(read1, READ_SIZE, f1);
    ret2 = fgets(read2, READ_SIZE, f2);
    cmp = strcmp(read1, read2);
    line++;
  } while (cmp == 0 && !(ret1 == NULL || ret2 == NULL));

  // Determine result based on exit condtions
  if (ret1 != NULL && ret2 == NULL) {
    printf("%s is longer than %s\n", argv[1], argv[2]);
  } else if (ret1 == NULL && ret2 != NULL) {
    printf("%s is longer than %s\n", argv[2], argv[1]);
  } else if (cmp != 0) {
    printf("Files differ on line %d:\n%s: %s%s: %s", line, argv[1], read1,
           argv[2], read2);
  } else {
    printf("Files %s and %s are the same.\n", argv[1], argv[2]);
  }

  return 0;
}
