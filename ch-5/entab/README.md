entab/detab
---

### Exercise directions
Exercise 5-11: Modify the programs entab and detab (written as exercises in Chapter 1) to
accept a list of tab stops as arguments. Use the default tab settings if there are no arguments.

Exercise 5-12: Extend entab and detab to accept the shorthand `entab -m +n` to mean tab
stops every n columns, starting at column m. Choose convenient (for the user) default behavior.

### Prompts from original entab / detab
Ex 1.20: Write a program detab() that replaces tabs in the input with the
proper number of blanks to space to the next tab stop. Assume a fixed set of
tab stops, say every n columns. Should n be a variable or a symbolic  parameter?

Ex 1.21: Write a program entab that replaces strings of blanks by the minimum number
of tabs and blanks to achieve the same spacing. Use the same tab stops as for
detab(). When either a tab or a single blank would suffice to reach a tab
stop, which should be given preference?
