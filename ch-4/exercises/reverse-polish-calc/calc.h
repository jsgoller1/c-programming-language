#pragma once

#include <stdio.h>
#include <stdlib.h> // for atof()
#include <ctype.h>
#include <math.h>

#define NUMBER '0'
#define MAX_STACK_SIZE 100      // maximum depth of values stack
#define MAX_OP_SIZE 100               // max size for operand or operator
#define PARSE_BUFFER_SIZE 100   // buffer for ungetch

// The calculator accepts whitespace separated operands; as we parse
// operands from stdin, the parser logic makes determinations about what they
// are - supported types of operands are numeric (i.e. doubles), single-character
// variables, and strings of characters representing mathematical functions (sine,
// cosine, etc). The determination is returned to the switch block in main(), which
// does the right thing.
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
#define CIEL 14
#define CIEL_STR "CEIL"

// bools
#define true 1
#define false 0

// parser.c
int getch(void);
void ungetch(int);
int parse(char s[], int s_size);

// lexer.c
int lex(char []);
int handle_alpha(char operator[], int len);
int handle_numeric(char operator[], int len);

// operations.c
void add(double val1[], double val2[]);
void subtract(double val1[], double val2[]);
void multiply(double val1[], double val2[]);
void divide(double val1[], double val2[]);
void modulus(double val1[], double val2[]);
void sin(double val1[]);
void cos(double val1[]);
void tan(double val1[]);
void pow(double val1[], double val2[]);
void exp(double val1[]);
void sqrt(double val1[]);

// stack.c
void push(double val[]);
void pop(double ret[]);
void peek(double ret[]);
void duplicate_top();
void swap_top();

// vars.c
void assign(double val1[], double val2[]);
void dereference(double var[]);
int validate_var(double var[]);