#include <stdio.h>
#include <string.h>

#include "decl.h"

// dirdecl: parse a direct declarator
void dirdecl(void) {
  int type = 0;

  if (tokentype == '(') {
    decl();
    if (tokentype != ')') {
      printf("error: missing )\n");
    }
  } else if (tokentype == NAME) {
    strcpy(name, token);
  } else {
    printf("error: expected name or (decl)\n");
  }

  type = gettoken();
  switch (type) {
    case PARENS:
      strcat(out, " function with no args returning");
      break;
    case BRACKETS:
      strcat(out, " array");
      strcat(out, token);
      strcat(out, " of");
      break;
    case '(':
      strcat(out, " function with args (");
      char args[] = {" "};
      while ((args[0] = (char)getchar()) != ')') {
        strcat(out, args);
      }
      type = ')';
      strcpy(token, ")");
      strcat(out, ") returning");
      break;
    case ')':
    case '\n':
      break;
    default:
      printf(
          "error: expected (), [], or (function args), but got %s (type %d: "
          "%c) \n",
          token, type, type);
      break;
  }
}
