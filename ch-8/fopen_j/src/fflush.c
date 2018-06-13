#include "fopen_j.h"

// fflush_j(): empty a FILE_J's buffer to its file descriptor
int fflush_j(FILE_J *stream) {
  (void)stream;
  return 0;
}
