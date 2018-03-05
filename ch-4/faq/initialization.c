#include <stdio.h>

/* 
K&R says (sect. 4.9) that static variables must be initialized with constants, but that
automatic (i.e. variables with function scope) and register variables can be initialized
with other types of expressions. Let's test that!
*/

int some_func(int z);

/* x and y are declared, but not initialized */
static int x;
static int y;

int main()
{
    /* x is initialized with a constant. */
    x = 5; 
    /* Are K&R wrong? y is initialized with a function return value */
    y = some_func(x);
    printf("%d\n", y);

    return 0;
}

int some_func(int z)
{
    return z * x;
}