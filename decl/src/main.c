#include <stdio.h>
#include <string.h>
#include "decl.h"

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

// decl - converts complicated syntax declarations to English
int main() {
  while (gettoken() != EOF) {  // 1st token on the line
    strcpy(datatype, token);   // is the datatype
    out[0] = '\0';

    decl();  // parse rest of the line
    if (tokentype != '\n') {
      printf("syntax error.\n");
    }
    printf("%s: %s %s\n", name, out, datatype);
  }
  return 0;
}
