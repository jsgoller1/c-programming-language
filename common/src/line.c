#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

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
    line[i] = (char)c;
  }
  if (c == '\n') {
    line[i] = (char)c;
    ++i;
  }
  line[i] = '\0';
  // printf("getline(): %d bytes.\n", i);
  return i;
}

// declare lineptr as const pointer to pointer to const char; the pointers to
// the strings will change as we copy them in, but the array pointer should not
// mutate and the chars in the strings shouldn't either.

// readlines(): read input lines into a string buffer
int readlines(char **lineptr, const int maxlines) {
  int len, line_count;
  char *p, temp_line[MAXLEN];

  line_count = 0;
  for (int i = 0; line_count <= maxlines; i++) {
    if ((len = mygetline(temp_line, MAXLEN)) > 1) {
      p = malloc((unsigned long)len + 1);
      strncpy(p, temp_line, (unsigned long)len);
      p[len] = '\0';
      lineptr[line_count++] = p;
    } else {
      break;
    }
  }
  return line_count;
}

// declare lineptr as const pointer to const pointer to const char; the array
// pointer, string pointers, and chars in the strings should not mutate
// writelines(): write output lines from a string buffer
void writelines(char **lineptr, const int nlines) {
  int i;

  for (i = 0; i < nlines; i++) {
    printf("%s", lineptr[i]);
  }
}

// freelines(): frees all lines read in via readline()
void freelines(char **lineptr, const int nlines) {
  for (int i = 0; i < nlines; i++) {
    free(lineptr[i]);
  }
}

// getword(): reads characters into word, and returns the len.
// getword() always reads at least one valid character or EOF character, but
// will stop parsing after it reads the first whitespace character.
int getword(char *word, const int len) {
  if (word == NULL || len < 2) {
    return -1;
  }

  int c = 0;
  int i = 0;

  c = getchar();
  // do nothing for EOF
  if (c == EOF) {
    return i;
  }  // return a single char string for space characters
  else if (isspace(c)) {
    word[i++] = (char)c;
    word[i] = '\0';
    return i;
  }  // return a full word
  else {
    word[i++] = (char)c;
    while (((c = getchar()) != EOF) && (i < len - 1)) {
      if (!(isspace(c))) {
        word[i++] = (char)c;
      } else {
        ungetc(c, stdin);
        break;
      }
    }
    word[i] = '\0';
    return i;
  }
}

// gettoken(): similar to getword(), except that gettoken() looks for characters
// that are syntactically relevant to a C program instead of just alphanumeric
// words and ignores whitespace. Always reads at least one valid character or
// EOF character, but will stop parsing when it reads the first non-alphanum
// character. Returns number of chars read.
int gettoken(char *word, const int len) {
  int c = 0;
  int i = 0;

  while (((c = getchar()) != EOF) && i < len) {
    if (!isalnum(c) && c != '_') {
      if (i == 0) {
        word[i++] = (char)c;  // always read at least one char
        break;
      } else {
        ungetc(c, stdin);
        break;
      }
    } else {
      word[i++] = (char)c;
    }
  }
  word[i] = '\0';
  return i;
}

/*
int gettoken(char *word, const int len) {
  if (word == NULL || len < 2) {
    return -1;
  }

  int c = 0;
  int i = 0;

  c = getchar();
  // do nothing for EOF
  if (c == EOF) {
    return i;
  }  // return a single char string for syntactic characters
  else if (!(isalnum(c))) {
    word[i++] = (char)c;
    word[i] = '\0';
    return i;
  }  // return a full word
  else {
    word[i++] = (char)c;
    while (((c = getchar()) != EOF) && (i < len - 1)) {
      if (isalnum(c)) {
        word[i++] = (char)c;
      } else {
        ungetc(c, stdin);
        break;
      }
    }
    word[i] = '\0';
    return i;
  }
}
*/
