#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/*
Ex. 5.10: Write the program expr(), which evaluates a reverse polish expression
from the command line, where each operator and operand is a separate argument.
For example, "expr 2 3 4 + *" evaluates "2 x (3 + 4)".
*/

#define MAX_SIZE 100

static int top = -1;
static int stack[MAX_SIZE];

static void push(const int val) {
  if (top >= MAX_SIZE - 1) {
    printf("Error: stack full, cannot push more values.\n");
  }
  stack[++top] = val;
}

static int pop(void) {
  int ret;
  if (top == -1) {
    printf("Error: stack empty.\n");
    return -1;
  }
  ret = stack[top--];
  return ret;
}

// to_number(): like atoi() but with better validation
static int to_number(const char* const num_string, int* const val) {
  for (int i = 0; num_string[i] != '\0'; i++) {
    if (!(isdigit(num_string[i]))) {
      return -1;
    }
  }
  *val = atoi(num_string);
  return 0;
}

int main(int argc, char* argv[]) {
  int op1, op2;
  for (int i = 1; i < argc; i++) {
    char* current_arg = argv[i];
    int arg_val;

    if (to_number(current_arg, &arg_val) == 0) {
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
