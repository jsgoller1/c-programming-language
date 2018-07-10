#pragma once

#define USE_ENTAB 42
#define USE_DETAB 666

typedef struct input_flags {
} input_flags;

// input
int parse_flags(const int argc, char** const argv, int* tab_stops);

// entab
char* entab(const char* const in_line, const int in_len,
            const int* const tab_stop);
int look_ahead(const char* const in_line, const int in_len, int offset,
               const int tab_stop);
// detab
char* detab(const char* const in_line, const int in_len,
            const int* const tab_stop);
