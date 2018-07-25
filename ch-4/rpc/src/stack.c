#include "rpc.h"

static int sp = -1;
static operand stack[MAX_STACK_SIZE];

// push() - push f onto value stack
int push(const operand op) {
  if (sp < MAX_STACK_SIZE) {
    stack[++sp] = op;
    return 0;
  } else {
    printf("Error; stack full.\n");
    return -1;
  }
}

// pop: return the top value/type pair from stack and decrement the stack
// pointer
operand pop(void) {
  if (sp == -1) {
    printf("Error: stack empty.\n");
    return (operand){GARBAGE, 0, 0.0};
  } else if (sp < -1) {
    printf("Error: stack invalid.\n");
    return (operand){GARBAGE, 0, 0.0};
  } else {
    return stack[sp--];
  }
}

// peek: return the top value/type pair from stack without decrementing sp;
operand peek(void) {
  if (sp == -1) {
    printf("Error: stack empty.\n");
    return (operand){GARBAGE, 0, 0.0};
  } else if (sp < -1) {
    printf("Error: stack invalid.\n");
    return (operand){GARBAGE, 0, 0.0};
  } else {
    return stack[sp];
  }
}

// duplicate_top: instructions were unclear, but assuming that
// this means add another element equal to the top element.
void duplicate_top() {
  operand top = pop();
  push(top);
  push(top);
}

// swap_top: switch the top two elements of the stack
void swap_top() {
  // zero-initialize for -Werror=maybe-uninitialized
  operand top = pop();
  operand second = pop();

  push(top);
  push(second);
}

int get_stack_top() { return sp; }
