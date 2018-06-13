#include "fopen_j.h"

#define putc(x, p) \
  (--(p)->cnt >= 0 ? *(p)->ptr++ = (x) : _buffered_write((x), p))

// putc(): write a character to a file stream
int putc(int character, FILE_J* stream) {}

/*
_buffered_write: Implements buffered writing. This function is called
when attempting to write to a FILE_J - the buffer is filled (or created) and
putc() puts characters into it until it is large enough to be flushed to the
actual file descriptor. This prevents unnecessary write() syscalls.
*/
int _flush_buf(int stream, FILE_J* file) {
  (void)stream;
  (void)file;
  return 0;
}
