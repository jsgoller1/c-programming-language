#include "6.1.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "common.h"

/*
  The listed version of getword() doesn't handle:
  underscores - _int
  comments - // int
  preprocessor directives - # if
  string constants - char foo[] = {"int if"}

  Write a better version that handles these correctly.
  ---
  Note - both K&R and The C Answer book don't specify
  whether we are supposed to treat all input as one line or not,
  so I'm assuming we will.
*/

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof(struct key))

struct key {
  char *word;
  int count;
};

char getword(char *, int);
int mybinsearch(char *word, struct key *tab, int n);

static struct key keytab[] = {
    {"auto", 0},   {"break", 0},    {"case", 0},     {"char", 0},
    {"const", 0},  {"continue", 0}, {"default", 0},  {"do", 0},
    {"double", 0}, {"else", 0},     {"enum", 0},     {"extern", 0},
    {"float", 0},  {"for", 0},      {"goto", 0},     {"if", 0},
    {"inline", 0}, {"int", 0},      {"long", 0},     {"register", 0},
    {"return", 0}, {"short", 0},    {"signed", 0},   {"sizeof", 0},
    {"static", 0}, {"struct", 0},   {"switch", 0},   {"typedef", 0},
    {"union", 0},  {"void", 0},     {"volatile", 0}, {"while", 0}};

// mybinsearch: find word in tab[0]...tab[n-1]
int mybinsearch(char *word, struct key tab[], int n) {
  int cond;
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if ((cond = strcmp(word, tab[mid].word)) < 0) {
      high = mid - 1;
    } else if (cond > 0) {
      low = mid + 1;
    } else {
      return mid;
    }
  }

  return -1;
}

// getword(): get next word or character from input
char getword(char *word, int lim) {
  char c;
  char *w = word;

  // noop, skip whitespace
  while (isspace(c = getch())) {
  }

  if (c != EOF) {
    *w = c;
    w++;
  }

  if (!isalpha(c)) {
    *w = '\0';
    return c;
  }

  for (; --lim > 0; w++) {
    if (!isalnum(*w = getch())) {
      ungetch(*w);
      break;
    }
  }
  *w = '\0';
  // printf("Returning %s\n", word);
  return word[0];
}

int main() {
  int n;
  char word[MAXWORD];
  char firstchar;
  int slashmarks = 0;

  // states
  bool ignore_line = false;  // we are in a comment or preprocessor directive
  bool in_string = false;  // we are in a string and waiting for a closing quote
  bool got_underscore = false;  // we just got an underscore, don't count the
                                // next word as a keyword

  // get the first character of every "word" from stdin;
  // keep track of state and do the syntatically correct
  // thing depending on what state we are in
  while ((firstchar = getword(word, MAXWORD)) != EOF && !(ignore_line)) {
    if (isalpha(firstchar) && firstchar != '_' && !(in_string)) {
      if ((n = mybinsearch(word, keytab, NKEYS)) >= 0) {
        keytab[n].count++;
      }
    } else {
      printf("Switching on: %c\n", firstchar);
      switch (firstchar) {
        case '/':
          slashmarks++;
          if (slashmarks == 2) {
            printf("Now in a comment; ignoring newlines.\n");
            ignore_line = true;
          }
          break;
        case '#':
          printf("Now in a preprocessor directive; ignoring newlines.\n");
          ignore_line = true;
          break;
        case '_':
          printf("Got an underrscore, skipping next word.\n");
          got_underscore = true;
          break;
        case '"':
          break;
        case '\n':
          printf("Got a newline, can now count lines again.\n");
          ignore_line = false;
          break;
        default:
          break;
      }
    }
  }

  for (n = 0; n < (int)NKEYS; n++) {
    if (keytab[n].count > 0) {
      printf("%4d %s\n", keytab[n].count, keytab[n].word);
    }
  }
  return 0;
}
