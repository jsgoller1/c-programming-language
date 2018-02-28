#pragma once

#include <stdio.h>
#include <stdlib.h> // for atof()
#include <ctype.h>

#define NUMBER '0'
#define MAX_STACK_SIZE 100 // maximum depth of values stack
#define MAXOP 100 // max size for operand or operator

// Before a value is stored on the stack, a determination must be made
// as to what the data type is: a variable (later needing to be dereferenced),
// or a raw float; the "type" is pushed first and the value is pushed second. 
#define VAR 0.0
#define RAW 1.0

#define true 1
#define false 0

// getch.c
int getch(void);
void ungetch(int);

// getop.c
int getop(char []);

// operations.c
void add(double val1[], double val2[]);
void subtract(double val1[], double val2[]);
void multiply(double val1[], double val2[]);
void divide(double val1[], double val2[]);
void modulus(double val1[], double val2[]);

// stack.c
void push(double val[]);
void pop(double ret[]);
void peek(double ret[]);
void duplicate_top();
void swap_top();

// vars.c
void store_var(double val1[], double val2[]);
void assign(double val1[], double val2[]);
double dereference(double var[]);