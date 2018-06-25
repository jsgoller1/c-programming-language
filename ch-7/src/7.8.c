#include <stdio.h>

/*
 * Exercise 7-8. Write a program to print a set of files, starting each new one
 * on a new page, with a title and a running page count for each file.
 * ---------------------
 *
 */

#define PAGE_LEN 40
#define READ_SIZE 100

static int paged_print(char* path) {
  FILE* file;
  if ((file = fopen(path, "r")) == NULL) {
    printf("Cannot open %s.\n", path);
    perror("");
    return -1;
  }

  char line[READ_SIZE];
  int line_count = 0;
  int page_count = 1;
  while (fgets(line, READ_SIZE, file) != NULL) {
    if (line_count % PAGE_LEN == 0) {
      // print title and page number
      printf("\n%s\nPage: %d\n", path, page_count++);
    }
    printf("%s", line);
    line_count++;
  }
  if (fclose(file) == -1) {
    printf("Cannot close %s.\n", path);
    perror("");
    return -1;
  }
  return 0;
}

int main(int argc, char** argv) {
  if (argc < 1) {
    printf("usage: ./7.8 <file1> <file2> ...");
  }

  for (int i = 1; i < argc; i++) {
    if (paged_print(argv[i]) == -1) {
      return -1;
    }
  }
  return 0;
}
