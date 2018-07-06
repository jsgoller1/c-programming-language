#include <stdio.h>

/*
Exercise 7-4: Write a private version of scanf analogous to minprintf from the
previous section.
--
sc
*/

// minscanf(): private scanf with variable argument list
static void minscanf(char* fmt, ...) {
  // va_list points to each unnamed arg in turn
  va_list ap;
  char *p, *sval;
  int ival;
  double dval;

  // make ap point to first unnamed arg
  va_start(ap, fmt);
  for (p = fmt; *p; p++) {
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

int main() { minscanf("%d %f %s %o %x\n", 10, 20.5, "foobarbaz", 999, 255); }
