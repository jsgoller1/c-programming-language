# Reverse Polish Notation (RPN) calculator

## Use
Valid input is of the form `<EXPRESSION> <EXPRESSION> <OPERATOR>`. Expressions
may either be floating point values, variables, or a nested expression.

## Supported features
* You can assign single-character variables via the `=` operator: `a 4 =`; assignment is C-style (i.e. returns the value assigned).
* Basic arithmetic operators: `+`, `-`, `*`, `/`, and `%`.
* Math functions as operators, which are 3 or 4 letters long:
* * SIN
* * COS
* * TAN
* * ASIN
* * ACOS
* * ATAN
* * POW
* * EXP
* * SQRT
* * FLOR

## Building
`make calc`

## Example use
```
4 5 +
       9
4 5 + 5 6 + -
      -2
a 5 =
Stored a = 5.000000.
       5
b 6 =
Stored b = 6.000000.
       6
b 10 * SIN
-0.30481062
```