#include <stdbool.h>

char* expand(const char* const str, const int len);
bool valid_expansion(const char* const str, const int i, const int len);
char* generate_expansion(const char a, const char b);
int get_char_type(const char a);
int is_upper(const char a);
int is_lower(const char a);
int is_int(const char a);
void test(const char* const str, const char* const expansion);
