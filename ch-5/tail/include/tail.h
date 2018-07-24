typedef struct node {
  struct node* next;
  char* data;
} node;

typedef struct {
  node* head;
  node* tail;
  int current_size;
  int max_size;
} queue;

int check_input(const int argc, const char* const* const argv);
int read_lines(queue* const q);

// queue.c
queue* new_queue(const int max_size);
int enqueue(queue* const q, const char* const data);
int dequeue(queue* const q, char* data);
