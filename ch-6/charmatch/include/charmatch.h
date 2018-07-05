#pragma once

#include <stdbool.h>

typedef struct string {
  struct string* next_group;
  struct string* next_string;
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

// vars
void parse_varname(void);
void display_varnames(void);
void cleanup_varnames(void);
int store_varname(const char* const varname);

// types
int istypename(const char* const word);
int handle_define(void);
void handle_typedef(void);
void cleanup_typenames(void);

// misc
void skip_whitespace(void);
int parse_input(const int argc, char** const argv);

// strings
string* alloc_string(const char* const characters);
void free_string(string* str);
string* walk_strings_ll(const string* const head, const char* const str);
string* walk_groups_ll(const string* const head, const char* const str,
                       const int n);
