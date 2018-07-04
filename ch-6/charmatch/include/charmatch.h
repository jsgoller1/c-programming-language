#pragma once

typedef struct string {
  struct string* next;
  char* chars;
} string;

typedef string type_name;
typedef string var_name;
