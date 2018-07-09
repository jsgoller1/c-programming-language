#pragma once

#define MAXTOKEN 100

// globals
enum { NAME, PARENS, BRACKETS };
extern int tokentype;
extern char token[];
extern char name[];
extern char datatype[];
extern char out[];

#define TYPESCOUNT 7
extern char* types[];

// decl
int decl(void);

// dirdecl
int dirdecl(void);

// gettoken
int gettoken(void);
int gettype(void);
int istype(void);
