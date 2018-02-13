#include <stdio.h>

#define IN  1    // inside a word
#define OUT 0    // outside a word

// Write a program to print a histogram of words lengths in its input; vertical is harder than horizontal.
int main()
{
    int i, c, word_length, state;
    int words[10]; // 1 through 9, then 10+

    word_length = 0;
    state = OUT;

    for (i = 0; i < 10; i++)
        words[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            if (word_length >= 10) {
                words[9]++;
            } else if (word_length >= 1) {
                words[word_length-1]++;
                word_length = 0;
            }   
        } else if (state == OUT)
            state = IN;
        if (state == IN)
            ++word_length;
    }

     
    printf("Word Lengths contents\n");
    for (i=0; i<9; i++){
        printf("%d: %4d\n", i+1, words[i]);
    }       

    for (i=0; i<9; i++){
        printf("%4d", i+1);
    }    
    printf("%4d+\n", 10);

    int curr_column, curr_row, more_rows;
    char hist_row[10];
    curr_column = curr_row = 0;
    more_rows = 1;
    while (more_rows) {
        more_rows = 0;
        for(curr_column = 0; curr_column <= 9; curr_column++) {
            if (words[curr_column] > curr_row) {
                more_rows = 1;
                hist_row[curr_column] = 'X';
            }
            else {
                hist_row[curr_column] = ' ';
            }
        }
        ++curr_row;

        for (i=0; i<10; i++){
            printf("%4c", hist_row[i]);
        }
        printf("\n");
    }
   
    return 0;
}