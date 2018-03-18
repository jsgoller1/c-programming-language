#include <stdio.h>

void strcat(char s[], char t[]);

int main() {
  char stringa[14] = {"Joshua "};
  char stringb[] = {"Goller"};
  strcat(stringa, stringb);
  printf("%s\n", stringa);

  return 0;
}

// strc: concatenate t to end of s; s must be big enough
void strcat(char s[], char t[]) {
  int i, j;

  i = j = 0;
  while (s[i] != '\0')  // find end of s
  {
    i++;
  }
  while ((s[i++] = t[j++]) != '\0') {
    // nothing to do here
  }
}