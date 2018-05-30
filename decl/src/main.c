#include <stdio.h>
#include <string.h>
#include "decl.h"

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char description[1000];

// decl - converts complicated syntax declarations to English
int main() {
  while (gettoken() != EOF) {  // 1st token on the line
    strcpy(datatype, token);   // is the datatype
    description[0] = '\0';
    printf("initial datatype: %s.\n", datatype);

    decl();  // parse rest of the line
    if (tokentype != '\n') {
      printf("syntax error.\n");
    }
    printf("name: %s\n", name);
    printf("description: %s\n", description);
    printf("datatype: %s\n\n", datatype);
    printf("%s: %s%s\n------------------------\n", name, description, datatype);
  }
  return 0;
}
