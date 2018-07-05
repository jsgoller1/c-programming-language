#include <stdbool.h>
#include <string.h>

#include "charmatch.h"

bool IN_CPP_COMMENT = false;  // this kind of comment
bool IN_C_COMMENT = false;    /* this kind of comment */
bool IN_STRING = false;
bool IN_FUNCTION_PARAMS = false;

#define SHOULD_EVALUATE \
  !(IN_CPP_COMMENT | IN_C_COMMENT | IN_STRING | IN_FUNCTION_PARAMS)

void update_fsm(const char* const token) {
  if ((strcmp(token, ")") == 0) && IN_FUNCTION_PARAMS) {
    IN_FUNCTION_PARAMS = false;
  }
}

bool should_evaluate(const char* const token) {
  update_fsm(token);
  return SHOULD_EVALUATE;
}
