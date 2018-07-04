#pragma once

typedef struct string {
  struct string* next;
  char* chars;
} string;

typedef string type_name;
typedef string var_name;

// fsm
int should_evaluate(const char* const word);

// vars
void store_varname(void);
void display_varnames(void);
void cleanup_varnames(void);

// types
int istypename(const char* const word);
void handle_define(void);
void handle_typedef(void);
void cleanup_typenames(void);
