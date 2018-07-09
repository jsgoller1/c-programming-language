#include <stdio.h>
#include <string.h>

#include "decl.h"

// undecl: convert word description into declaration
int main() {
  int type;
  char temp[MAXTOKEN];

  while (gettoken() != EOF) {
    strcpy(out, token);
    while ((type = gettoken()) != '\n') {
      if (type == PARENS || type == BRACKETS) {
        strcat(out, token);
      } else if (type == '*') {
        if ((type = gettoken()) == PARENS || type == BRACKETS) {
          sprintf(temp, "(*%s)", out);
          strcat(temp, token);
        } else if (type == NAME) {
          sprintf(temp, "%s* %s", token, out);
        } else if (type == '*') {
          sprintf(temp, "**%s", out);
        } else {
          printf("undecl: syntax error.\n");
        }
        strcpy(out, temp);
      } else if (type == NAME) {
        sprintf(temp, "%s %s", token, out);
        strcpy(out, temp);
      } else {
        printf("invalid input at %s\n", token);
      }
    }
    printf("%s\n", out);
  }
  return 0;
}
