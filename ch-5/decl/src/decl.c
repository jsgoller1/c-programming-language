#include <stdio.h>
#include <string.h>

#include "decl.h"

// decl(): parse a declarator
void decl(void) {
  int ns;

  for (ns = 0; gettoken() == '*';) {
    ns++;
  }
  dirdcl();
  while (ns-- > 0) {
    strcat(out, "pointer to");
  }
}
