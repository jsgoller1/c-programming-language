#pragma once

#include <stdio.h>
#include <stdlib.h> // for atof()
#include <ctype.h>
#include <math.h>

#define NUMBER '0'
#define MAX_STACK_SIZE 100 // maximum depth of values stack
#define MAXOP 100 // max size for operand or operator

// The calculator accepts whitespace separated operands; as we parse
// operands from stdin, the parser logic makes determinations about what they
// are - supported types of operands are numeric (i.e. doubles), single-character
// variables, and strings of characters representing mathematical functions (sine,
// cosine, etc). The determination is returned to the switch block in main(), which
// does the right thing.
#define GARBAGE 0
#define VAR 1
#define RAW 2
#define SIN 3
#define COS 4
#define TAN 5
#define POW 6
#define EXP 7
#define SQRT 8

// bools
#define true 1
#define false 0

// parser.c
int getch(void);
void ungetch(int);
int getop(char []);
int handle_alpha();
int handle_numeric();

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