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
  printf("rpn_add() | %lf + %lf\n", val1.dvalue, val2.dvalue);
  val1.dvalue = val1.dvalue + val2.dvalue;
  val1.type = VAL;
  printf("rpn_add() | called (new dvalue %lf).\n", val1.dvalue);
  push(val1);
}

void rpn_subtract(operand val1, operand val2) {
  if (val1.type == VAR) {
    dereference(val1);
  }
  if (val2.type == VAR) {
    dereference(val2);
  }
  val1.dvalue = val1.dvalue - val2.dvalue;
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
  val1.dvalue = val1.dvalue * val2.dvalue;
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
  if (double_eq(val2.dvalue, 0.0)) {
    printf("Error: division by zero.\n");
    return;
  }
  val1.dvalue = val1.dvalue / val2.dvalue;
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
  if (double_eq(val2.dvalue, 0.0)) {
    printf("Error: modulo by zero.\n");
    return;
  }

  val1.dvalue = (int)val1.dvalue % (int)val2.dvalue;
  val1.type = VAL;
  push(val1);
}

void rpn_sin(operand val1) {
  if (val1.type == VAR) {
    dereference(val1);
  }

  val1.dvalue = sin(val1.dvalue);
  val1.type = VAL;
  push(val1);
}

void rpn_cos(operand val1) {
  if (val1.type == VAR) {
    dereference(val1);
  }

  val1.dvalue = cos(val1.dvalue);
  val1.type = VAL;
  push(val1);
}

void rpn_tan(operand val1) {
  if (val1.type == VAR) {
    dereference(val1);
  }

  val1.dvalue = tan(val1.dvalue);
  val1.type = VAL;
  push(val1);
}

void rpn_asin(operand val1) {
  if (val1.type == VAR) {
    dereference(val1);
  }

  val1.dvalue = asin(val1.dvalue);
  val1.type = VAL;
  push(val1);
}

void rpn_acos(operand val1) {
  if (val1.type == VAR) {
    dereference(val1);
  }

  val1.dvalue = acos(val1.dvalue);
  val1.type = VAL;
  push(val1);
}

void rpn_atan(operand val1) {
  if (val1.type == VAR) {
    dereference(val1);
  }

  val1.dvalue = atan(val1.dvalue);
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

  val1.dvalue = pow(val1.dvalue, val2.dvalue);
  val1.type = VAL;
  push(val1);
}

void rpn_exp(operand val1) {
  if (val1.type == VAR) {
    dereference(val1);
  }

  val1.dvalue = exp(val1.dvalue);
  val1.type = VAL;
  push(val1);
}

void rpn_sqrt(operand val1) {
  if (val1.type == VAR) {
    dereference(val1);
  }

  val1.dvalue = sqrt(val1.dvalue);
  val1.type = VAL;
  push(val1);
}

void rpn_floor(operand val1) {
  if (val1.type == VAR) {
    dereference(val1);
  }

  val1.dvalue = floor(val1.dvalue);
  val1.type = VAL;
  push(val1);
}
