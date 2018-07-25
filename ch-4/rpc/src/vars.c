#include "rpc.h"

// the vars table stores variables for
// a-z at offsets 0-25, and then
// A-Z at offsets 26-51
static double vars_table[MAX_STACK_SIZE];

void assign(const operand val1, const operand val2) {
  if (!validate_var(val1)) {
    return;
  }

  const operand val2_ready = (val2.type == VAR) ? dereference(val2) : val2;

  if (val1.cvalue >= 'a' && val1.cvalue <= 'z') {
    vars_table[val1.cvalue - 'a'] = val2_ready.dvalue;
  } else if (val1.cvalue >= 'A' && val1.cvalue <= 'Z') {
    // upper case var storage starts at vars_table[26]
    vars_table[val1.cvalue - 'A' + 26] = val2_ready.dvalue;
  }

  // C style assignment returns the value assigned
  push(val2_ready);
}

operand dereference(const operand op) {
  if (!validate_var(op)) {
    return (operand){GARBAGE, 0, 0.0};
  }

  operand new;
  if (op.cvalue >= 'a' && op.cvalue <= 'z') {
    new.dvalue = vars_table[op.cvalue - 'a'];
  } else if (op.cvalue >= 'A' && op.cvalue <= 'Z') {
    new.dvalue = vars_table[op.cvalue - 'A' + 26];
  } else {
    printf("Error: Invalid lvalue for variable assignment.\n");
    return (operand){GARBAGE, 0, 0.0};
  }

  new.type = VAL;
  new.cvalue = 0;
  return new;
}

int validate_var(const operand var) {
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
