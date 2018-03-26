#define MAXLINES 5000  // maximum number of sortable lines
#define MAXLEN 1000    // max len of any input line

// From this exercise
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void swap(char *v[], int i, int j);
void qsort(char *lineptr[], int left, int right);
