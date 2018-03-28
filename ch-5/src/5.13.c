#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "5-common.h"

/*
Exercise 5-13. Write the program tail, which prints the last n lines of its
input. By default, n is 10, let us say, but it can be changed by an optional
argument, so that
tail -n
prints the last n lines. The program should behave rationally no matter how
unreasonable the input or the value of n. Write the program so it makes the
best use of available storage; lines should be stored as in the sorting program
of Section 5.6, not in a two-dimensional array of fixed size.

/ *****************************************************************************

Design / considerations
------------------------

1) We will get m lines of input; we don't know if m > n, m < n, or m == n.
2) We need to keep the order of the lines recieved.
3) We can safely ignore lines that are not in the n last.
4) We don't know when the input will terminate (i.e. when we will get an EOF)
5) We don't know how much input we will recieve before a newline

Given 1 - 3, it seems that a FIFO data structure (i.e. a queue) is the right
approach; we should queue every line we get, and if on appending the queue size
ever exceeds n, we should remove the last item from the queue.

Given 3 and 4 and the memory efficient demand in the problem statement, we
should only queue pointers to the strings, not the strings themselves.

Additionally, we should use just enough memory to store the string; we can
obtain that length by reading the string into a large-but-fixed temporary
buffer of size MAX_LEN, and then using malloc() to get just enough space and
copying it over to the allocated space - this way, we avoid a large 2D
fixed-size array. Note that GNU tail can handle arbitrarily long lines - this
approach will overflow the temporary buffer if lines are longer than MAX_LEN. We
can probably think of some ways to overcome this issue (like "chunking up" the
strings themselves by storing them as linked lists of n-character substrings and
pointers to the next n characters, but this would necessitate more calls to
malloc() and free(), which could cause their own performance issues).

Implementing the queue will be tricky; naively, we could create an array
of n pointers when the program starts, but this will cause problems when we
read in the n+1th line - we would have to remove the 0th pointer in the array
and "push back" each pointer after it to make room for the n+1th pointer.

A better solution is to use a linked list for our queue; each node can consist
of a pointer to the next node and a pointer to the respective line of input. We
can store references to the first node and the most recent one, so enqueuing
another node would simply mean dequeuing the first node, setting the new first
node to the current first's next node, and then enqueuing the most recent line
as the last node's next.

When reading ends, we can walk the list and print every node, which will print
all lines.

Suppose we had an example where we read 4 lines in, but n = 3; A graphical
representation would look like:

[*][*]----> This is line #0; n = 3; // this line was dequeued and cleaned up
                                    // when line #3 was queued

[*][*]----> This is line #1; n = 3;
 |
 V
[*][*]----> This is line #2; n = 3;
 |
 V
[*][*]----> This is line #3; n = 3;
 |
 V
NULL

This example would print:
This is line #1; n = 3
This is line #2; n = 3
This is line #3; n = 3

We have not learned about structs yet but I'm going to use them anyway because
it's the cleanest approach for implementing linked list nodes.
*/

// the maximum character count of a line given to tail()
#define MAXLINE 1000

// tail(): print the last n lines from input
int main(int argc, char* argv[]) {
  printf("%d\n", argc);
  int line_num = 0;
  if (argc == 1) {
    line_num = 10;
  }
  // If we get more than 1 arg, ensure that arg 2 is "-n" and arg 3 is a valid
  // number
  else if (argc == 3 && !(strncmp(argv[1], "-n", 2))) {
    char c;
    for (int i = 0; (c = argv[2][i]) != '\0'; i++) {
      if (!(isdigit(c))) {
        printf("usage: tail -n <line count>\n");
        return -1;
      }
    }
    line_num = atoi(argv[2]);
  } else {
    printf("usage: tail -n <line count>\n");
    return -1;
  }

  // begin reading lines in; temporarily
  // store lines in the temp_line buffer and
  // copy them out to actual heap lines, and
  // push those into a queue of lines that will be printed at the end.
  char* lines[line_num];
  char temp_line[MAXLINE];

  return 0;
}
