#include "1.11.h"
#include <stdio.h>
#include <string.h>
#include "common.h"
#include "tests.h"

/*
 * Ex 1.11: How would you test the 1.5.4 word count program?
 * ---
 * 1) I have rewritten the program so that the code
 * that does the word counting in encapsulated in its own
 * function that is const correct and I/O ignorant. This should
 * isolate bugs to just logical errors in the function.
 * 2) I have written a test case that cover every line of word_count().
 * This ensures that there are no completely untested parts of the program.
 * 3) I have written a few different tests to try to find edge cases that I
 * speculate may cause the program to behave unpredictably.
 */

#define IN 1   // inside a word
#define OUT 0  // outside a word

static void test(const char* const input, const int lines, const int words,
                 const int chars, const char* const message) {
#ifdef TEST_MESSAGES
  printf("TEST: %s...\n", message);
#endif
  counter counts = {0, 0, 0};
  word_count(input, (int)strlen(input), &counts);
#ifdef DEBUG
  printf("%s\nlines: %d, words: %d, chars: %d\n", input, counts.lines,
         counts.words, counts.chars);
#else
  (void)message;
#endif
  assert_int_eq(lines, counts.lines);
  assert_int_eq(words, counts.words);
  assert_int_eq(chars, counts.chars);
}

int main() {
  // Covers all 3 branches
  printf("1.11: Running tests...\n");
  test("this\t has many words\n and several lines.\n", 3, 7, 41,
       "expected input");
  test("", 0, 0, 0, "edge case: empty string");
  test("   \t\n\t  \n  \t", 3, 0, 12, "edge case: all spacing chars");
  printf("1.11: PASS!\n");
  return 0;
}

// word_count(): count lines, words and characters in input
void word_count(const char* const input, const int len, counter* const counts) {
  int c = 0, state = 0;
  state = OUT;

  // We don't know if the counter is initialized; assume it's not
  counts->lines = 0;
  counts->words = 0;
  counts->chars = 0;

  // A no-character string is 0 lines; all others are at least one.
  if (len == 0) {
    return;
  } else {
    counts->lines++;
  }

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
