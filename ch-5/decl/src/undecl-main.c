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
        // printf("out: %s (appended paren / brackets)\n", out);
      } else if (type == '*') {
        if ((type = gettoken()) == PARENS || type == BRACKETS) {
          sprintf(temp, "(*%s)", out);
        } else if (type == NAME) {
          sprintf(temp, "%s ", token);
          sprintf(token, "%s", out);
        } else if (type == '*') {
          sprintf(temp, "**%s", out);
          sprintf(token, "%s", "");
        } else {
          sprintf(temp, "*%s", out);
        }
        strcat(temp, token);
        strcpy(out, temp);
        // printf("out: %s (encountered pointer, appended following)\n", out);
      } else if (type == NAME) {
        sprintf(temp, "%s %s", token, out);
        strcpy(out, temp);
        // printf("out: %s (encountered name)\n", out);
      } else {
        printf("invalid input at %s\n", token);
      }
    }
    printf("%s\n\n", out);
  }
  return 0;
}
