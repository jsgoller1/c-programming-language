#include "1.24.h"
#include <stdio.h>

/*
Ex 1.24: Write a program to check a C program for rudimentary syntax
errors like unbalanced parentheses, brackets and braces. Don't forget about
quotes, both single and double, escape sequences, and comments. (This
program is hard if you do it in full generality.)
----
At the time of publication, "comments" technically meant only C-style
comments, i.e. the type this text is in, but I did both here.
*/

#define IN_SINGLE_COMMENT 0x1
#define IN_MULTI_COMMENT 0x2
#define IN_SINGLE_QUOTE 0x4
#define IN_MULTI_QUOTE 0x8

int main() {
  int c = 0;
  // parsing_state ps = {0, 0, 0, 0, 0};
  char parsing_flags = 0;
  input_registry ir = {0, 0, 0, 0, 0, 0};

  while ((c = getchar()) != EOF) {
    parsing_test(c, parsing_flags);
    if (!(parsing_flags)) {
      input_test(c, &ir);
    }
  }
  print_output(&ir);
  return 0;
}

void parsing_test(const int c1, char parsing_flags) {
  int c2 = 0;

  // Test for beginning of single or multi comment
  if (c1 == '/') {
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
  }
  ps->should_parse = !(ps->in_single_comment || ps->in_multi_comment ||
                       ps->in_single_quote || ps->in_multi_comment);
}

void input_test(const int c1, input_registry* const ir) {
  switch (c1) {
    case '/':
      ir->comment_braces++;
      break;
    case '"':
      ir->quotes++;
      break;
    case '\'':
      ir->ticks++;
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

void print_output(const input_registry* const ir) {
  if ((ir->quotes % 2) != 0) {
    printf("Program has mismatched closing/opening double quotes.\n");
  } else if ((ir->ticks % 2) != 0) {
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
