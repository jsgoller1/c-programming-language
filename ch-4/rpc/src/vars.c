#include "rpc.h"

// the vars table stores variables for
// a-z at offsets 0-25, and then
// A-Z at offsets 26-51
static double vars_table[MAX_STACK_SIZE];

void assign(operand val1, operand val2) {
  if (!validate_var(val1)) {
    return;
  }

  if (val2.type == VAR) {
    val2 = dereference(val2);
  }

  if (val1.cvalue >= 'a' && val1.cvalue <= 'z') {
    vars_table[val1.cvalue - 'a'] = val2.dvalue;
  } else if (val1.cvalue >= 'A' && val1.cvalue <= 'Z') {
    // upper case var storage starts at vars_table[26]
    vars_table[val1.cvalue - 'A' + 26] = val2.dvalue;
  }

  // C style assignment returns the value assigned
  push(val2);
}

operand dereference(operand op) {
  if (!validate_var(op)) {
    return (operand){GARBAGE, 0, 0.0};
  }

  if (op.cvalue >= 'a' && op.cvalue <= 'z') {
    op.dvalue = vars_table[op.cvalue - 'a'];
  } else if (op.cvalue >= 'A' && op.cvalue <= 'Z') {
    op.dvalue = vars_table[op.cvalue - 'A' + 26];
  } else {
    printf("Error: Invalid lvalue for variable assignment.\n");
    return (operand){GARBAGE, 0, 0.0};
  }

  op.type = VAL;
  op.cvalue = 0;
  return op;
}

int validate_var(operand var) {
  if (var.type != VAR) {
    printf("validate_var() | Error: operand is not a VAR.\n");
    return 0;
  }

  if (!((var.cvalue >= 'a' && var.cvalue <= 'z') ||
        (var.cvalue >= 'A' && var.cvalue <= 'Z'))) {
    printf("validate_var() | Error: invalid variable name %c.\n", var.cvalue);
    return 0;
  }

  return 1;
}
