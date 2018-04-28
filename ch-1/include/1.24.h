// store for syntactically relevant symbols
typedef struct ir {
  int parens;          // number of ( or )
  int curlys;          // number of { or }
  int squares;         // number of [ or ]
  int comment_braces;  // number of /
} input_registry;

// states for parser FSM
typedef struct ps {
  int in_single_comment;  // are we in a // comment?
  int in_multi_comment;   // are we in a /* comment?
  int in_single_quote;    // are we in a 'single quote'?
  int in_double_quote;    // are we in "double quotes"?
  int should_parse;       // should we count any symbols we see?
} parsing_state;

void parsing_test(const int c, parsing_state* ps);
void input_test(const int c1, input_registry* const ir);
void print_output(const input_registry* const ir,
                  const parsing_state* const ps);
