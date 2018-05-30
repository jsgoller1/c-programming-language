decl
---

Grammar:
```
       dcl -> (optional *'s) direct-dcl
direct-dcl -> name
           -> (dcl)
           -> direct-dcl()
           -> direct-dcl[optional size]
```

---

Test cases from the book:
```
char **argv
argv: pointer to pointer to char

int (*daytab)[13]
daytab: pointer to array[13] of int

int *daytab[13]
daytab: array[13] of pointer to int

void *comp()
comp: function returning pointer to void

void (*comp)()
comp: pointer to function returning void

char (*(*x()){})()
x: function returning pointer to array[] of pointer to function returning char

char (*(*x[3])(»[S]
x: array[3] of pointer to function returning pointer to array[S] of char
```

---

```
Exercise 5-18. Make dcl recover from input errors.

Exercise 5-19. Modify undcl so that it does not add redundant parentheses to
declarations.

Exercise5-20. Expand dcl to handle declarations with function argument types, qualifiers like const, and so on.
```
