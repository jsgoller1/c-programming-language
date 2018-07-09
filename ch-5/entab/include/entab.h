#pragma once

typedef struct input_flags {
} input_flags;

// input
int parse_flags(const int argc, char** const argv);

// entab
int look_ahead(const char* const in_line, const int in_len, int offset,
               const int tab_stop);

// detab
char* detab(const char* const in_line, const int in_len, const int tab_stop);