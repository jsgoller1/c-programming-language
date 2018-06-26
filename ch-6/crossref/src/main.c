#include <alloca.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "crossref.h"

int main() {
  int c = 0;
  int line_count = 1;
  char word[MAX_WORD];
  word_node* head = NULL;
  word_node* current = NULL;

  while ((c = getword(word)) != EOF) {
    if (head == NULL) {
      head = create_node(word);
    }

    // see if we've encountered the word before
    if ((current = tree_search(word, head)) == NULL) {
      current = tree_insert(word, head);
    }

    // add this line to the word's list of lines
    if (add_line(current, line_count) == -1) {
      return -1;
    }

    // bump line count if we are going to the next line
    if (c == '\n') {
      line_count++;
    }
  }

  // display tree contents, then cleanup and exit
  tree_walk(head);
  tree_cleanup(head);
  return 0;
}
