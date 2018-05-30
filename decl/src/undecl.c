#include <stdio.h>
#include <string.h>
#include "decl.h"

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char description[1000];

/* undcl: convert word description to declaration */
int main() {
  int type;
  char temp[MAXTOKEN];

  while (gettoken() != EOF) {
    strcpy(description, token);
    while ((type = gettoken()) != '\n') {
      if (type == PARENS || type == BRACKETS) {
        strcat(description, token);
      } else if (type == '*') {
        sprintf(temp, "(*%s)", description);
        strcpy(description, temp);
      } else if (type == NAME) {
        sprintf(temp, "%s %s", token, description);
        strcpy(description, temp);
      } else {
        printf("invalid input at %s\n", token);
      }
      printf("%s\n", description);
    }
  }
  return 0;
}
