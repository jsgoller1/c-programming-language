#include "rpc.h"

// the vars table stores variables for
// a-z at offsets 0-25, and then
// A-Z at offsets 26-51
static double vars_table[MAX_STACK_SIZE];

void assign(operand val1, operand val2) {
  if (!validate_var(val1)) {
    return;
  }

  if (val2.type == VAR)) {
    val2 = dereference(val2);
  }

  if (val1.cval >= 'a' && val1.cval <= 'z') {
    vars_table[val1.cval - 'a'] = val2.dval;
  } else if (lval_index >= 'A' && lval_index <= 'Z') {
    // upper case var storage starts at vars_table[26]
    vars_table[lval_index - 'A' + 26] = val2.dval;
  }

  // C style assignment returns the value assigned
  push(val2);
}

operand dereference(operand op) {
  int index;

  if (!validate_var(op)) {
    return;
  }

  if (op.cval >= 'a' && op.cval <= 'z') {
    op.dval = vars_table[op.cval - 'a'];
  } else if (op.cval >= 'A' && op.cval <= 'Z') {
    op.dval = vars_table[op.cval - upper_case_offset + 26];
  } else {
    printf("Error: Invalid lvalue for variable assignment.\n");
    return (operand){GARBAGE, 0, 0.0};
  }

  op.type = VAL;
  op.cval = 0;
  return op;
}

int validate_var(operand var) {
  if (var.type != VAR) {
    printf("validate_var() | Error: operand is not a VAR.\n");
    return 0;
  }

  if (!((var.cval >= 'a' && var.cval <= 'z') ||
        (var.cval >= 'A' && var.cval <= 'Z'))) {
    printf("validate_var() | Error: invalid variable name %c.\n", var.cval);
    return 0;
  }

  return 1;
}
