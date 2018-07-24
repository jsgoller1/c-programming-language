#pragma once

#define USE_ENTAB 42
#define USE_DETAB 666

// input
int parse_flags(const int argc, char** const argv, int** tab_stops,
                int* stop_list_len);

// detab
char* detab(const char* const in_line, const int in_len,
            const int* const stop_list, const int stop_list_len);
// entab
char* entab(const char* const in_line, const int in_len,
            const int* const tab_stop, const int stop_list_len);
int look_ahead(const char* const in_line, const int in_len, int offset,
               const int stop_list);
// misc
int generate_stop_list(const int start, const int interval, int** tab_stops,
                       int* const tab_stops_len);
int next_tab_stop(const int* const tab_stops, const int tab_stops_len,
                  const int column);
int isdigits(const char* const string, const int len);
