#include "decl.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// decl(): parse a declarator
void decl() {
  int ns;

  for (ns = 0; gettoken() == '*';) {  // count '*'
    ns++;
  }
  dirdecl();

  while (ns-- > 0) {
    strcat(out, "pointer to");
  }
}

// dirdcl(): parse a direct declarator
void dirdecl() {
  int type;
  if (tokentype == '(') {  // decl
    decl();
    if (tokentype != ')') {
      printf("error: missing ')'\n");
    } else if (tokentype == NAME) {  // variable name
      strcpy(name, token);
    }
  } else {
    printf("error: expected name or (decl)");
  }
  while ((type = gettoken()) == PARENS || type == BRACKETS) {
    if (type == PARENS) {
      strcat(out, "function returning");
    } else {
      strcat(out, "array");
      strcat(out, token);
      strcat(out, " of");
    }
  }
}
