#include <stdio.h>

int main(int argc, char** argv) {
  int len = 0;                  // current line length
  char line[MAXLINE] = {0};     // current input line
  char* processed_line = NULL;  // line after entabing / detabing
  int* tab_stops = NULL;        // list of tab stops
  int input = 0;
  char* (*behavior)(const char*, const int,
                    const int);  // detab or entab, depending on flags

  // handle input
  if ((input = parse_flags(argc, argv)) == USE_ENTAB) {
    behavior = entab;
  } else if (input == USE_DETAB) {
    behavior = detab;
  } else {
    return -1;
  }

  // do the thing
  while ((len = mygetline(line, MAXLINE)) > 0) {
    processed_line = behavior(line, len, TAB_STOPS);
    printf("%s\n", processed_line);
    free(processed_line);
  }

  return 0;
}
