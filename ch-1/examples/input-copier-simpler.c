#include <stdio.h>

// Copy input to output; 1.5st version

int main(){
    int c;
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
    return 0;
}