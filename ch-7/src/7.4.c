#include <stdarg.h>
#include <stdio.h>

#pragma clang diagnostic ignored "-Wcast-qual"

/*
Exercise 7-4: Write a private version of scanf
analogous to minprintf from the previous section.
------------------
1. minscanf() is called with a format string and variable arg list.
2. Characters are read from the string until the first scanf()-able char is
read;
3. va_arg is called to get the pointer to scan it into
4. scanf is called, and if the result isn't zero, then scanning contiues
  a. otherwise an error is thrown
*/

// minscanf(): private scanf with variable argument list
static int minscanf(const char* const fmt, ...) {
  // va_list points to each unnamed arg in turn
  va_list ptr;
  int c;
  char* p;
  int* ip;
  double* fp;
  char* sp;

  // make ap point to first unnamed arg
  va_start(ptr, fmt);
  for (p = (char*)fmt; *p; p++) {
    if (*p != '%') {
      if ((c = getchar()) != *p) {
        printf("minscanf() | Ordinary character mismatch; quitting.\n");
        va_end(ptr);
        return -1;
      } else {
        continue;
      }
    }
    switch (*++p) {
      case 'd':
        ip = va_arg(ptr, int*);
        if (scanf("%d", ip) == 0) {
          printf(
              "minscanf() | ERROR: incorrect type / format string provided; "
              "quitting.\n");
          va_end(ptr);
          return -1;
        }
        break;
      case 'f':
        fp = va_arg(ptr, double*);
        if (scanf("%lf", fp) == 0) {
          printf(
              "minscanf() | ERROR: incorrect type / format string provided; "
              "quitting.\n");
          va_end(ptr);
          return -1;
        }
        break;
      case 's':
        sp = va_arg(ptr, char*);
        if (scanf("%s", sp) == 0) {
          printf(
              "minscanf() | ERROR: incorrect type / format string provided; "
              "quitting.\n");
          va_end(ptr);
          return -1;
        }
        break;
      default:
        continue;
    }
  }
  va_end(ptr);  // clean up when done
  return 0;
}

int main() {
  int d;
  double f;
  char s[100];

  if (minscanf("%d - %f - %s\n", &d, &f, s) == 0) {
    printf("%d - %f - %s\n", d, f, s);
  }
}
