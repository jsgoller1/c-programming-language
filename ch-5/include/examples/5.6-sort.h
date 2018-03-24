#define MAXLINES 5000  // maximum number of sortable lines
#define MAXLEN 1000    // max len of any input line

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);
void swap(char *v[], int i, int j);
