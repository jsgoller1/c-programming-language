#include "1.14.h"
#include <ctype.h>
#include <stdio.h>

/*
Ex 1.14:  Write a program to print a histogram
of the frequencies of different characters in its input.
*/

int main() {
#ifdef DEBUG
  int char_counts[26] = {0};  // Initializes all elements to zero
  char characters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                         'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                         's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  get_chars(char_counts);
  print_histogram(characters, char_counts);
#else
  printf("1.14: No unit tests.\n");
#endif
  return 0;
}

// get_chars(): reads character-by-character input until EOF from stdin
void get_chars(int* const char_counts) {
  int i, c, word_length;
  i = c = word_length = 0;

  printf("Begin typing, terminate via ctrl-D on an empty line.\n");
  while ((c = getchar()) != EOF) {
    if (c >= 'a' && c <= 'z') {
      char_counts[c - 'a']++;
    } else if (c >= 'A' && c <= 'Z') {
      char_counts[tolower(c) - 'a']++;
    }
  }
}

// print_histogram(): prints a histogram of character frequencies from
// array args.
void print_histogram(const char* const characters, int* const char_counts) {
  int i = 0;
  int curr_column, more_rows;

  // Print the header
  for (i = 0; i < 26; i++) {
    printf("%4c", characters[i]);
  }
  printf("\n");

  // Print the actual rows; decrement
  // each nonzero entry in words[] and print
  // spaced X characters until all entries are zero
  more_rows = 1;
  while (more_rows) {
    more_rows = 0;
    for (curr_column = 0; curr_column < 26; curr_column++) {
      if (char_counts[curr_column] != 0) {
        more_rows = 1;
        printf("%4c", 'X');
        char_counts[curr_column]--;
      } else {
        printf("%4c", ' ');
      }
    }
    printf("\n");
  }
}
