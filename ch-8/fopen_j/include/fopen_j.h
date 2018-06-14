#include <stdbool.h>
#include <stddef.h>

#define NULL_J 0
#define EOF (-1)
#define BUFSIZ 10
#define OPEN_MAX 20

typedef struct _flags {
  bool _READ;
  bool _WRITE;
  bool _UNBUF;
  bool _EOF;
  bool _ERR;
  char _align[3];  // do not use
} _flags;

typedef struct _iobuf {
  int fd;      // file descriptor
  char *base;  // pointer to I/O buffer
  char *ptr;   // next character position within I/O buffer
  long count;  // characters left in buffer
  int _align;  // do not use
  _flags flags;
} FILE_J;

extern FILE_J _iobufs[OPEN_MAX];

#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

#define feof(p) (((p)->flag & _EOF) != 0)
#define ferror(p) (((p)->flag & _ERR) != 0)
#define fileno(p) ((p)->fd)

#define getchar() getc(stdin)
#define putchar(x) putc((x), stdout)

FILE_J *fopen_j(const char *const name, const char *const mode);
int fclose_j(FILE_J *file);

int getc(FILE_J *file);
int _fill_buf(FILE_J *file);
int putc(int character, FILE_J *stream);
int _flush_buf(FILE_J *file);
int fflush_j(FILE_J *stream);
