decl
---

## Grammar:
```
       decl -> (optional *'s) direct-decl
direct-decl -> name
            -> (decl)
            -> direct-decl(typed-expr)
            -> direct-decl[optional size]
 typed-expr -> type name
       name -> (optional const) any string of alphanum chars, not reserved
       type -> (optional const) (char | short | int | long | float | double ) (optional *)
```

## Assumptions
- we will not handle compound types, e.g. `unsigned long`
- we will not handle structs
- function arguments will only be basic types:
  - allowed: 
    - `int x(int a, int b)`
    - `int x(const int a)`
  - not allowed:
    - `int x(int (*f)(int, int), int a)`


## Directions
```
Exercise 5-18. Make decl recover from input errors.

Exercise 5-19. Modify undecl so that it does not add redundant parentheses to declarations.

Exercise5-20. Expand decl to handle declarations with function argument types, qualifiers like const, and so on.
```

## Notes
const int x;
  decl
  const direct-decl



const char* const x;
x(const int y);

const char* const x(const char* const y);
