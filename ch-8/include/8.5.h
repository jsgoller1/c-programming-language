#include <stddef.h>
#include <sys/types.h>

#ifndef MAX_PATH
#define MAX_PATH 255
#endif

void fsize(const char *const name);
void dirwalk(const char *const name, void (*fcn)(const char *const));
