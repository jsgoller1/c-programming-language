#pragma once

#define USE_ENTAB 42
#define USE_DETAB 666

// input
int parse_flags(const int argc, char** const argv, int* tab_stops, int* stop_list_len));

// entab
char* entab(const char* const in_line, const int in_len,
            const int* const tab_stop, const int stop_list_len);
int look_ahead(const char* const in_line, const int in_len, int offset,
               const int stop_list);
// detab
char* detab(const char* const in_line, const int in_len,
            const int* const stop_list);
