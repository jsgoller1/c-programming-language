#include <stdarg.h>
#include <stdio.h>

#pragma clang diagnostic ignored "-Wcast-qual"

/*
 * Revise minprintf to handle more of the other facilities of printf()
 */

// minprintf(): minimal printf with variable argument list
static void minprintf(const char* const fmt, ...) {
  // va_list points to each unnamed arg in turn
  va_list ap;
  char *p, *sval;
  int ival;
  double dval;

  // make ap point to first unnamed arg
  va_start(ap, fmt);
  for (p = (char*)fmt; *p; p++) {
    if (*p != '%') {
      putchar(*p);
      continue;
    }
    switch (*++p) {
      case 'd':
        ival = va_arg(ap, int);
        printf("%d", ival);
        break;
      case 'f':
        dval = va_arg(ap, double);
        printf("%f", dval);
        break;
      case 's':
        for (sval = va_arg(ap, char*); *sval; sval++) {
          putchar(*sval);
        }
        break;
      case 'o':
        ival = va_arg(ap, int);
        printf("%o", ival);
        break;
      case 'x':
        ival = va_arg(ap, int);
        printf("%x", ival);
        break;
      default:
        putchar(*p);
        break;
    }
  }
  va_end(ap);  // clean up when done
}

int main() {
  minprintf("%d %f %s %o %x\n", 10, 20.5, "foobarbaz", 999, 255);
  return 0;
}
