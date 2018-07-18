#pragma once

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
#define EXIT 0
#define VAR 1
#define RAW 2
#define GARBAGE 3
#define SIN 4
#define SIN_STR "SIN"
#define COS 5
#define COS_STR "COS"
#define TAN 6
#define TAN_STR "TAN"
#define ASIN 7
#define ASIN_STR "ASIN"
#define ACOS 8
#define ACOS_STR "ACOS"
#define ATAN 9
#define ATAN_STR "ATAN"
#define POW 10
#define POW_STR "POW"
#define EXP 11
#define EXP_STR "EXP"
#define SQRT 12
#define SQRT_STR "SQRT"
#define FLOR 13
#define FLOR_STR "FLOR"
#define ASSIGN 14
#define ADD 15
#define SUB 16
#define DIV 17
#define MUL 18
#define MOD 19
#define DISPLAY 20

// bools
#define true 1
#define false 0

// parser.c
int rpc_getch(void);
void rpc_ungetch(int);
void ungets(char s[], int len);
int parse(char s[], int s_size);

// lexer.c
int lex(char symbol[], int len);
int handle_alpha(char oper[], int len);
int handle_numeric(char oper[], int len);
int is_operator(char oper[]);
int handle_operator(char oper[]);

// rpn_math.c
bool double_eq(const double x, const double y);
void rpn_add(double val1[], double val2[]);
void rpn_subtract(double val1[], double val2[]);
void rpn_multiply(double val1[], double val2[]);
void rpn_divide(double val1[], double val2[]);
void rpn_modulus(double val1[], double val2[]);
void rpn_sin(double val1[]);
void rpn_cos(double val1[]);
void rpn_tan(double val1[]);
void rpn_asin(double val1[]);
void rpn_acos(double val1[]);
void rpn_atan(double val1[]);
void rpn_pow(double val1[], double val2[]);
void rpn_exp(double val1[]);
void rpn_sqrt(double val1[]);
void rpn_floor(double val1[]);

// stack.c
void push(double val[]);
void pop(double ret[]);
void peek(double ret[]);
void duplicate_top(void);
void swap_top(void);
int get_stack_size(void);
void display(void);

// vars.c
void assign(double val1[], double val2[]);
void dereference(double var[]);
int validate_var(double var[]);
