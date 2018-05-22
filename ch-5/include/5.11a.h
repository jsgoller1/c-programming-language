char* entab(const char* const in_line, const int in_len, const int* tab_stops);
int look_ahead(const char* const in_line, const int in_len, int offset,
               const int tab_stop);
int get_next_tabstop(const int* const tab_stops, const int current_char);
