#include <stdbool.h>
#include <stddef.h>

#define BUF_SIZE 10

typedef struct _flags {
  bool _READ;
  bool _WRITE;
  bool _UNBUF;
  bool _EOF;
  bool _ERR;
  char _align[3];  // do not use, aligns struct to 8B
} _flags;

typedef struct _iobuf {
  int fd;        // (4B) file descriptor
  int dirty;     // (4B) set if the buffer has been written to.
  char *buff;    // (8B) pointer to I/O buffer
  char *ptr;     // (8B) next character position within I/O buffer
  _flags flags;  // (8B)
} FILE_J;

#define feof(p) (((p)->flag & _EOF) != 0)
#define ferror(p) (((p)->flag & _ERR) != 0)
#define fileno(p) ((p)->fd)

#define getchar() getc(stdin)
#define putchar(x) putc((x), stdout)

FILE_J *fopen_j(const char *const name, const char *const mode);
int fclose_j(FILE_J *file);

int getc_j(FILE_J *file);
int _fill_buff(FILE_J *file);
int putc_j(int character, FILE_J *stream);
int _flush_buff(FILE_J *file);
int fflush_j(FILE_J *stream);
int fseek_j(FILE_J *fp, long offset, int origin);
