#include <stdio.h>
#define MAXLINE 1000  // maximum input line size

int getline(char line[], int maxline);
char reverse(char string[], int len);
void swap(char string[], int a, int b);

// Write a function reverse(s) that reverses the string given to it

// ALWAYS USE CURLY BRACES, YOU IDIOT

int main() {
  int len, i;          // current line length, and string index
  char line[MAXLINE];  // current input line

  while ((len = getline(line, MAXLINE)) > 0) {
    reverse(line, len);
    printf("%s", line);
  }
  return 0;
}

// reverse(): given a string of len, return the reversed version of it;
// assumes the string was created by getline(), and as such ends with \n\0
char reverse(char string[], int len) {
  int i, end;
  end = len - 2;  // ignore null terminator and newline
  for (i = 0; i < len / 2; i++) {
    swap(string, i, end);
    end--;
  }
}

void swap(char string[], int a, int b) {
  char temp;
  temp = string[a];
  string[a] = string[b];
  string[b] = temp;
}

// getline(): read a line into s, return length
int getline(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
