#include <stdio.h>

// Write a function that can detect rudimentary syntax errors in C programs.
// I may come back to this and write more features into it, but for now, it
// only ignores single-line comments.

// ALWAYS USE CURLY BRACES, YOU IDIOT

int main(){
    int in_comment, quotes, ticks, paren_l, paren_r, curly_l, curly_r, square_l, square_r, comment_braces;
    in_comment, quotes = ticks = paren_l = paren_r = curly_l = curly_r = square_l = square_r = comment_braces = 0;
    char c; 

    while ((c = getchar()) != EOF) {
        // Check if we're in a comment
        if (comment_braces == 2) {
            in_comment = 1;
        }

        if (c == '\n') {
            comment_braces = in_comment = 0;
        }

        if (!in_comment){
            switch(c) {
                case '/':
                    comment_braces++;
                    break;
                case '"':
                    quotes++;
                    break;
                case '\'':
                    ticks++;
                    break;
                case '(':
                    paren_l++;
                    break;
                case ')':
                    paren_r++;
                    break;
                case '{':
                    curly_l++;
                    break;
                case '}':
                    curly_r++;
                    break;
                case '[':
                    square_l++;
                    break;
                case ']':
                    square_r++;
                    break;                                                                    
            }
        }
    }
    printf(" quotes: %d\n ticks: %d\n paren_l: %d\n paren_r: %d\n curly_l: %d\n curly_r: %d\n square_l: %d\n square_r: %d\n", 
            quotes, ticks, paren_l, paren_r, curly_l, curly_r, square_l, square_r);
    if ((quotes%2) != 0) {
         printf("Program has mismatched closing/opening double quotes.\n");
    } else if ((ticks%2) != 0) {
         printf("Program has mismatched closing/opening single-ticks.\n");
    } else if (paren_l != paren_r) {
         printf("Program has mismatched parens.\n");
    } else if (curly_l != curly_r) {
        printf("Program has mismatched curly braces.\n");
    } else if (square_l != square_r) {
        printf("Program has mismatched square braces.\n");
    } else {
        printf("Program is possibly correct.\n");
    }

    return 0;
}