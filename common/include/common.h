#pragma once
#include <stdbool.h>

#define MAXLEN 1000  // max len of any input line

#ifdef DEBUG
#define LOG(msg) printf("Log: %s\n", msg);
#else
#define LOG(msg) ;
#endif

// Bitwise functions
int create_mask(const int n, const int position, int* const mask,
                const bool inverted);
int clear_bitfield(int* x, const int position, const int n);

// Character I/O
int getch(void);
void ungetch(int val);

// Line I/O
int mygetline(char* const line, const int maxline);
int readlines(char** lineptr, const int maxlines);
void writelines(char** lineptr, const int nlines);
void freelines(char** lineptr, const int nlines);
int getword(char* word, int len);
int gettoken(char* word, const int len);

// Memory
char* myalloc(int n);
void myafree(char* p);

// Maths
int powi(int base, int exp);

// Strings
// TODO: Either uncomment this or remove it and make 1.19 static.
// void reverse(char *const s, const int len);
