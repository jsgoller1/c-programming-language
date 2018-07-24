#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "tail.h"

#pragma clang diagnostic ignored "-Wcast-qual"

// new_queue(): Initialize a queue structure
queue* new_queue(const int max_size) {
  queue* q = malloc(sizeof(queue));

  q->head = NULL;
  q->tail = NULL;
  q->max_size = max_size;
  q->current_size = 0;

  return q;
}

// enqueue(): add an item to the queue
int enqueue(queue* const q, const char* const data) {
  if (q->current_size == q->max_size) {
    // If the queue is full, dequeue the last item to make room
    char* deleted = malloc(MAXLEN);
    dequeue(q, deleted);
    // handle special edgecase for one-node-max queue
    if (q->max_size == 1) {
      q->head = NULL;
    }
    free(deleted);
  } else if (q->current_size > q->max_size) {
    printf("enqueue(): Error - queue exceeds maximum size.\n");
    return -1;
  }

  // Make a new node
  node* new_tail = malloc(sizeof(node));
  new_tail->next = NULL;
  new_tail->data = (char*)data;

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

// dequeue(): remove an item from the queue
int dequeue(queue* const q, char* const data) {
  if (!(q->current_size && q->head)) {
    // Queue is empty
    *data = '\0';
    return 0;
  } else {
    // Remove current head; make the next item the new head
    node* old_head = q->head;
    strcpy(data, old_head->data);
    q->head = old_head->next;

    free(old_head->data);
    free(old_head);
    q->current_size--;
    return 1;
  }
}
