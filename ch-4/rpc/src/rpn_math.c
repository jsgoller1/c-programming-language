#include <math.h>

#include "rpc.h"

// from https://stackoverflow.com/questions/5989191/compare-two-floats
bool double_eq(const double x, const double y) {
  if (fabs(x - y) < .0001) {
    return true;
  }
  return false;
}

void rpn_add(operand val1, operand val2) {
  if (val1.type == VAR) {
    dereference(val1);
  }
  if (val2.type == VAR) {
    dereference(val2);
  }
  val1.dval = val1.dval + val2.dval;
  val1.type = VAL;
  push(val1);
}

void rpn_subtract(operand val1, operand val2) {
  if (val1.type == VAR) {
    dereference(val1);
  }
  if (val2.type == VAR) {
    dereference(val2);
  }
  val1.dval = val1.dval - val2.dval;
  val1.type = VAL;
  push(val1);
}

void rpn_multiply(operand val1, operand val2) {
  if (val1.type == VAR) {
    dereference(val1);
  }
  if (val2.type == VAR) {
    dereference(val2);
  }
  val1.dval = val1.dval * val2.dval;
  val1.type = VAL;
  push(val1);
}

void rpn_divide(operand val1, operand val2) {
  if (val1.type == VAR) {
    dereference(val1);
  }
  if (val2.type == VAR) {
    dereference(val2);
  }
  if (double_eq(val2.dval, 0.0)) {
    printf("Error: division by zero.\n");
    return;
  }
  val1.dval = val1.dval / val2.dval;
  val1.type = VAL;
  push(val1);
}

void rpn_modulus(operand val1, operand val2) {
  if (val1.type == VAR) {
    dereference(val1);
  }
  if (val2.type == VAR) {
    dereference(val2);
  }
  if (double_eq(val2.dval, 0.0)) {
    printf("Error: modulo by zero.\n");
    return;
  }

  val1.dval = (int)val1.dval % (int)val2.dval;
  val1.type = VAL;
  push(val1);
}

void rpn_sin(operand val1) {
  if (val1.type == VAR) {
    dereference(val1);
  }

  val1.dval = sin(val1.dval);
  val1.type = VAL;
  push(val1);
}

void rpn_cos(operand val1) {
  if (val1.type == VAR) {
    dereference(val1);
  }

  val1.dval = cos(val1.dval);
  val1.type = VAL;
  push(val1);
}

void rpn_tan(operand val1) {
  if (val1.type == VAR) {
    dereference(val1);
  }

  val1.dval = tan(val1.dval);
  val1.type = VAL;
  push(val1);
}

void rpn_asin(operand val1) {
  if (val1.type == VAR) {
    dereference(val1);
  }

  val1.dval = asin(val1.dval);
  val1.type = VAL;
  push(val1);
}

void rpn_acos(operand val1) {
  if (val1.type == VAR) {
    dereference(val1);
  }

  val1.dval = acos(val1.dval);
  val1.type = VAL;
  push(val1);
}

void rpn_atan(operand val1) {
  if (val1.type == VAR) {
    dereference(val1);
  }

  val1.dval = atan(val1.dval);
  val1.type = VAL;
  push(val1);
}

void rpn_pow(operand val1, operand val2) {
  if (val1.type == VAR) {
    dereference(val1);
  }
  if (val2.type == VAR) {
    dereference(val2);
  }

  val1.dval = pow(val1.dval, val2.dval);
  val1.type = VAL;
  push(val1);
}

void rpn_exp(operand val1) {
  if (val1.type == VAR) {
    dereference(val1);
  }

  val1.dval = exp(val1.dval);
  val1.type = VAL;
  push(val1);
}

void rpn_sqrt(operand val1) {
  if (val1.type == VAR) {
    dereference(val1);
  }

  val1.dval = sqrt(val1.dval);
  val1.type = VAL;
  push(val1);
}

void rpn_floor(operand val1) {
  if (val1.type == VAR) {
    dereference(val1);
  }

  val1.dval = floor(val1.dval);
  val1.type = VAL;
  push(val1);
}
