#pragma once

#define MAXTOKEN 100

// globals
enum { NAME, PARENS, BRACKETS, CONST };
extern int tokentype;
extern char token[];
extern char name[];
extern char datatype[];
extern char out[];

#define TYPESCOUNT 7
extern char* types[];

// decl
void decl(void);

// dirdcl
void dirdecl(void);

// gettoken
int gettoken(void);
int istype(void);
