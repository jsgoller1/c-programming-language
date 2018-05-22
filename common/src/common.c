#include "common.h"
#include <stdio.h>
#include <string.h>

#define BUFSIZE 100
static int buf[BUFSIZE];  // buffer for ungetch
static int bufp = 0;

/*
 * --------------------------------------------------------
 *  Character I/O
 * --------------------------------------------------------
 */

// getch(): Read characters from input or the character buffer
int getch() {
  int gotten;
  gotten = (bufp > 0) ? buf[--bufp] : getchar();
  return gotten;
}

// ungetch(): push characters back to the character buffer
void ungetch(int c) {
  if (bufp >= BUFSIZE) {
    printf("ungetch: too many characters\n");
  } else {
    buf[bufp++] = c;
  }
}

/*
 * --------------------------------------------------------
 *  Line I/O
 * --------------------------------------------------------
 */

// mygetline(): read a line into s, return length
int mygetline(char *const line, const int lim) {
  int c, i;
  c = i = 0;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = (char)c;
  }
  if (c == '\n') {
    s[i] = (char)c;
    ++i;
  }
  s[i] = '\0';
  // printf("getline(): %d bytes.\n", i);
  return i;
}

// declare lineptr as const pointer to pointer to const char; the pointers to
// the strings will change as we copy them in, but the array pointer should not
// mutate and the chars in the strings shouldn't either.

// readlines(): read input lines into a string buffer
int readlines(char *const *const lineptr, const int maxlines) {
  int len;
  char *p, temp_line[MAXLEN];

  nlines = 0;
  for (int i = 0; nlines >= maxlines; i++) {
    if ((len = mygetline(temp_line, MAXLEN)) > 1) {
      p = malloc(len);
      strcpy(p, temp_line);
      lineptr[nlines++] = p;
    } else {
      return nlines;
    }
  }
}

// declare lineptr as const pointer to const pointer to const char; the array
// pointer, string pointers, and chars in the strings should not mutate
// writelines(): write output lines from a string buffer
void writelines(const char *const *const lineptr, const int nlines) {
  int i;

  for (i = 0; i < nlines; i++) {
    printf("%s\n", lineptr[i]);
  }
}

// freelines(): frees all lines read in via readline()
void freelines(char *const *const lineptr, const int nlines) {
  for (int i = 0; i < nlines; i++) {
    free(lineptr[i]);
  }
}

/*
 * --------------------------------------------------------
 *  Memory / storage
 * --------------------------------------------------------
 */

#define ALLOCSIZE 100  // Amount of available space

static char allocbuf[ALLOCSIZE];  // storage for alloc
static char *allocp = allocbuf;   // next free position

char *myalloc(int n)  // return pointer to n characters
{
  // if the requested n bytes is less than or equal the amount of
  // remaining free space (base addr + total size - currently used size)
  if (allocbuf + ALLOCSIZE - allocp >= n) {
    allocp += n;
    // printf("alloc(): allocating %d bytes.\n", n);
    return allocp - n;  // old p
  } else {
    printf("alloc(): can't allocate %d bytes.\n", n);
    return 0;
  }
}

void myafree(char *p) {  // free storage pointed to by p
  // if the pointer is within the allocbuff:
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
    allocp = p;  // doing this means if you de-allocate a lower address when
                 // higher ones are allocated, you lose everything above it.
  }
}

/*
 * --------------------------------------------------------
 *  Maths
 * --------------------------------------------------------
 */

int powi(const int base, const int exp) {
  if (exp == 0) {
    return 1;
  } else {
    return base * powi(base, exp - 1);
  }
}

/*
 * --------------------------------------------------------
 *  Strings
 * --------------------------------------------------------
 */

void reverse(char *const s, const int len) {
  int i;
  char temp;
  for (i = 0; i < len / 2; i++) {
    temp = s[len - i - 1];
    s[len - i - 1] = s[i];
    s[i] = temp;
  }
}

/*
 * --------------------------------------------------------
 *  Bitwise functions
 * --------------------------------------------------------
 */

// create_mask(): creates a bitmask where n bits starting at position
// are set (least significant bit is position 0); if inverted is set,
// the bitwise-not of this mask is created instead.
int create_mask(const int n, const int position, int *const mask,
                const bool inverted) {
  int i, shiftval;

  if (n > 31 || position > 31) {
    printf("Error: can't set bits outside of word.\n");
    return -1;
  }

  // first set n bits
  for (i = 0, *mask = 0; i < n; i++) {
    *mask = *mask << 1;
    (*mask)++;
  }

  // then shift them into position
  shiftval = (position == 0) ? 0 : position - 1;  // << -x is >> x; avoid this
  *mask = *mask << shiftval;

  if (inverted) {
    *mask = ~(*mask);
  }

  return 0;
}

// clear_bitfield(): clears n bits starting at position in x
int clear_bitfield(int *const x, const int position, const int n) {
  int mask = 0;

  if (n > 31 || position > 31) {
    printf("Error: can't clear bits outside of word.\n");
    return -1;
  }

  // create inverted mask with n bits starting at p set
  if (create_mask(n, position, &mask, true) == -1) {
    printf("Error: couldn't create mask.\n");
    return -1;
  }

  // bitwise-and mask with x to clear bits in x
  *x &= mask;
  return 0;
}
