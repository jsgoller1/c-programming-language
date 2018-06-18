#include <stdio.h>

/* Write a program that converts upper case to lower
 * or lower case to upper, depending on the name it
 * is invoked with, as found in argv[0].
 */

int main(int argc, char** argv) {
  if (argc < 1) {
    print("usage: caser -[ul] <string>");
    return -1;
  }

  if (strcmp("-u", argv[1]){
    // TODO: convert to uppercase
  } else if (strcmp("-l", argv[1]){
    // TODO: convert to lowercase
  } else {
    print("usage: caser -[ul] <string>");
    return -1;
  }
    return 0;
}
