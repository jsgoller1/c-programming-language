#include "calc.h"

// the vars stack stores variables for
// a-z at offsets 0-25, and then
// A-Z at offsets 26-51
int vars_stack_pointer = 0;
double vars_stack[MAX_STACK_SIZE];

// this flag is set if the last character parsed 
// by getop() was a variable
// extern parsed_var;

// store: saves data to the variables stack; if pop() encounters a
// non-int, it will attempt to dereference it from this stack.
void store_var(double val1[], double val2[])
{
    /*
    // Suppose we want to assign to 'Q'. Upper case variable values are 
    // stored starting at vars_stack[26]; to correctly 
    // store the value associated with 'Q', we can use
    // 'Q' as an offset into the array as such:
    // 'Q' - 'A' + 26
    // = 81 - 65 + 26
    // = 81 - (65 - 26) 
    // = 81 - 39
    // = 42 (note that Q is 17th letter of the alphabet; 25 + 17 = 42).
    int upper_case_offset = 65 - 26;

    // coerce to int to use lval as index
    int lval_index = lval;

    if (lval >= 'a' && lval <= 'z')
    {
        vars_stack[lval_index - 'a'] = rval;        
    }
    else if (lval >= 'A' && lval <= 'Z')
    {
        vars_stack[lval_index - upper_case_offset] = rval;        
    }
    else
    {
        printf("Error - invalid variable assignment; no variables assigned.\n");
    }

    printf("Stored %c = %f.\n", lval, rval);
    */
}

void assign(double val1[], double val2[])
{
    /*
    int lval, valid_rval, c;
    char s[MAXOP];

    while (((c = getchar()) == ' ') || c == '\t' )
    {
        // no op; get all characters until a space/tab/newline is hit
    }    

    lval = c;
    if (!((lval >= 'a' && lval <= 'z') || (lval >= 'A' && lval <= 'Z')))
    {
        printf("Error: Invalid lvalue for variable assignment.\n");
        return;
    }
    
    valid_rval = getop(s);

    if (valid_rval == NUMBER)
    {
        store_var(lval, atof(s));
    }
    else
    {
        printf("Error: Invalid rvalue for variable assignment.\n");
    }
    */
}

double dereference(double var[])
{
    /*
    int upper_case_offset = 65 - 26;
    double ret;

    if (var >= 'a' && var <= 'z')
    {
        ret = vars_stack[var - 'a'];        
    }
    else if (var >= 'A' && var <= 'Z')
    {
        ret = vars_stack[var - upper_case_offset];        
    }    
    else
    {
        printf("Error: Invalid lvalue for variable assignment.\n");
        return 0.0;
    }

    printf("ret: %f\n", ret);
    return ret;
    */
}