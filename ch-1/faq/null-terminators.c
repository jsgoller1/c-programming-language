#include <stdio.h>

// Why is it necessary to have a null terminator at the end of a char[] buffer?

int main()
{
    // chars_a and chars_b contain the same thing, as
    // C buffers are zero-initialized.
    int i, len;
    len = 4;
    char chars_a[4] = {'\0', '\0', '\0', '\0'};
    char chars_b[len];

    // This is BAD; chars_b will be: {'A', 'A', 'A', 'A'}
    for (i = 0; i < len; i++){
        chars_b[i] = 'A';
    }

    // There's now no null terminator!
    for (i = 0; i < len; i++){
        if(chars_b[i] == '\0'){
            printf("Null terminator.\n");
        } else {
            printf("Not null: %c\n", chars_b[i]);
        }
    }
    // Why is this bad? printf will go on to print whatever 
    // is outside the buffer. Notice we get more than chars_b 
    // when we go to print it:
    for (i = 4; i < 11; i++){
        chars_b[i] = '!';
    }
    printf("%s\n", chars_b);
    // But if we stick a null at the end, we will stop printing at the end of the buffer:
    chars_b[3] = '\0';
    printf("%s\n", chars_b); 

    // Another example - let's say we have two strings contiguous in memory,
    // separated by null a terminator.
    char chars_c[8] = {'o', 'n', 'e', '\0', 't', 'w','o', '\0'};
    printf("%s\n", chars_c); 
    // If we replace the null terminator with something else, we get them both.
    chars_c[3] = '!';
    printf("%s\n", chars_c); 

    return 0;
}