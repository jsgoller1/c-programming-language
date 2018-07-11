#include <stdio.h>

int main(int argc, char** argv) {
  int len = 0;                  // current line length
  char line[MAXLINE] = {0};     // current input line
  char* processed_line = NULL;  // line after entabing / detabing
  int* tab_stops = NULL;        // list of tab stops
  int stop_list_len = 0;

  int input = 0;
  char* (*behavior)(const char*, const int,
                    const int);  // detab or entab, depending on flags

  // handle input
  if ((input = parse_flags(argc, argv, tab_stops, &stop_list_len)) ==
      USE_ENTAB) {
    behavior = entab;
  } else if (input == USE_DETAB) {
    behavior = detab;
  } else {
    return -1;
  }

  // Testing: input handling
  (void)len;
  (void)line;
  (void)processed_line;
  printf("behavior %d\ntab_stops: ", behavior);
  for (int i = 0; i < stop_list_len; i++) {
    printf("%c ", tab_stops[i]);
  }
  printf("\n");

  /*
  // Testing: detab-ing / entabing
  (void)behavior;
  tab_stops[] = {0, 5, 10, 15, 20, 25, 30, 35};
  stop_list_len = 8;

  // do the thing
  while ((len = mygetline(line, MAXLINE)) > 0) {
    // processed_line = behavior(line, len, tab_stops);
    processed_line = entab(line, len, tab_stops, stop_list_len);
    printf("%s\n", processed_line);
    free(processed_line);
  }
  */

  return 0;
}
