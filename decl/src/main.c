#include <stdio.h>
#include "decl.h"

// decl - converts complicated syntax declarations to English
int main() {
  while (gettoken() != EOF) {  // 1st token on the line
    strcpy(datatype, token);   // is the datatype
    out[0] = '\0';

    dcl();  // parse rest of the line
    if (tokentype != '\n') {
      printf("syntax error.\n");
    }
    printf("%s: %s %s\n", name, out, datatype);
  }
  return 0;
}
