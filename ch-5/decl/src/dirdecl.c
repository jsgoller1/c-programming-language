#include <stdio.h>
#include <string.h>

#include "decl.h"

// dirdecl: parse a direct declarator via the grammar, possibly recursing into
// decl if necessary.
int dirdecl(void) {
  int type = 0;

  if (tokentype == '(') {
    if (decl() == -1) {
      return -1;
    }
    if (tokentype != ')') {
      printf("error: missing )\n");
      return -1;
    }
  } else if (tokentype == NAME) {
    strcpy(name, token);
  } else {
    printf("error: expected name or (decl)\n");
    return -1;
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

  return 0;
}
