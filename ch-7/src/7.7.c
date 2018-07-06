#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

#define MAXLINE 1000

static char* get_pattern_file(const char* const path) {
  FILE* file;
  char* pattern;
  int len;

  if ((file = fopen(path, "r")) == NULL) {
    return NULL;
  }

  if ((len = fseek(file, 0, SEEK_END)) < 1) {
    fclose(file);
    return NULL;
  } else {
    fseek(file, 0, SEEK_SET);
  }

  // sizeof not neccessary but good practice
  unsigned long size = (unsigned long)len * sizeof(char) + 1;
  if ((pattern = malloc(size)) == NULL) {
    fclose(file);
    return NULL;
  }

  if (fread(pattern, (unsigned long)len, 1, file) != (unsigned long)len) {
    free(pattern);
    fclose(file);
    return NULL;
  }
  pattern[len] = '\0';
  fclose(file);
  return pattern;
}

static char* parse_flags(int argc, char** argv, int* non_match,
                         int* show_line_nums) {
  char* pattern = NULL;
  char* current = NULL;

  if (argc < 3 || 5 < argc) {
    printf("Usage: find -x -n [-p pattern | -f path] \n");
    return NULL;
  }

  for (int i = 1; i < argc; i++) {
    current = argv[i];
    if (current[0] == '-') {
      switch (current[1]) {
        case 'x':
          *non_match = 1;
          break;
        case 'n':
          *show_line_nums = 1;
          break;
        case 'f':
          if (pattern == NULL) {
            pattern = get_pattern_file(argv[++i]);
          } else {
            printf("find: illegal option -f; pattern already set.\n");
            free(pattern);
            return NULL;
          }
          break;
        case 'p':
          if (pattern == NULL) {
            pattern = strdup(argv[++i]);
          } else {
            printf("find: illegal option -p; pattern already set.\n");
            free(pattern);
            return NULL;
          }
          break;
        default:
          printf("find: illegal option %c\n", current[1]);
          return NULL;
      }
    } else {
      printf("find: illegal argument: %s\n", current);
      return NULL;
    }
  }

  return pattern;
}

// find(): print lines that match pattern from 1st arg
int main(int argc, char** argv) {
  char line[MAXLINE] = {0};
  char* pattern = NULL;
  long lineno = 0;
  int non_match = 0, show_line_nums = 0;
  int found = 0;

  if ((pattern = parse_flags(argc, argv, &non_match, &show_line_nums)) ==
      NULL) {
    return -1;
  }

  while (mygetline(line, MAXLINE) > 0) {
    lineno++;
    if ((strstr(line, pattern) != NULL) != non_match) {
      if (show_line_nums) {
        printf("%ld: ", lineno);
      }
      printf("%s", line);
      found++;
    }
  }

  printf("Found: %d\n", found);
  free(pattern);
  return 0;
}
