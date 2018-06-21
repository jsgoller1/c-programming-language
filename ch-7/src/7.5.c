#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
/*
 * Ex. 7.5: Rewrite the postfix calculator of Chapter 4 to use scanf and/or
 * sscanf to do the input and number conversion.
 * ---
 * Because I rewrote the entire RPC calculator in chapter 4, I'm going to
 * re-write the version of it in chapter 5 (ex. 5.10) that takes expressions
 * from the CLI.
 */

#define MAX_SIZE 100

static int top = -1;
static int stack[MAX_SIZE];

static void push(int val) {
  if (top >= MAX_SIZE - 1) {
    printf("Error: stack full, cannot push more values.\n");
  }
  stack[++top] = val;
}

static int pop() {
  int ret;
  if (top == -1) {
    printf("Error: stack empty.\n");
    return -1;
  }
  ret = stack[top--];
  return ret;
}

static int is_number(char* num_string, int* val) {
  for (int i = 0; num_string[i] != '\0'; i++) {
    if (!(isdigit(num_string[i]))) {
      return 0;
    }
  }
  *val = atoi(num_string);
  return 1;
}

int main(int argc, char* argv[]) {
  int op1, op2;
  for (int i = 1; i < argc; i++) {
    char* current_arg = argv[i];
    int arg_val;

    if (is_number(current_arg, &arg_val)) {
      push(arg_val);
    } else {
      switch (*(current_arg)) {
        case '+':
          op1 = pop();
          op2 = pop();
          push(op1 + op2);
          break;
        case '-':
          op2 = pop();  // reverse order because - doesn't commute
          op1 = pop();
          push(op1 - op2);
          break;
        case '/':
          op2 = pop();  // reverse order because / doesn't commute
          op1 = pop();
          if (op2 == 0) {
            printf("Error: division by zero.\n");
            return -1;
          }
          push(op1 / op2);
          break;
        case '*':
          op1 = pop();
          op2 = pop();
          push(op1 * op2);
          break;
        default:
          printf("Error: invalid input: %s\n", argv[argc]);
          printf("Usage: expr <rpn expression using +,*,-,/.\n");
          return -1;
      }
    }
  }
  if (top != 0) {
    printf("Error: invalid expression.\n");
    printf("Usage: expr <rpn expression using +,*,-,/.\n");
  } else {
    printf("Result: %d\n", pop());
  }
  return 0;
}
