#include "fopen_j.h"

// fseek(): on a seekable file, change the file offset.
int fseek_j(const FILE_J *const fp, const long offset, const int whence) {
  // Ensure valid whence
  switch (whence) {
    case SEEK_SET:
    case SEEK_CUR:
    case SEEK_END:
    case SEEK_HOLE:
    case SEEK_DATA:
      break;
    default:
      printf("fseek() | invalid whence.\n");
      return -1;
  }

  lseek(fp->fd, offset, whence);

  // determine if buffer should be flushed or not based on seek.

  return 0;
}
