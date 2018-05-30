#define MAXTOKEN 100

// typedef struct token {
//} token;

enum { NAME, PARENS, BRACKETS };

extern int tokentype;
extern char token[];
extern char name[];
extern char datatype[];
extern char description[];

void decl(void);
void dirdecl(void);
int gettoken(void);
