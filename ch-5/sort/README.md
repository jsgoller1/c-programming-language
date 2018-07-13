sort
---

### Problem statements
Exercise 5-14. Modify the sort program to handle a -r flag, which indicates
sorting in reverse (decreasing) order. Be sure that -r works with -n.

Exercise 5-15. Add the option -f to fold upper and lower case together, so
that case distinctions are not made during sorting; for example, a and A
compare equal.

Exercise 5-16. Add the -d ("directory order") option, which makes
comparisons only on letters, numbers and blanks. Make sure it works in
conjunction with -f.

Exercise 5-17. Add a field-handling capability, so sorting may be done on
fields within lines, each field sorted according to an independent set of
options. (The index for this book was sorted with -df for the index category
and -n for the page numbers.)

### Notes
5-17: The problem statement for this isn't super clear (what is meant by "fields?" should we go character by character in each string or whitespace separated substrings? can we have multiple subfields sorted differently? etc.), so to keep the problem scope
sane, we will assume that if an `-i` field is given with an offset, any fields after it are to be sub-sorted; `field` means a whitespace-separated substring of characters within that string, e.g. in `pointers, 18 55 15 32`, if `sort ... -i 9 -n` is given, then the substring `18 55 15 32` would be sorted numerically (into `15 18 32 55`) as these subfields occur after index 9. Any flags given after `-i` apply to the sub-sorting routine.
