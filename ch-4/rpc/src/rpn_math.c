#include <math.h>

#include "rpc.h"

// from https://stackoverflow.com/questions/5989191/compare-two-floats
bool double_eq(const double x, const double y) {
  if (fabs(x - y) < .0001) {
    return true;
  }
  return false;
}

void rpn_add(double val1[], double val2[]) {
  if (double_eq(val1[0], VAR)) {
    dereference(val1);
  }
  if (double_eq(val2[0], VAR)) {
    dereference(val2);
  }
  val1[0] = val1[0] + val2[0];
  val1[1] = RAW;
  push(val1);
}

void rpn_subtract(double val1[], double val2[]) {
  if (double_eq(val1[0], VAR)) {
    dereference(val1);
  }
  if (double_eq(val2[0], VAR)) {
    dereference(val2);
  }
  val1[0] = val1[0] - val2[0];
  val1[1] = RAW;
  push(val1);
}

void rpn_multiply(double val1[], double val2[]) {
  if (double_eq(val1[0], VAR)) {
    dereference(val1);
  }
  if (double_eq(val2[0], VAR)) {
    dereference(val2);
  }
  val1[0] = val1[0] * val2[0];
  val1[1] = RAW;
  push(val1);
}

void rpn_divide(double val1[], double val2[]) {
  if (double_eq(val1[0], VAR)) {
    dereference(val1);
  }
  if (double_eq(val2[0], VAR)) {
    dereference(val2);
  }
  if (double_eq(val2[0], 0.0)) {
    printf("Error: division by zero.\n");
    return;
  }
  val1[0] = val1[0] / val2[0];
  val1[1] = RAW;
  push(val1);
}

void rpn_modulus(double val1[], double val2[]) {
  if (double_eq(val1[0], VAR)) {
    dereference(val1);
  }
  if (double_eq(val2[0], VAR)) {
    dereference(val2);
  }
  if (double_eq(val2[0], 0.0)) {
    printf("Error: modulo by zero.\n");
    return;
  }

  val1[0] = (int)val1[0] % (int)val2[0];
  val1[1] = RAW;
  push(val1);
}

void rpn_sin(double val1[]) {
  if (double_eq(val1[0], VAR)) {
    dereference(val1);
  }

  val1[0] = sin(val1[0]);
  val1[1] = RAW;
  push(val1);
}

void rpn_cos(double val1[]) {
  if (double_eq(val1[0], VAR)) {
    dereference(val1);
  }

  val1[0] = cos(val1[0]);
  val1[1] = RAW;
  push(val1);
}

void rpn_tan(double val1[]) {
  if (double_eq(val1[0], VAR)) {
    dereference(val1);
  }

  val1[0] = tan(val1[0]);
  val1[1] = RAW;
  push(val1);
}

void rpn_asin(double val1[]) {
  if (double_eq(val1[0], VAR)) {
    dereference(val1);
  }

  val1[0] = asin(val1[0]);
  val1[1] = RAW;
  push(val1);
}

void rpn_acos(double val1[]) {
  if (double_eq(val1[0], VAR)) {
    dereference(val1);
  }

  val1[0] = acos(val1[0]);
  val1[1] = RAW;
  push(val1);
}

void rpn_atan(double val1[]) {
  if (double_eq(val1[0], VAR)) {
    dereference(val1);
  }

  val1[0] = atan(val1[0]);
  val1[1] = RAW;
  push(val1);
}

void rpn_pow(double val1[], double val2[]) {
  if (double_eq(val1[0], VAR)) {
    dereference(val1);
  }
  if (double_eq(val2[0], VAR)) {
    dereference(val2);
  }

  val1[0] = pow(val1[0], val2[0]);
  val1[1] = RAW;
  push(val1);
}

void rpn_exp(double val1[]) {
  if (double_eq(val1[0], VAR)) {
    dereference(val1);
  }

  val1[0] = exp(val1[0]);
  val1[1] = RAW;
  push(val1);
}

void rpn_sqrt(double val1[]) {
  if (double_eq(val1[0], VAR)) {
    dereference(val1);
  }

  val1[0] = sqrt(val1[0]);
  val1[1] = RAW;
  push(val1);
}

void rpn_floor(double val1[]) {
  if (double_eq(val1[0], VAR)) {
    dereference(val1);
  }

  val1[0] = floor(val1[0]);
  val1[1] = RAW;
  push(val1);
}
