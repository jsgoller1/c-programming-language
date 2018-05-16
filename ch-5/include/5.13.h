typedef struct node {
  struct node* next;
  struct nnode* prev;
  void* data;
} node;

typedef struct {
  node* head;
  node* tail;
} queue;

int check_input(const int argc, const char* const* const argv);

queue* new_queue(void);
void enqueue(queue* const q, const char* const data);
char* dequeue(queue* const q);
