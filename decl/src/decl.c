#include "decl.h"
#include <stdio.h>
#include <string.h>

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char description[1000];

// decl - converts complicated syntax declarations to English
int main() {
  printf("Enter a valid C expression:\n");
  while (gettoken() != EOF) {  // 1st token on the line
    strcpy(datatype, token);   // is the datatype
    description[0] = '\0';

    decl();  // parse rest of the line
    if (tokentype != '\n') {
      printf("syntax error.\n");
    }
    printf("%s: %s%s\n\n", name, description, datatype);
  }
  return 0;
}
