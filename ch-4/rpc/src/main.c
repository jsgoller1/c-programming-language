#include "rpc.h"

// Reverse Polish calculator
int main() {
  operand op1;
  operand op2;
  operand_type type;
  char token[MAX_TOKEN_SIZE];

  while ((type = lex(token, MAX_TOKEN_SIZE)) != EXIT) {
    switch (type) {
      case VAL:
        op1.type = VAL;
        op1.dvalue = atof(token);
        op1.cvalue = 0;
        push(op1);
        break;
      case VAR:
        op1.type = VAR;
        op1.cvalue = token;
        op1.dvalue = 0.0;
        push(op1);
        break;
      case ASSIGN:
        pop(op2);
        pop(op1);
        assign(op1, op2);
        break;
      case ADD:
        pop(op2);
        pop(op1);
        rpn_add(op1, op2);
        break;
      case MUL:
        pop(op2);
        pop(op1);
        rpn_multiply(op1, op2);
        break;
      case SUB:
        pop(op2);
        pop(op1);
        rpn_subtract(op1, op2);
        break;
      case DIV:
        pop(op2);
        pop(op1);
        rpn_divide(op1, op2);
        break;
      case MOD:
        pop(op2);
        pop(op1);
        rpn_modulus(op1, op2);
        break;
      case SIN:
        pop(op1);
        rpn_sin(op1);
        break;
      case COS:
        pop(op1);
        rpn_cos(op1);
        break;
      case TAN:
        pop(op1);
        rpn_tan(op1);
        break;
      case ASIN:
        pop(op1);
        rpn_asin(op1);
        break;
      case ACOS:
        pop(op1);
        rpn_acos(op1);
        break;
      case ATAN:
        pop(op1);
        rpn_atan(op1);
        break;
      case POW:
        pop(op2);
        pop(op1);
        rpn_pow(op1, op2);
        break;
      case EXP:
        pop(op1);
        rpn_exp(op1);
        break;
      case SQRT:
        pop(op1);
        rpn_sqrt(op1);
        break;
      case FLOR:
        pop(op1);
        rpn_floor(op1);
        break;
      case GARBAGE:
      default:
        printf("Error: invalid expression %s.\n", token);
        return -1;
    }
  }
  if (get_stack_size() == 1) {
    operand final = pop();
    printf("%8.8g\n", final.dvalue);
    return 0;
  } else {
    printf("Error: invalid expression; quitting.\n");
    return -1;
  }
}
