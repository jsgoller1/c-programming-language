#include <stdio.h>
#include <math.h>

/* 
K&R says (sect. 4.9) that static variables must be initialized with constants, but that
automatic (i.e. variables with function scope) and register variables can be initialized
with other types of expressions. Let's test that!
*/

int some_func(int z);

/* x and y are declared, but not initialized */
static int x;
static int y;
/* 
z and w are declared and initialized at the same time. 
Note that this won't compile if uncommented - z cannot be assigned to 
the return value of a function during compilation (how would
that code run?).

static int z = some_func(5);
*/
static int w = 10;

int main()
{
    /* x is initialized with a constant. */
    x = 5; 
    /* 
    y is assigned the return value of a function. Are K&R wrong? 
    No - this is acceptable at run-time; the only thing not-allowed
    for static variables is non-constant initialization at compile time
    (i.e. by declaring and initializing simultaneously. 
    */
    y = some_func(x);
    printf("%d\n", y);

    return 0;
}

int some_func(int z)
{
    return z * x;
}