#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "decl.h"

// decl(): parse a declarator
int decl() {
  int ns;

  for (ns = 0; gettoken() == '*';) {  // count '*'
    ns++;
  }
  if (dirdecl() == -1) {
    return -1;
  }

  while (ns-- > 0) {
    strcat(description, "pointer to ");
  }
  return 0;
}

// dirdcl(): parse a direct declarator
int dirdecl() {
  int type;
  if (tokentype == '(') {  // decl
    decl();
    if (tokentype != ')') {
      printf("error: missing ')'\n");
      return -1;
    }
  } else if (tokentype == NAME) {  // variable name
    strcpy(name, token);
  } else {
    printf("error: expected name or (decl).\n");
    return -1;
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
  return 0;
}
