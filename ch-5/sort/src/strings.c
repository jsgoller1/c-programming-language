#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "sort.h"

// index(): get first occurence of character in string
int indexof(char* string, char character) {
  for (int i = 0; i < (int)strlen(string); i++) {
    // printf("indexof() | evaluating %c\n", string[i]);
    if (string[i] == character) {
      return i;
    }
  }
  return -1;
}

// split(): given a string and an offset into it,
// divide the string into substrings divided by splitchar,
// and return the number of them created (analagous to Python's str.split()
// method)
int split(char* string, int offset, char splitchar, char** substrings) {
  if (string == NULL) {
    return -1;
  }
  if (substrings == NULL) {
    return -1;
  }

  int len = (int)strlen(string);
  if (offset >= len) {
    return -1;
  }

  int j, k;
  for (j = 0, k = 0; offset < len; offset++) {
    // get memory for next substring; string is never longer
    // than MAXLEN, so it won't be possible for any substring to exceed
    // this length
    // TODO: Catch this malloc if it fails
    substrings[j] = malloc(MAXLEN * sizeof(char));
    char* current = substrings[j++];

    // copy characters out of string until we hit a splitchar or null
    // terminator
    while (string[offset] != splitchar && string[offset] != '\n' &&
           string[offset] != '\0') {
      current[k++] = string[offset++];
    }
    current[k] = '\0';
    k = 0;
  }

  return j;
}

// split(): given an array of strings, combine them into one
// string with each substring divided by joinstr (similar
// to python's str.join() method), followed by a null terminator;
// string is assumed to be of sufficient size and will be overflowed if too
// small. We have to
int join(char** substrings, int count, char* joinstr, char* string) {
  if (substrings == NULL || joinstr == NULL || string == NULL) {
    return -1;
  }

  for (int i = 0; i < count; i++) {
    strcat(string, substrings[i]);
    strcat(string, joinstr);
  }

  // remove last joinchar
  string[strlen(string) - 1] = '\n';
  string[strlen(string)] = '\0';

  return 0;
}
