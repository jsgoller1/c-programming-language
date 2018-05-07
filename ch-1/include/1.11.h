typedef struct {
  int lines;
  int words;
  int chars;
} counter;

void word_count(const char* const input, const int len, counter* const counts);
