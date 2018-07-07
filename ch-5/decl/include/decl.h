#pragma once

#define MAXTOKEN 100

// globals
enum { NAME, PARENS, BRACKETS };
extern int tokentype;
extern char token[];
extern char name[];
extern char datatype[];
extern char out[];

// decl
void decl(void);

// dirdcl
void dirdecl(void);

// gettoken
int gettoken(void);
