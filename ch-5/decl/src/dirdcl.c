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

  while ((type = gettoken()) == PARENS || type == '(' || type == BRACKETS) {
    switch (type) {
      case PARENS:
        strcat(out, " function returning");
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
        type = PARENS;
        strcpy(token, "()");
        strcat(out, ") returning");
        break;
    }
  }
}
