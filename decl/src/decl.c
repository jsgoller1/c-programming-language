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
    // printf("initial datatype: %s.\n", datatype);

    decl();  // parse rest of the line
    if (tokentype != '\n') {
      printf("syntax error.\n");
    }
    // printf("name: %s\n", name);
    // printf("description: %s\n", description);
    // printf("datatype: %s\n\n", datatype);
    printf("%s: %s%s\n", name, description, datatype);

    // clear memory to recovery from input errors
    // printf("Clearing memory for next iteration...\n");
    // tokentype = 0;
    // memset(token, ' ', MAXTOKEN);
    // printf("Cleared token.\n");
    // memset(name, ' ', MAXTOKEN);
    // printf("Cleared name.\n");
    // memset(datatype, ' ', MAXTOKEN);
    // printf("Cleared datatype.\n");
    // memset(description, ' ', 1000);
    // printf("Cleared description.\n");
    // printf("Ready for next iteration.\n");
  }
  return 0;
}
