#pragma once

#include <stdbool.h>

typedef struct string {
  struct string* next;
  char* chars;
} string;

typedef string type_name;
typedef string var_name;

extern int MATCH_LENGTH;

// fsm
extern bool IN_CPP_COMMENT;
extern bool IN_C_COMMENT;
extern bool IN_STRING;
extern bool IN_FUNCTION_PARAMS;

bool should_evaluate(const char* const token);
void update_fsm(const char* const token);

// vars
void parse_varname(void);
void display_varnames(void);
void cleanup_varnames(void);
void store_varname(const char* const varname);

// types
int istypename(const char* const word);
void handle_define(void);
void handle_typedef(void);
void cleanup_typenames(void);

// misc
string* alloc_string(const char* const characters);
void free_string(string* str);
void skip_whitespace(void);
int parse_input(const int argc, char** const argv);
