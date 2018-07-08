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
  while ((type = gettoken()) == PARENS || type == BRACKETS) {
    if (type == PARENS) {
      strcat(out, " function returning");
    } else {
      strcat(out, " array");
      strcat(out, token);
      strcat(out, " of");
    }
  }
}
