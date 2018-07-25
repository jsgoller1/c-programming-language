#include "rpc.h"

static int sp = 0;
static operand stack[MAX_STACK_SIZE];

// push() - push f onto value stack
int push(const operand op) {
  if (sp < MAX_STACK_SIZE) {
    stack[sp++] = op;
    return 0;
  } else {
    printf("Error; stack full.\n");
  }
}

// pop: return the top value/type pair from stack and decrement the stack
// pointer
operand pop(void) {
  if (sp == 0) {
    printf("Error: stack empty.\n");
    return (operand){GARBAGE, 0};
  } else if (sp < 1) {
    printf("Error: stack invalid.\n");
    return (operand){GARBAGE, 0};
  } else {
    return stack[sp--];
  }
}

// peek: return the top value/type pair from stack without decrementing sp;
operand peek(void) {
  if (sp == 0) {
    printf("Error: stack empty.\n");
    return (operand){GARBAGE, 0};
  } else if (sp < 1) {
    printf("Error: stack invalid.\n");
    return (operand){GARBAGE, 0};
  } else {
    return stack[sp];
  }
}

// duplicate_top: instructions were unclear, but assuming that
// this means add another element equal to the top element.
void duplicate_top() {
  operand top = {0, 0.0};

  pop(top);  // and the fun don't stop!
  push(top);
  push(top);
}

// swap_top: switch the top two elements of the stack
void swap_top() {
  // zero-initialize for -Werror=maybe-uninitialized
  operand top = {0, 0.0};
  operand second = {0, 0.0};

  pop(top);
  pop(second);
  push(top);
  push(second);
}

int get_stack_size() { return sp; }

void display() {
  operand op1 = {0, 0.0};

  // pop stack and display result, unless the
  // resultant expression is bad. If so, dump the stack.
  if (get_stack_size() != 1) {
    printf("Error: expression resulted in invalid computation.\n");
    sp = 0;
  } else {
    pop(op1);
    printf("%8.8g\n", op1[0]);
  }
}
