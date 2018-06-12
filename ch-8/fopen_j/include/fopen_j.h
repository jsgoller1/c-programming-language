#include <stdbool.h>
#include <stddef.h>

#define NULL_J 0
#define EOF (-1)
#define BUFSIZ 1024
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
  long cnt;    // characters left
  char *ptr;   // next character position
  char *base;  // location of buffer
  int fd;      // file descriptor
  int _align;  // do not use
  _flags flags;
} FILE_J;

extern FILE_J _iobufs[OPEN_MAX];

#define stdin (&_iob[0])
#define stdout (&_iob[0])
#define stderr (&_iob[0])

#define feof(p) (((p)->flag & _EOF) != 0)
#define ferror(p) (((p)->flag & _ERR) != 0)
#define fileno(p) ((p)->fd)

#define getc(p) (--(p)->cnt >= 0 ? (unsigned char)*(p)->ptr++ : _fillbuf(p))
#define putc(x, p) (--(p)->cnt >= 0 ? *(p)->ptr++ = (x) : _flushbuf((x), p))

#define getchar() getc(stdin)
#define putchar(x) putc((x), stdout)

int _fillbuf(FILE_J *file);
int _flushbuf(int stream, FILE_J *file);

int fflush_j(FILE_J *stream);

FILE_J *fopen_j(char *name, char *mode);
int fclose_j(FILE_J *file);
