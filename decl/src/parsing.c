#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "decl.h"

// decl(): parse a declarator
void decl() {
  int ns;

  for (ns = 0; gettoken() == '*';) {  // count '*'
    ns++;
  }
  dirdecl();

  while (ns-- > 0) {
    strcat(description, "pointer to ");
  }
}

// dirdcl(): parse a direct declarator
void dirdecl() {
  int type;
  if (tokentype == '(') {  // decl
    decl();
    if (tokentype != ')') {
      printf("error: missing ')'\n");
    }
  } else if (tokentype == NAME) {  // variable name
    strcpy(name, token);
  } else {
    printf("error: expected name or (decl).\n");
    return;
  }

  while ((type = gettoken()) == PARENS || type == BRACKETS) {
    if (type == PARENS) {
      strcat(description, "function returning ");
    } else {
      strcat(description, "array ");
      // strcat(description, token); // TODO: this is where the 4 in 'array 4 of
      // char' would be inserted
      strcat(description, "of ");
    }
  }
}
