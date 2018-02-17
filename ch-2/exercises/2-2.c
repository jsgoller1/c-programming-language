#include <stdio.h>
#define MAXLINE 1000 // maximum input line size

#define true  1
#define false 0

int get_line_no_comp(char s[], int lim);

int main(){
    int len;
    char line[MAXLINE];     // current input line
    while((len = get_line_no_comp(line, MAXLINE)) > 0 ){
        printf("%d: %s\n", len, line);
    }

    return 0;
}

// getline(): read a line into s, return length
int get_line_no_comp(char s[], int lim)
{
    int c, i;
    int loop = true;

    for (i=0; loop; ++i) {

        // Check if we have space, then get the char
        if(i >= lim-1) {
            loop = !loop;
        } else {
            c = getchar();
        }

        // Test char and take action accordingly
        if (c == EOF) {
            printf("\n"); // don't goof up output if user EOFs mid-line
            loop = !loop;
        } else if (c == '\n') {
            s[i] = c;
            loop = !loop;
        } else {
            s[i] = c;
        }
    }

    s[i] = '\0';
    return i-1;
}