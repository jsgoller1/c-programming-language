#include <stdio.h>

// Write an alternative version of squeeze() that deletes
// any character in s1 that is found in another string s2

void squeeze(char s1[], char s2[]);

int main() {
  char string1[] = {"dog food tastes good!"};
  char string2[] = {"dgft"};
  printf("%s - removing '%s': ", string1, string2);
  squeeze(string1, string2);
  // o oo ases oo!
  printf("%s\n", string1);

  char string3[] = {"dog food tastes good!"};
  char string4[] = {""};
  printf("%s - removing '%s': ", string3, string4);
  squeeze(string3, string4);
  // dog food tastes good!
  printf("%s\n", string3);

  char string5[] = {""};
  char string6[] = {"dog food tastes good!"};
  printf("%s - removing '%s': ", string5, string6);
  squeeze(string5, string6);
  // empty
  printf("%s\n", string5);
  return 0;
}

// delete all c from s
void squeeze(char s1[], char s2[]) {
  int i = 0;  // keeps track of our current place in s1 that we are able to put
              // the next letter at
  int j;      // used for looping through s2
  int k;      // keeps track of the current letter in s1 under consideration
  int MATCH_FOUND;
  for (k = 0; s1[k] != '\0'; k++) {
    MATCH_FOUND = 0;
    for (j = 0; s2[j] != '\0' && !MATCH_FOUND; j++) {
      if (s1[k] == s2[j]) {
        MATCH_FOUND = 1;
      }
    }

    if (!MATCH_FOUND) {
      s1[i++] = s1[k];
    }
  }
  s1[i] = '\0';
}