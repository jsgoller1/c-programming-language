#include "1.19.h"
#include <stdio.h>
#include "common.h"

/*
Ex 1.19: Write a function reverse(s) that reverses the character
string s. Use it to write a program that reverses its input a line
at a time.
*/

int main() {
  int len;             // current line length, and string index
  char line[MAXLINE];  // current input line

  while ((len = mygetline(line, MAXLINE)) > 0) {
    reverse(line, len);
    printf("%s", line);
  }
  return 0;
}

// reverse(): given a string of len, return the reversed version of it;
// assumes the string was created by getline(), and as such ends with \n\0
void reverse(char string[], const int len) {
  int i, end;
  end = len - 2;  // ignore null terminator and newline
  for (i = 0; i < len / 2; i++) {
    swap(string, i, end);
    end--;
  }
}

// swap(): exchange string[a] with string[b]
void swap(char string[], const int a, const int b) {
  char temp;
  temp = string[a];
  string[a] = string[b];
  string[b] = temp;
}
