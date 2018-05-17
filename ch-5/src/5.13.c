#include "5.13.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

/*
 * Exercise 5-13. Write the program tail, which prints the last n lines of its
 * input. By default, n is 10, let us say, but it can be changed by an optional
 * argument, so that tail -n prints the last n lines. The program should behave
 * rationally no matter how unreasonable the input or the value of n. Write the
 * program so it makes the best use of available storage; lines should be stored
 * as in the sorting program of Section 5.6, not in a two-dimensional array of
 * fixed size.
 * ----------------------------------
 * We will use a queue, and automatically free the nodes exceeding n.
 */

/*
static void test_queue() {
  queue* q = new_queue(2);

  char* string1 = malloc(50);
  strcpy(string1, "first");
  char* string2 = malloc(50);
  strcpy(string2, "second");
  char* string3 = malloc(50);
  strcpy(string3, "third");

  enqueue(q, string1);
  enqueue(q, string2);

  char* string4 = malloc(50);
  dequeue(q, string4);
  printf("dequeued: %s\n", string4);
}

int main() {
  test_queue();
  return 0;
}
*/

// For some reason, VSCode can't see
// this in common.h
#define MAXLEN 1000

// tail(): print the last n lines from input
int main(int argc, char** argv) {
  int line_num;

  if ((line_num = check_input(argc, (const char* const*)argv)) == -1) {
    return -1;
  }

  queue* q = new_queue(line_num);
  read_lines(q);

  char* final_line = malloc(MAXLEN);
  int i = 0;
  while (dequeue(q, final_line) == 1) {
    printf("dequeuing: %d\n", i);
    printf("%s", final_line);
    printf("dequeued: %d\n", i++);
  }

  printf("Ready to free..\n");
  free(final_line);
  return 0;
}

int check_input(const int argc, const char* const* const argv) {
  // if -n is not given, default to 10
  if (argc == 1) {
    return 10;
  }
  // If we get more than 1 arg, ensure that arg 2
  // is "-n" and arg 3 is a valid number, then return
  // arg3 as an int.
  else if (argc == 3 && !(strncmp(argv[1], "-n", 2))) {
    const char* const count = argv[2];
    const int arg_size = (int)strlen(count);

    for (int i = 0; i < arg_size; i++) {
      if (!(isdigit(count[i]))) {
        printf("check_input(): error - n is not a number\n");
        printf("usage: tail -n <line count>\n");
        return -1;
      }
    }
    return (int)atoi(argv[2]);
  } else {
    printf("check_input(): error - too many arguments:\n");
    for (int i = 0; i < argc; i++) {
      printf("arg: %s\n", argv[i]);
    }
    printf("usage: tail -n <line count>\n");
    return -1;
  }
}

queue* new_queue(int max_size) {
  queue* q = malloc(sizeof(queue));

  q->head = NULL;
  q->tail = NULL;
  q->max_size = max_size;
  q->current_size = 0;

  return q;
}

void read_lines(queue* q) {
  char temp_line[MAXLEN];
  unsigned long line_len;

  while (mygetline(temp_line, MAXLEN) != 0) {
    line_len = strlen(temp_line);
    char* line = malloc(line_len + 1);
    strncpy(line, temp_line, line_len);
    line[line_len] = '\0';
    enqueue(q, line);
  }
}

int enqueue(queue* const q, char* data) {
  node* new_tail = malloc(sizeof(node));
  new_tail->data = data;

  // Check if adding our node is allowed given the queue's size
  if (q->current_size < q->max_size) {
    q->current_size++;
  } else if (q->current_size == q->max_size) {
    char* deleted = malloc(MAXLEN);
    dequeue(q, deleted);
    free(deleted);
  } else {
    printf("enqueue(): Error - queue exceeds maximum size.\n");
    free(new_tail);
    return -1;
  }

  // Add the node; handle empty queue if necessary.
  if (q->head == NULL) {
    q->head = new_tail;
    q->tail = new_tail;
  }

  q->tail->next = new_tail;
  q->tail = q->tail->next;

  return 0;
}

int dequeue(queue* const q, char* data) {
  if (q->head == NULL) {
    data = NULL;
    return 0;
  } else if (q->head != NULL && q->tail != NULL) {
    strcpy(data, q->head->data);
    node* old_head = q->head;
    q->head = q->head->next;
    free(old_head);
    return 1;
  } else {
    printf("dequeue(): Error - queue head is not null but tail is?\n");
    data = NULL;
    return -1;
  }
}
