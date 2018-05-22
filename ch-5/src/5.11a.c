#include "5.11a.h"
#include <stdio.h>
#include <string.h>
#include "common.h"
#include "tests.h"

/*
 * Exercise 5-11. Modify the programs entab and detab (written as exercises in
 * Chapter 1) to accept a list of tab stops as arguments. Use the default tab
 * settings if there are no arguments,
 * -----
 * This one will do entab().
 */

#define TAB_CHAR '$'

static void test(const char* const in_string, const int* const tab_stops,
                 const int num_stops, const char* const expected,
                 const char* const message) {
  const int len = strlen(in_string);
  char* actual = entab(in_string, len, tab_stops, num_stops);
  assert_string_eq(actual, expected, "entab", message);
  free(actual);
}

int main(int argc, char** argv) {}

// entab(): given a string of len, return it with all whitespaces of a given
// length replaced by tabs (represented by "$" for clarity)
char* entab(const char* const in_line, const int in_len, const int* tab_stops,
            const int num_stops) {
  char* out_line = {""};
  int i = 0, j = 0, next_stop = 0;
  char temp[MAXLINE] = {0};
  int tab_stop;

  // Copy char by char til we get a whitespace; if so,
  // look_ahead() to see if we can entab - do so if possible,
  // otherwise just copy the char.
  for (j = i = 0; i < in_len; i++) {
    if (in_line[i] == ' ') {
      // if we are past the final stop, default to the end of the string
      if ((tab_stop = get_next_tabstop(tab_stops, num_stops, i) == -1)) {
        tab_stop = in_len - 1;
      }
      if ((next_stop = look_ahead(in_line, in_len, i, tab_stop))) {
        temp[j] = TAB_CHAR;
        j++;
        i = next_stop - 1;
      } else {
        temp[j] = in_line[i];
        j++;
      };
    } else {
      temp[j] = in_line[i];
      j++;
    }
  }
  temp[j] = '\0';

  out_line = (char*)malloc((unsigned long)j + 1);
  strncpy(out_line, temp, (unsigned long)j + 1);
  return out_line;
}

/*
 * look_ahead(): given string in_line of length in_len, determine if
 * the characters between in_line[offset] and the nearest tab_stop are
 * all whitespaces. If they are, return the next tab stop's offset; otherwise,
 * return 0.
 */
int look_ahead(const char* const in_line, const int in_len, int offset,
               const int tab_stop) {
  int next_stop;

  next_stop = offset + (tab_stop - (offset % tab_stop));

  // Quit if we try to read past the buffer
  if (next_stop > in_len) {
    return 0;
  }
  for (; offset < next_stop; offset++) {
    if (in_line[offset] != ' ') {
      return 0;
    }
  }
  return next_stop;
}

int get_next_tabstop(const int* const tab_stops, const int num_stops,
                     const int current_char) {
  int tab_stop = -1;

  for (int i = 0; i < num_stops; i++) {
    if (current_char <= tab_stops[i]) {
      return tab_stops[i];
    }
  }

  return -1;
}
