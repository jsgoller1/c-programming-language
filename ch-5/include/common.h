#define MAXLEN 1000  // max len of any input line

// Character I/O
int getch(void);
void ungetch(int val);

// Line I/O
int mygetline(char *line, int maxline);

// declare lineptr as const pointer to pointer to const char; the pointers to
// the strings will change as we copy them in, but the array pointer should not
// mutate and the chars in the strings shouldn't either.
int readlines(char *const *const lineptr, const int nlines);

// declare lineptr as const pointer to const pointer to const char; the array
// pointer, string pointers, and chars in the strings should not mutate
void writelines(const char *const *const lineptr, const int nlines);

// Memory / storage
char *myalloc(int n);
void myafree(char *p);
