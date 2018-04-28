typedef struct ir {
  int quotes;          // number of "
  int ticks;           // number of '
  int parens;          // number of ( or )
  int curlys;          // number of { or }
  int squares;         // number of [ or ]
  int comment_braces;  // number of /
} input_registry;

/*
typedef struct ps {
  int in_single_comment;  // are we in a // comment?
  int in_multi_comment;   // are we in a /* comment?
  int in_single_quote;    // are we in a 'single quote'?
  int in_double_quote;    // are we in "double quotes"?
  int should_parse;       // should we count any symbols we see?
} parsing_state;
*/

void comment_quote_test(const int c1, int* const in_single_comment,
                        int* const in_multi_comment, int* const in_single_quote,
                        int* const in_double_quote);
void input_test(const int c1, input_registry* const ir);
void print_output(const input_registry* const ir);
