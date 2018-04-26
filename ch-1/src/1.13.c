#include "1.13.h"
#include <stdio.h>

/*
Ex 1-9:  Write a program to print a histogram of words lengths in its input;
vertical is harder than horizontal.
*/

#define IN 1   // inside a word
#define OUT 0  // outside a word

void gather_inputs(int* words) {
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
  int curr_column, curr_row, more_rows;
  char hist_row[10];

  // Print the header
  for (i = 0; i < 9; i++) {
    printf("%4d", i + 1);
  }
  printf("%4d+\n", 10);

  // Print the actual rows
  curr_column = curr_row = 0;
  more_rows = 1;
  while (more_rows) {
    more_rows = 0;
    for (curr_column = 0; curr_column <= 9; curr_column++) {
      if (words[curr_column] > curr_row) {
        more_rows = 1;
        hist_row[curr_column] = 'X';
      } else {
        hist_row[curr_column] = ' ';
      }
    }
    ++curr_row;

    for (i = 0; i < 10; i++) {
      printf("%4c", hist_row[i]);
    }
    printf("\n");
  }
}

int main() {
  int words[10] = {0};  // Initializes all elements to zero

  gather_inputs(words);
  print_histogram(words);

  return 0;
}
