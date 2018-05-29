#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

extern int tokentype;
extern char token[];
extern char name[];
extern char datatype[];
extern char out[];

void decl(void);
void dirdecl(void);
int gettoken(void);
