#include <stdio.h>
#define MAXLINE 1000 // maximum input line size

int getline(char line[], int maxline);
void entab(char string[], int len, int whitespaces);

// Write a function that replaces tabs with the correct number of whitespaces (or any other character).

// ALWAYS USE CURLY BRACES, YOU IDIOT

int main(){
    int len, i;    // current line length, and string index
    char line[MAXLINE];     // current input line

    while ((len = getline(line, MAXLINE)) > 0) {
        entab(line, len, 4);
        printf("%s\n", line);
    }
    return 0;
}

// entab(): given a string of len, return it with all whitespaces of a given length replaced by 
// tabs (represented by "$" for clarity)
void entab(char string[], int len, int whitespaces){
    char copy[MAXLINE];
    int i, j, k, do_tab;
    do_tab = k = 0;

    for (i = 0; i < len; i++){
        // If we hit a whitespace, check the following chars
        // to see if we can replace it with a tab
        if (string[i] == ' ') {
            do_tab = 1;
            for (j = 0; j < whitespaces; j++) {
                do_tab &= (string[i+j] == ' ');
            }

            // we can, do the replacement, and then
            // advance the source string the correct
            // number of chars
            if (do_tab) {
                copy[k] ='$';
                k++;
                i+=whitespaces-1;
            } else {
                // There weren't enough whitespaces for
                // replacement, so copy the characters we
                // already checked so we don't have to 
                // check them again.
                for (j = 0; j < whitespaces; j++) {
                    copy[k] = string[i];
                    k++;
                    i++;
                }
            }
        } else {
            copy[k] = string[i];
            k++;
        }
    }
    
    // Copy newly formatted string back to the old one
    for (i = 0; i < k; i++){
        string[i] = copy[i];
    }

    string[k] = '\0';
}

// getline(): read a line into s, return length
int getline(char s[], int lim)
{
    int c, i;

    for (i=0; (i < lim-1) && ((c=getchar()) != EOF) && (c != '\n'); ++i) {
        s[i] = c;
    }

    if (c == EOF) {
        printf("\nGot EOF, quitting immediately.\n");
        return 0;
    } else if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}
