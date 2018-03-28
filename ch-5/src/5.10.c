#include <stdio.h>

/*
Write the program expr(), which evaluates a reverse polish expression from the
command line, where each operator and operand is a separate argument. For
example, "expr 2 3 4 + *" evaluates "2 x (3 + 4)".
*/

#define MAX_VALS 100

static vals_index = 0;
static int vals[MAX_VALS];

void push(int val) {}

int pop() {}

int is_number(char* num_string, int* val) { return 1; }

int main(int argc, char* argv[]) {
  for (int i = 1; i < argc; i++) {
    // TODO: do input sanitization, quit on invalid input
    char* current_arg = argv[argc];
    int arg_val;

    if (is_number(current_arg, &arg_val)) {
      push(arg_val);
    } else
      switch (*(argv[argc])) {
        case '+':
          // handle
          break;
        case '-':
          // handle
          break;
        case '/':
          // handle
          break;
        case '*':
          // handle
          break;
        default:
          printf("Error: invalid input: %s\n", *(argv[argc]));
          return -1;
      }
  }
  return 0;
}
