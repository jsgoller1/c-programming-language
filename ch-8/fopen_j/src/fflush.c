#include "fopen_j.h"

// fflush_j(): empty a FILE_J's buffer to its file descriptor
int fflush_j(FILE_J* fp) {
  _flush_buf(fp);
  return 0;
}
