#include <stdio.h>
#include <string.h>

#include "decl.h"

char token[MAXTOKEN] = {0};
char name[MAXTOKEN] = {0};
char datatype[MAXTOKEN] = {0};
char out[MAXTOKEN] = {0};
int tokentype = 0;
char* types[] = {"char", "short", "int", "long", "float", "double", "void"};

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