#include <stdio.h>
#include <string.h>

/*
 * The documentation for strcmp(char* a, char* b) says it returns a value based
 * on whether a is "lexicographically greater" than b; what exactly does this
 * mean?
 */

static void compare(const char* const a, const char* const b) {
  int result = strcmp(a, b);
  printf("comparing: %s and %s: %d\n", a, b, result);
}

int main() {
  // How is the return value calculated?
  // Answer: The first character in which the strings differ
  // is found, the second string's character is subtracted from the first's.
  // So, a comes before b in the alphabet, meaning that the result of
  // strcmp(a,b) will be negative, whereas strcmp(b, a) will be positive.
  compare("CATx", "CATz");
  printf("%c (%d) - %c (%d): %d\n", 'x', 'x', 'z', 'z', 'x' - 'z');

  // If just the first letter in which the strings differ is used,
  // do the preceeding characters make a difference?
  // Answer: No, the result is the same.
  compare("AAAAAAAz", "AAAAAAAx");
  compare("ZZZZZZZz", "ZZZZZZZx");

  // Does the length of the string matter?
  // Answer: No, just the last character.
  compare("a", "z");
  compare("aa", "zz");

  // Does the order of the arguments matter?
  // Answer: Yes - but you get the negative version of the same answer.
  compare("aa", "zz");
  compare("zz", "aa");

  // What about for case-different versions of the same string?
  // Answer: Same answer, as long as the case is consistent
  compare("AA", "ZZ");
  compare("aa", "zz");

  return 0;
}
