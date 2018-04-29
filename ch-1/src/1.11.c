#include "1.11.h"
#include <stdio.h>
#include <string.h>
#include "common.h"

/*
Ex 1.11: How would you test the 1.5.4 word count program?
---
1) I have rewritten the program so that the code
that does the word counting in encapsulated in its own
function that is const correct and I/O ignorant. This should
isolate bugs to just logical errors in the function.
2) I have written a test case that cover every line of word_count().
This ensures that there are no completely untested parts of the program.
3) I have written a few different tests to try to find edge cases that I
speculate may cause the program to behave unpredictably.
*/

#define IN 1   // inside a word
#define OUT 0  // outside a word

int main() {
  // Covers all 3 branches
  test_case("this\t has many words\n and several lines.\n");

  // Edge case - no input
  test_case("");

  // Edge case - all spacing characters
  test_case("   \t\n\t  \n  \t");

  // Edge case - mid-word spacing characters
  test_case("two\twords");
  return 0;
}

void test_case(const char* const input) {
  counter counts = {0, 0, 0};
  word_count(input, (int)strlen(input), &counts);
  printf("%s\nlines: %d, words: %d, chars: %d\n", input, counts.lines,
         counts.words, counts.chars);
}

// word_count(): count lines, words and characters in input
void word_count(const char* const input, const int len, counter* const counts) {
  int c = 0, state = 0;
  state = OUT;
  for (int i = 0; i < len; i++) {
    c = input[i];
    ++(counts->chars);
    if (c == '\n') {
      ++(counts->lines);
    }
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
    } else if (state == OUT) {
      state = IN;
      ++(counts->words);
    }
  }
}
