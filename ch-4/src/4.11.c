#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>  // for atof()

// Ex. 4.11 - Modify getop so that it doesn't need to use ungetch. Hint: use an
// internal static variable.

#define MAXOP 100   // max size for operand or operator
#define MAXVAL 100  // maximum depth of val stack
#define NUMBER '0'
static int c = ' ';

static int sp = 0;
static double val[MAXVAL];

// push() - push f onto value stack
static void push(const double f) {
  if (sp < MAXVAL) {
    val[sp++] = f;
  } else {
    printf("Error; stack full - can't push %g\n", f);
  }
}

// pop: pop and return top value from stack
static double pop() {
  if (sp > 0) {
    return val[--sp];
  } else {
    printf("Error: stack empty\n");
    return 0.0;
  }
}

// getop: get next operator or numeric operand
static int getop(char* const s) {
  int i;

  while (((s[0] = (char)c) == ' ') || (c == '\t')) {
    // no op; get all characters until a space/tab/newline is hit
    c = getchar();
  }
  s[1] = '\0';
  if (!isdigit(c) && c != '.') {
    return c;  // if not a number or floating point
  }
  i = 0;
  if (isdigit(c))  // collect integer part
  {
    while (isdigit(s[++i] = c = (char)getchar())) {
      // no-op
    }
  }
  if (c == '.')  // collect fractional part
  {
    while (isdigit(s[++i] = c = (char)getchar())) {
      // no-op
    }
  }
  s[i] = '\0';
  return NUMBER;
}

// Reverse Polish calculator
int main() {
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
      case NUMBER:
        push(atof(s));
        c = ' ';
        break;
      case '+':
        push(pop() + pop());  // commutative; pop() order is irrelevant
        c = ' ';
        break;
      case '*':
        push(pop() * pop());  // commutative; pop() order is irrelevant
        c = ' ';
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        c = ' ';
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0) {
          push(pop() / op2);
        } else {
          printf("Error: div by zero");
        }
        c = ' ';
        break;
      case '\n':
        printf("\t%.8g\n", pop());
        c = ' ';
        break;
      default:
        printf("error: unknown command %s\n", s);
        break;
    }
  }
  return 0;
}
