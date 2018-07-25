#include "rpc.h"

// Reverse Polish calculator
int main() {
  operand op1;
  operand op2;
  operand_type type;
  char token[MAX_TOKEN_SIZE];

  while ((type = lex(token, MAX_TOKEN_SIZE))) {
    printf("main() | evaluating type %d, token %s\n", type, token);
    switch (type) {
      case VAL:
        op1.type = VAL;
        op1.dvalue = atof(token);
        op1.cvalue = 0;
        push(op1);
        break;
      case VAR:
        op1.type = VAR;
        op1.cvalue = token[0];
        op1.dvalue = 0.0;
        push(op1);
        break;
      case ASSIGN:
        op2 = pop();
        op1 = pop();
        assign(op1, op2);
        break;
      case ADD:
        op2 = pop();
        op1 = pop();
        rpn_add(op1, op2);
        break;
      case MUL:
        op2 = pop();
        op1 = pop();
        rpn_multiply(op1, op2);
        break;
      case SUB:
        op2 = pop();
        op1 = pop();
        rpn_subtract(op1, op2);
        break;
      case DIV:
        op2 = pop();
        op1 = pop();
        rpn_divide(op1, op2);
        break;
      case MOD:
        op2 = pop();
        op1 = pop();
        rpn_modulus(op1, op2);
        break;
      case SIN:
        op1 = pop();
        rpn_sin(op1);
        break;
      case COS:
        op1 = pop();
        rpn_cos(op1);
        break;
      case TAN:
        op1 = pop();
        rpn_tan(op1);
        break;
      case ASIN:
        op1 = pop();
        rpn_asin(op1);
        break;
      case ACOS:
        op1 = pop();
        rpn_acos(op1);
        break;
      case ATAN:
        op1 = pop();
        rpn_atan(op1);
        break;
      case POW:
        op2 = pop();
        op1 = pop();
        rpn_pow(op1, op2);
        break;
      case EXP:
        op1 = pop();
        rpn_exp(op1);
        break;
      case SQRT:
        op1 = pop();
        rpn_sqrt(op1);
        break;
      case FLOR:
        op1 = pop();
        rpn_floor(op1);
        break;
      case CONTINUE:
        op1 = pop();
        printf("%8.8g\n", op1.dvalue);
        break;
      case EXIT:
        // this never occurs, but the compiler
        // whines if it's not present.
        break;
      case GARBAGE:
        printf("Error: invalid expression %s.\n", token);
        return -1;
    }
  }
  if (get_stack_size() == 0) {
    operand final = pop();
    printf("%8.8g\n", final.dvalue);
    return 0;
  } else {
    printf("stack size: %d\n", get_stack_size());
    printf("Error: invalid expression; quitting.\n");
    return -1;
  }
}
