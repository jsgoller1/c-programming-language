typedef struct ir {
  int quotes;
  int ticks;
  int parens;
  int curlys;
  int squares;
  int comment_braces;
} input_registry;

void comment_test(int c1, int* in_single_comment, int* in_multi_comment);
void input_test(int c1, input_registry* ir);
void print_output(input_registry* ir);
