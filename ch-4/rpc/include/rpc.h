#pragma once
#pragma clang diagnostic ignored "-Wpadded"

#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER '0'
#define MAX_STACK_SIZE 100     // maximum depth of values stack
#define MAX_TOKEN_SIZE 100     // max size for operand or operator
#define PARSE_BUFFER_SIZE 100  // buffer for ungetch

// The calculator accepts whitespace separated operands; as we parse
// operands from stdin, the parser logic makes determinations about what they
// are - supported types of operands are numeric (i.e. doubles),
// single-character variables, and strings of characters representing
// mathematical functions (sine, cosine, etc). The determination is returned to
// the switch block in main(), which does the right thing.
typedef enum {
  EXIT,
  VAR,
  VAL,
  GARBAGE,
  SIN,
  COS,
  TAN,
  ASIN,
  ACOS,
  ATAN,
  POW,
  EXP,
  SQRT,
  FLOR,
  ASSIGN,
  ADD,
  SUB,
  DIV,
  MUL,
  MOD,
  CONTINUE
} operand_type;

typedef struct {
  operand_type type;
  char cvalue;
  double dvalue;
} operand;

#define SIN_STR "SIN"
#define COS_STR "COS"
#define TAN_STR "TAN"
#define ASIN_STR "ASIN"
#define ACOS_STR "ACOS"
#define ATAN_STR "ATAN"
#define POW_STR "POW"
#define EXP_STR "EXP"
#define SQRT_STR "SQRT"
#define FLOR_STR "FLOR"

// parser.c
int rpc_getch(void);
void rpc_ungetch(const int);
void ungets(const char* const s, const int len);
int parse(char* const s, const int s_size);

// lexer.c
operand_type lex(char symbol[], int len);
operand_type handle_alpha(char oper[], int len);
operand_type handle_numeric(char oper[], int len);
int is_operator(char oper);
operand_type handle_operator(char oper);

// rpn_math.c
bool double_eq(const double x, const double y);
void rpn_add(operand val1, operand val2);
void rpn_subtract(operand val1, operand val2);
void rpn_multiply(operand val1, operand val2);
void rpn_divide(operand val1, operand val2);
void rpn_modulus(operand val1, operand val2);
void rpn_sin(operand val1);
void rpn_cos(operand val1);
void rpn_tan(operand val1);
void rpn_asin(operand val1);
void rpn_acos(operand val1);
void rpn_atan(operand val1);
void rpn_pow(operand val1, operand val2);
void rpn_exp(operand val1);
void rpn_sqrt(operand val1);
void rpn_floor(operand val1);

// stack.c
int push(operand op);
operand pop(void);
operand peek(void);
void duplicate_top(void);
void swap_top(void);
int get_stack_top(void);

// vars.c
void assign(operand val1, operand val2);
operand dereference(operand op);
int validate_var(operand op);
