#include "fopen_j.h"

// putc(): write to file; check if the IO buffer needs flushing,
// then write to it.
int putc_j(int character, FILE_J* file) {
  if (p->count <= 0) {
    printf("putc_j() | flushing buffer...");
    _flush_buf(character, stream);
    p->count = BUFSIZ;
  }
  p->ptr = character;
  p->ptr++;
  p->count--;
}

/*
_flush_buf: Implements buffered writing. This function is called
when attempting to write to a FILE_J - the buffer is filled (or created) and
putc() puts characters into it until it is large enough to be flushed to the
actual file descriptor. This prevents unnecessary write() syscalls.
*/
int _flush_buf(int stream, FILE_J* file) {
  (void)stream;
  (void)file;
  return 0;
}
