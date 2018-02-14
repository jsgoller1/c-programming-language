#include <stdio.h>

// test printing arrays with empty values

int main()
{
    char chars[4] = {'a', 'b', 'c', 'd'};
    chars[1] = "";
    printf("%s\n", chars); 
    return 0;
}