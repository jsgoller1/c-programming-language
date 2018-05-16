#define MAXLINES 5000             // maximum number of sortable lines
#define STORAGE_BUFFER_SIZE 5000  // number of bytes for stack buffer

int bufferedreadlines(char *lineptr[], int nlines, char storagebuffer[],
                      int buffersize);
void qsort(char *lineptr[], int left, int right);
void swap(char *v[], int i, int j);
