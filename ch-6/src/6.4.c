#include <stdio.h>

#include "common.h"
#include "trees.h"

/*
6-4: Write a program that prints the distinct words in its input sorted into
decreasing order of frequency of occurrence. Precede each word by its count.
------
First, we need to go through the program and count words. We can use a tree
for storing words and retrieving them efficiently, borrowing from crossref.
The ordering of the tree will be by words (i.e. strcmp() results) and each one
will store the number of occurences

Second, we can walk the first tree, and create a second tree - this one
will be ordered by the number of occurrences, and each node will contain words.
Left nodes are <=, right nodes are >.

Third, we walk the second tree pre-order - this will print the nodes in order.
*/

int main() {
  int c;
  char word[MAXLEN];
  while ((c = getword(word, MAXLEN)) != EOF) {
  }
  return 0;
}
