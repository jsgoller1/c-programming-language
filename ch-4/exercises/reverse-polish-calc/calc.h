#pragma once

#include <stdio.h>
#include <stdlib.h> // for atof()
#include <ctype.h>

#define NUMBER '0'
#define MAX_STACK_SIZE 100 // maximum depth of values stack
#define MAXOP 100 // max size for operand or operator

#define true 1
#define false 0

// getch.c
int getch(void);
void ungetch(int);

// getop.c
int getop(char []);

// stack.c
void push(double);
double pop(void);
void duplicate_top(void);
double peek(void);
void swap_top(void);

// vars.c
void store_var(int, double);
void assign(void);
double dereference(int);