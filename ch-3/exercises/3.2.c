#include <stdio.h>

#define MAX_LEN 1000

/*
Write a function escape(s, t) that converts characters like
newline and tab into visible escape sequences like \n and \t as it copies the
string t to s. Use a switch. Write a function for the other direction as well,
converting escape sequences into the real characters.
*/

void escape(char s[], char t[], int t_len);

int main()
{
    char in[] = {"This string contains\n\t escapes \t stuff."};
    char out[MAX_LEN];
    escape(in, out, MAX_LEN);
    printf("%s\n%s\n", in, out);

    char in1[] = {""};
    char out1[MAX_LEN];
    escape(in1, out1, MAX_LEN);
    printf("%s\n%s\n", in1, out1);

    char in2[] = {"asdasdsadsada"};
    char out2[MAX_LEN];
    escape(in2, out2, MAX_LEN);
    printf("%s\n%s\n", in2, out2);
    return 0;
}

void escape(char s[], char t[], int t_len)
{
    int i, j;
    i = j = 0;

    while (s[i] != '\0' && i < t_len)
    {
        switch (s[i])
        {
            case '\n':
                t[j] = '\\';    // Technically, we could increment i on the same line, but
                j++;            // that makes it harder to guess what index will be used in the array.
                t[j] = 'n';
                j++;
                break;
            case '\t':
                t[j] = '\\';    
                j++;            
                t[j] = 't';
                j++;
                break;  
            default:
                t[j] = s[i];
                j++;
                break;    
        }
        i++;
    }
    t[j] = '\0';
}