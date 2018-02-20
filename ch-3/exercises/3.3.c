#include <stdio.h>
#define MAX_LEN 1000

/* 
Exercise 3-3. Write a function expand(s1 ,s2) that expands shorthand 
notations like a-z in the string s1 into the equivalent complete list abc...xyz in
s2. Allow for letters of either case and digits, and be prepared to handle cases
like a-b-c and a-zO-9 and -a-z. Arrange that a leading or trailing - is
taken literally.

For this, I'm assuming that:
a-1 -> a-1, a-A -> a-A, etc. (no expansion for different chars)
d-a -> dcba (reverse expansion)
a-c-e -> abc-e -> abcde (chained expansion)
*/

void expand(char s1[], int s1_len, char s2[]);
int is_valid_range(char a, char b);
int get_type(char a);
int is_upper(char a);
int is_lower(char a);
int is_int(char a);


int main()
{
    // Note: did some copying and pasting
    // to organize test case; apologies
    // for numbering being disorganized
    // (as long as the test vars are 
    // grouped correctly, I don't really 
    // care here)
/*
    // basic expansion, lower case
    // abcd
    char t0[] = {"a-d"};
    char a0[MAX_LEN];
    expand(t0, 3, a0); 
    printf("%s == %s\n", t0, a0);

    // basic expansion, upper case
    // ABCD
    char t1[] = {"A-D"};
    char a1[MAX_LEN];
    expand(t1, 3, a1); 
    printf("%s == %s\n", t1, a1);

    // basic expansion, ints
    // 01234
    char t2[] = {"0-4"};
    char a2[MAX_LEN];
    expand(t2, 3, a2); 
    printf("%s == %s\n", t2, a2);

   // Average input
   // abcd01234ABCD
    char t3[] = {"a-d0-4A-D"};
    char a3[MAX_LEN];
    expand(t3, 9, a3); 
    printf("%s == %s\n", t3, a3);

   // Reverse input
   // dcba
    char t4[] = {"d-a"};
    char a4[MAX_LEN];
    expand(t4, 3, a4); 
    printf("%s == %s\n", t4, a4);

    // null input
    // ""
    char t5[] = {""};
    char a5[MAX_LEN];
    expand(t5, 0, a5); 
    printf("%s == %s\n", t5, a5);
*/
    // edge cases, all of which should
    // print their input
    char t6[] = {"-"};
    char a6[MAX_LEN];
    expand(t6, 2, a6); 
    printf("%s == %s\n", t6, a6);
/*
    char t4[] = {"-a-"};
    char a4[MAX_LEN];
    expand(t4, 3, a4); 
    printf("%s == %s\n", t4, a4);

    char t5[] = {"a--a"};
    char a5[MAX_LEN];
    expand(t5, 4, a5); 
    printf("%s == %s\n", t5, a5);

    char t8[] = {"abcd"};
    char a8[MAX_LEN];
    expand(t8, 4, a8); 
    printf("%s == %s\n", t8, a8);

    char t8[] = {"1-a"};
    char a8[MAX_LEN];
    expand(t8, 3, a8); 
    printf("%s == %s\n", t8, a8);
*/
    return 0;
}

void expand(char s1[], int s1_len, char s2[])
{
    int i; // s1 index
    int j; // s2 index
    int k; // temp var for expansion
    j = 0;

    // go through the string until we find a '-'
    for (i = 0; i < s1_len; i++)
    {
    // check if the chars left and right of it are within bounds
        //printf("i: %d\n", i);
        if ((s1[i] == '-') && ((i-1 >= 0) && (i+1 < s1_len)))
        {
            // if so, determine if specificed range is of valid "types" (upper, lower, or int, both bounds are the same "type")
            if (is_valid_range(s1[i-1], s1[i+1]))
            {
                // given that they're the same type, determine if they're ascending or descending
                if (s1[i-1] < s1[i+1])
                {
                    // for ascending, expand by incrementing; remember
                    // the left bound is already in s2 from the previous
                    // iteration, so skip it.
                    for (k = (s1[i-1]+1); k <= s1[i+1]; k++)
                    {
                        printf("inc: inserting %c at s2[%d]\n", k, j);
                        s2[j] = k;
                        j++;
                    }
                    i++; // in a-c, don't evaluate c after evaluating -; 
                } else if (s1[i-1] > s1[i+1])
                {
                    // for descending, expand by looping down; remember
                    // the left bound is already the first correct char
                    for (k = (s1[i-1]-1); k >= s1[i+1]; k--)
                    {
                        printf("dec: inserting %c at s2[%d]\n", k, j);                        
                        s2[j] = k;
                        j++;
                    }
                    i++; // in c-a, don't evaluate a after evaluating -; 

                } else // they're equal, just copy the character;
                {
                    printf("eq: inserting %c at s2[%d]\n", s1[i], j);
                    s2[j] = s1[i];
                    j++;   
                }
            } else // invalid range bounds, copy the '-' mark
            {
                printf("invalid range bounds: inserting %c at s2[%d]\n", s1[i], j);             
                s2[j] = s1[i];
                j++;   
            }
        } else // left or right is outside of s1, copy the '-' mark
        {
            printf("bounds outside s1 or normal char: inserting %c at s2[%d]\n", s1[i], j);           
            s2[j] = s1[i];
            j++;   
        }
    }
    s2[j] = '\0';
}

int is_valid_range(char a, char b)
{
    int type_a, type_b;
    type_a = get_type(a);
    type_b = get_type(b);

    return ((type_a == type_b) && (type_a != -1));
}

int get_type(char a)
{
    if (is_upper(a))
    {
        return 0;
    } else if (is_lower(a))
    {
        return 1;
    } else if (is_int(a))
    {
        return 2;
    } else 
    {
        return -1;
    }
}

int is_upper(char a)
{
    return (a >= 'A') || (a <= 'Z');
}

int is_lower(char a)
{
    return (a >= 'a') || (a <= 'z');    
}

int is_int(char a)
{
    return (a >= '0') || (a <= '9');
}