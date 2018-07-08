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
      while ((type = gettoken()) == NAME) {
        strcat(out, " ");
        strcat(out, token);
      }
      strcat(out, ") returning");
      break;
    default:
      printf("error: expected (), [], or (function args)\n");
      break;
  }
  /*
    while ((type = gettoken()) == PARENS || type == BRACKETS || type == NAME) {
      if (type == PARENS) {
        strcat(out, " function returning");
      } else if (type == NAME) {
        strcat(out, " function with args (");
        strcat(out, token);
        while ((type = gettoken()) != ')') {
          strcat(out, token);
        }
        strcat(out, ") ");
      } else {
        strcat(out, " array");
        strcat(out, token);
        strcat(out, " of");
      }
    }
*/
}
