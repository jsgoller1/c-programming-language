#include "2.3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

/*
Ex 2.3: Write the function htoi(s), which converts a string of
hexadecimal digits (including an optional Ox or Ox) into its equivalent integer
value. The allowable digits are 0 through 9, a through f, and A through F.
*/

int main() {
  // 344865
  mytest("0x54321");

  // 74565
  mytest("0X12345");

  // 0
  mytest("0X0");

  // 11184810
  mytest("0xaaaaaa");

  // 1715004
  mytest("0x1A2B3C");

  // 1715004
  mytest("0xFFFFFFFF");

  // ERROR: Invalid length for hex number.
  mytest("0X");

  // ERROR: Invalid hex characters.
  mytest("0X45DBEQQ");

  // ERROR: Invalid length for hex number.
  mytest("");

  // ERROR: Not a hex number
  mytest("12345");

  return 0;
}

int myhtoi(const char* const string, const int len) {
  int val = 0;
  int i, charval;

  if (len < 3) {
    printf("ERROR: Invalid length in hex number %s.\n", string);
    return -1;
  }

  if (string[0] != '0' || !(string[1] == 'x' || string[1] == 'X')) {
    printf("ERROR: '%s' is not a hex number.\n", string);
    return -1;
  }

  for (i = len - 1; i > 1; i--) {
    charval = hex_to_dec(string[i]);
    if (charval == -1) {
      printf("ERROR: %s contains invalid hex characters.\n", string);
      return -1;
    } else {
      val += charval * powi(16, (len - 1) - i);
    }
  }
  return val;
}

int hex_to_dec(const char hex) {
  int val = 0;

  if (hex >= '0' && hex <= '9') {
    val = hex - '0';
  } else {
    switch (hex) {
      case 'A':
      case 'a':
        val = 10;
        break;
      case 'B':
      case 'b':
        val = 11;
        break;
      case 'C':
      case 'c':
        val = 12;
        break;
      case 'D':
      case 'd':
        val = 13;
        break;
      case 'E':
      case 'e':
        val = 14;
        break;
      case 'F':
      case 'f':
        val = 15;
        break;
      default:
        printf("ERROR: %c is not a valid hex character.\n", hex);
        return -1;
    }
  }
  return val;
}

void mytest(const char* const numstring) {
  const int len = (int)strlen(numstring);
  const int dec = myhtoi(numstring, len);
  if (dec == -1) {
    return;
  } else {
    printf("%s = %u\n", numstring, dec);
  }
}
