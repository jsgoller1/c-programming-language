#include "rpc.h"

/*
NOTE: I do not actually know anything serious about lexing as I write this;
Wikipedia says lexing is "is the process of converting a sequence of characters
(such as in a computer program or web page) into a sequence of tokens (strings
with an assigned and thus identified meaning)", which is what the functions in
this file do.
*/

// lex: get next operator or numeric operand
operand_type lex(char symbol[], int token_len) {
  int len;

  while ((len = parse(symbol, token_len))) {
    // printf("lex() | parsed symbol: %s (%d)\n", symbol, len);
    if (len == -1) {
      return EXIT;
    }
    if (is_operator(symbol[0])) {
      return handle_operator(symbol[0]);
    }

    if (isalpha(symbol[0])) {
      return handle_alpha(symbol, len);
    } else if (isdigit(symbol[0]) || symbol[0] == '.') {
      /*
      uncomment the line below line to test ungets();
      this will push all floats back to the
      buffer before pushing them onto the
      stack, i.e. "4 +" will evaluate to 8
      */
      // ungets(symbol, len);
      return VAL;
    } else {
      return GARBAGE;
    }
  }

  // Loop breaks on display.
  return CONTINUE;
}

operand_type handle_alpha(char operator[], int len) {
  /*
  If we hit an alpha char, there are only two valid expressions:
  1) it's one character long, and therefore a variable
  2) it matches one of the supported mathematical functions,
  which are either 3 or 4 characters long. Anything else can
  be safely assumed to be garbage.
  */

  if (len == 1) {
    return VAR;
  }

  if (len == 2 || len > 4) {
    return GARBAGE;
  }

  if (len == 3) {
    if (strncmp(operator, SIN_STR,(unsigned long) len) == 0) {
      return SIN;
    } else if (strncmp(operator, COS_STR,(unsigned long) len) == 0) {
      return COS;
    } else if (strncmp(operator, TAN_STR,(unsigned long) len) == 0) {
      return TAN;
    } else if (strncmp(operator, POW_STR,(unsigned long) len) == 0) {
      return POW;
    } else if (strncmp(operator, EXP_STR,(unsigned long) len) == 0) {
      return EXP;
    }
  }
  if (len == 4) {
    if (strncmp(operator, ASIN_STR,(unsigned long) len) == 0) {
      return ASIN;
    } else if (strncmp(operator, ACOS_STR,(unsigned long) len) == 0) {
      return ACOS;
    } else if (strncmp(operator, ATAN_STR,(unsigned long) len) == 0) {
      return ATAN;
    } else if (strncmp(operator, SQRT_STR,(unsigned long) len) == 0) {
      return SQRT;
    } else if (strncmp(operator, FLOR_STR,(unsigned long) len) == 0) {
      return FLOR;
    }
  }

  // If we don't recognize the expression,
  // it's not supported.
  return GARBAGE;
}

int is_operator(char op) {
  return ((op == '+') || (op == '-') || (op == '/') || (op == '*') ||
          (op == '%') || (op == '='));
}

operand_type handle_operator(char operator) {
  // printf("handle_operator() | handling %c\n", operator);
  switch (operator) {
    case '+':
      return ADD;
    case '-':
      return SUB;
    case '*':
      return MUL;
    case '/':
      return DIV;
    case '%':
      return MOD;
    case '=':
      return ASSIGN;
    default:
      return GARBAGE;
  }
}
