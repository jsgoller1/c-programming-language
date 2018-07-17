#include "common.h"

/*
 * --------------------------------------------------------
 *  Strings
 * --------------------------------------------------------
 */

void reverse(char *const s, const int len) {
  int i;
  char temp;
  for (i = 0; i < len / 2; i++) {
    temp = s[len - i - 1];
    s[len - i - 1] = s[i];
    s[i] = temp;
  }
}
