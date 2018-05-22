# Reverse Polish Notation (RPN) calculator
To avoid unnecessary code replication over minor changes, exercises 4.3 through 4.9 have been grouped into a single application here, which I completely overhauled to use more robust parsing / lexing.

## Use
Valid input is of the form `<EXPRESSION> <EXPRESSION> <OPERATOR>`. Expressions
may either be floating point values, variables, or a nested expression.

## Supported features
* You can assign single-character variables via the `=` operator: `a 4 =`; assignment is C-style (i.e. returns the value assigned).
* Basic arithmetic operators: `+`, `-`, `*`, `/`, and `%`.
* Math functions as operators, which are 3 or 4 letters long:
  * SIN
  * COS
  * TAN
  * ASIN
  * ACOS
  * ATAN
  * POW
  * EXP
  * SQRT
  * FLOR

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