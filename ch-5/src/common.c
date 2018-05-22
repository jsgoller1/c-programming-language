#include "common.h"
#include <stdio.h>
#include <string.h>

#define BUFSIZE 100
static int buf[BUFSIZE];  // buffer for ungetch
static int bufp = 0;

/*
--------------------------------------------------------
 Character I/O
--------------------------------------------------------
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
--------------------------------------------------------
 Line I/O
--------------------------------------------------------
*/

// mygetline(): read a line into s, return length
int mygetline(char s[], int lim) {
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
--------------------------------------------------------
 Memory / storage
--------------------------------------------------------
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
