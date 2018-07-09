#include <stdio.h>
#include <string.h>

#include "decl.h"

// decl(): parse a declarator
int decl(void) {
  int ns;

  for (ns = 0; gettoken() == '*';) {
    ns++;
  }
  if (dirdecl() == 0) {
    while (ns-- > 0) {
      strcat(out, " pointer to");
    }
    return 0;
  } else {
    return -1;
  }
}
