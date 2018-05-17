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
 * The easiest way to do this would be to seek to the end of input and then
 * read back until we see n newlines. But we can't do this with stdin,
 * so we can use a queue to handle arbitrary input. Every line we read is
 * enqueued; if we read more than n lines, we dequeue one line every time we
 * enqueue a new one. Once all input is read, we empty the queue and print each
 * line.
 */

// For some reason, VSCode can't see
// this in common.h
#define MAXLEN 1000

// tail(): print the last n lines from input
int main(int argc, char** argv) {
  const int line_num = check_input(argc, (const char* const*)argv);

  if (line_num == -1) {
    return -1;
  } else if (line_num == 0) {
    return 0;
  }

  queue* q = new_queue(line_num);
  read_lines(q);

  char* final_line = malloc(MAXLEN);
  while (dequeue(q, final_line) == 1) {
    printf("%s", final_line);
  }

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
  // Check if adding our node is allowed given the queue's size
  if (q->current_size == q->max_size) {
    char* deleted = malloc(MAXLEN);
    dequeue(q, deleted);
    free(deleted);
  } else if (q->current_size > q->max_size) {
    printf("enqueue(): Error - queue exceeds maximum size.\n");
    return -1;
  }

  node* new_tail = malloc(sizeof(node));
  new_tail->next = NULL;
  new_tail->data = data;

  // Add the node; handle empty queue if necessary.
  if (q->head == NULL) {
    q->head = new_tail;
    q->tail = new_tail;
  }

  q->tail->next = new_tail;
  q->tail = q->tail->next;
  q->current_size++;

  return 0;
}

int dequeue(queue* const q, char* data) {
  if (!(q->current_size && q->head)) {
    data = NULL;
    return 0;
  } else {
    node* old_head = q->head;
    strcpy(data, old_head->data);
    q->head = old_head->next;

    free(old_head);
    q->current_size--;
    return 1;
  }
}
