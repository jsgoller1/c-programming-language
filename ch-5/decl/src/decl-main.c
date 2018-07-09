#include <stdio.h>
#include <string.h>

#include "decl.h"

int main() {
  if (gettype() == -1) {
    return -1;
  }
  out[0] = '\0';
  if (decl() == 0) {
    printf("declare %s as %s %s\n", name, out, datatype);
    return 0;
  } else {
    return -1;
  }
}
