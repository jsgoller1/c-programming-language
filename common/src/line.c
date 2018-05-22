
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
