#include <stdio.h>

#include "decl.h"

char token[MAXTOKEN] = {0};
char name[MAXTOKEN] = {0};
char datatype[MAXTOKEN] = {0};
char out[MAXTOKEN] = {0};

int main() {
  while (gettoken() != EOF) {
    strcpy(datatype, token);
    out[0] = '\0';
    decl();
    if (tokentype != '\n') {
      printf("syntax error.\n");
    }
    printf("%s: %s %s\n", name, out, datatype);
  }
  return 0;
}
