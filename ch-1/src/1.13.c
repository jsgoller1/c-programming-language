#include "1.13.h"
#include <stdio.h>

/*
Ex 1.13:  Write a program to print a histogram of words lengths in its input;
vertical is harder than horizontal.
*/

#define IN 1   // inside a word
#define OUT 0  // outside a word

void get_words(int* words) {
  int i, c, word_length, state;
  i = c = word_length = 0;
  state = OUT;

  printf("Begin typing, terminate via ctrl-D on an empty line.\n");
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
      if (word_length >= 10) {
        words[9]++;
      } else if (word_length >= 1) {
        words[word_length - 1]++;
        word_length = 0;
      }
    } else if (state == OUT)
      state = IN;
    if (state == IN) ++word_length;
  }
  if (state == IN) {  // catches edge case where user hits CTRL-D mid-word.
    words[word_length - 1]++;
  }
}

void print_histogram(int* words) {
  int i = 0;
  int curr_column, more_rows;

  // Print the header
  for (i = 0; i < 9; i++) {
    printf("%4d", i + 1);
  }
  printf("%4d+\n", 10);

  // Print the actual rows; decrement
  // each nonzero entry in words[] and print
  // spaced X characters until all entries are zero
  curr_column = 0;
  more_rows = 1;
  while (more_rows) {
    more_rows = 0;
    for (curr_column = 0; curr_column < 10; curr_column++) {
      if (words[curr_column] != 0) {
        more_rows = 1;
        printf("%4c", 'X');
        words[curr_column]--;
      } else {
        printf("%4c", ' ');
      }
    }
    printf("\n");
  }
}

int main() {
  int words[10] = {0};  // Initializes all elements to zero

  get_words(words);
  print_histogram(words);

  return 0;
}
