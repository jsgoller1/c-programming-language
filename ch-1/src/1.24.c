#include "1.24.h"
#include <stdio.h>

/*
 * Ex 1.24: Write a program to check a C program for rudimentary syntax
 * errors like unbalanced parentheses, brackets and braces. Don't forget about
 * quotes, both single and double, escape sequences, and comments. (This
 * program is hard if you do it in full generality.)
 * ----
 * At the time of publication, "comments" technically meant only C-style
 * comments, i.e. the type this text is in, but I did both here.
 */

int main() {
  int c = 0;
  parsing_state ps = {0, 0, 0, 0, 0};
  input_registry ir = {0, 0, 0, 0};

  while ((c = getchar()) != EOF) {
    parsing_test(c, &ps);
    if (ps.should_parse) {
      input_test(c, &ir);
    }
  }
  print_output(&ir, &ps);
  return 0;
}

// parsing_test(): A nasty function with a lot of nested
// logic to determine if we should count any of the symbols
// we read in; implements a simple FSM for parsing.
void parsing_test(const int c1, parsing_state* const ps) {
  int c2 = 0;

  // Test for beginning of single or multi comment
  if (c1 == '/' && !(ps->in_single_quote || ps->in_double_quote)) {
    c2 = getchar();
    if (c2 == '*' && ps->in_multi_comment == 0) {
      ps->in_multi_comment = 1;
    } else if (c2 == '/' && ps->in_multi_comment == 0) {
      ps->in_single_comment = 1;
    } else {
      ungetc(c2, stdin);
    }
  }  // test for ending of a multi comment
  else if (c1 == '*' && ps->in_multi_comment == 1) {
    c2 = getchar();
    if (c2 == '/') {
      ps->in_multi_comment = 0;
    } else {
      ungetc(c2, stdin);
    }
  }  // exit a single line comment
  else if (c1 == '\n') {
    ps->in_single_comment = 0;
  }  // enter or exit a single-tick quote
  else if (c1 == '\'' && !(ps->in_single_comment || ps->in_multi_comment ||
                           ps->in_double_quote)) {
    ps->in_single_quote = ~(ps->in_single_quote);
  }  // enter or exit a double-tick quote
  else if (c1 == '\"' && !(ps->in_single_comment || ps->in_multi_comment ||
                           ps->in_single_quote)) {
    ps->in_double_quote = ~(ps->in_double_quote);
  }

  // combine all flags to determine if parsing should occur
  ps->should_parse = !(ps->in_single_comment || ps->in_multi_comment ||
                       ps->in_single_quote || ps->in_multi_comment);
}

// input_test(): keeps track of what syntactically relevant characters
// we've observed
void input_test(const int c1, input_registry* const ir) {
  switch (c1) {
    case '/':
      ir->comment_braces++;
      break;
    case '(':
      ir->parens++;
      break;
    case ')':
      ir->parens--;
      break;
    case '{':
      ir->curlys++;
      break;
    case '}':
      ir->curlys--;
      break;
    case '[':
      ir->squares++;
      break;
    case ']':
      ir->squares--;
      break;
  }
}

// print_output(): print whether our C program is kosher or not.
void print_output(const input_registry* const ir,
                  const parsing_state* const ps) {
  if (ps->in_double_quote) {
    printf("Program has mismatched closing/opening double quotes.\n");
  } else if (ps->in_single_quote) {
    printf("Program has mismatched closing/opening single-ticks.\n");
  } else if (ir->parens) {
    printf("Program has mismatched parens.\n");
  } else if (ir->curlys) {
    printf("Program has mismatched curly braces.\n");
  } else if (ir->squares) {
    printf("Program has mismatched square braces.\n");
  } else {
    printf("Program is possibly correct.\n");
  }
}
