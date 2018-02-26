#pragma once

#include <stdio.h>
#include <stdlib.h> // for atof()
#include <ctype.h>

#define NUMBER '0'

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