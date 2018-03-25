#define MAXLEN 1000  // max len of any input line

// Character I/O
int getch(void);
void ungetch(int val);

// Line I/O
int mygetline(char *, int);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

// Memory / storage
char *myalloc(int n);
void myafree(char *p);
