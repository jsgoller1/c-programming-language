#include "calc.h"

// the vars stack stores variables for
// a-z at offsets 0-25, and then
// A-Z at offsets 26-51
int vars_stack_pointer = 0;
double vars_stack[MAX_STACK_SIZE];

void assign(double val1[], double val2[])
{
    if (!validate_var(val1))
    {
        return;
    }

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
    int lval_index = val1[0];

    if (val2[1] == VAR)
    {
        dereference(val2);
    }

    if (lval_index >= 'a' && lval_index <= 'z')
    {
        vars_stack[lval_index - 'a'] = val2[0];        
    }
    else if (lval_index >= 'A' && lval_index <= 'Z')
    {
        vars_stack[lval_index - upper_case_offset] = val2[0];        
    }

    printf("Stored %c = %f.\n", (int)val1[0], val2[0]);

    // Observe C style where assignment returns the value assigned
    push(val2);
}

void dereference(double var[])
{
    int upper_case_offset = 65 - 26;
    int index;

    if (!validate_var(var))
    {
        return;
    }

    index = (int)var[0];
    if (index >= 'a' && index <= 'z')
    {
        var[0] = vars_stack[index - 'a'];        
    }
    else if (index >= 'A' && index <= 'Z')
    {
        var[0] = vars_stack[index - upper_case_offset];        
    }    
    else
    {
        printf("Error: Invalid lvalue for variable assignment.\n");
        return;
    }

    var[1] = RAW;
}

int validate_var(double var[])
{
    if (!((var[0] >= 'a' && var[0] <= 'z') || (var[0] >= 'A' && var[0] <= 'Z')))
    {
        printf("Error: invalid variable name.\n");        
        return 0;
    }
    else if (var[1] != VAR)
    {
        printf("Error: not a variable, cannot assign.\n");
        return 0;
    }
    return 1;
}