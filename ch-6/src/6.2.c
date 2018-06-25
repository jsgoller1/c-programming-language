/* Exercise 6-2. Write a program that reads a C program and prints in
 * alphabetical order each group of variable names that are identical in the
 * first 6 characters, but different somewhere thereafter. Don't count words
 * within strings and comments. Make 6 a parameter that can be set from the
 * command line.
 * ------------------------------------------------------------------------------------------
 * As we find each variable name, we can store "groups of variable names" as
 * a linked list of linked lists. Each group of related variable names is stored as a linked list,
 * and each list head has a pointer to the next group's list head. We can use a struct like:
 * struct ll_vargroups {
 *    ll_vargroups* next_group;
 *    ll_vargroups* next_word;
 * };
 *
 * For example, if n = 2 and our variable list is
 * "cat", "cam", "bat", "bane", "back", "found", and "foo", we would store variables as:
 *
 * cat -> cam
 *  |
 *  v
 * bat -> bane -> back
 *  |
 *  v
 * foo -> found
 *
 * Inserting into the ll_vargroups list involves finding the right head via strcmp(), walking
 * to the end of that group and appending there.
 * ------------------------------------------------------------------------------------------
 * The hardest part of this is "how do we detect a variable name?" We can use the parser from
 * 6.1 to determine if we are parsing valid keywords (i.e. not in comments or string literals).
 * Legal variable names must at least once be declared after a type, so if we look for
 * words following types, we can detect all variables (in all scopes).
 *
 * Types can be:
 * - keywords like int
 * - "struct", as in a "struct <structname> <varname>" declaration,
 * - Previously declared via "typedef type newname"
 *
 * As part of program initialization, we can create a linked list of all keywords known to be types,
 * and add to it as we find typedefs.
 *
 * To find each variable name:
 * - Read through the file's words.
 * - Compare each word to the types in the type list. If we find a typedef statement, add
 * the new type to the linked list of typenames.
 * - If we encounter a type name match:
 *  - Get the next word and the character following it.
 *  - If the next word is followed by a semicolon, add it to the ll_vargroups list.
 *  - If it's followed by a comma (e.g. int foo, bar;), it to the ll_vargroups list and repeat.
 *  - If it's followed by an open paren, don't add it (it is a function declaration).
 * ------------------------------------------------------------------------------------------
 * Once we fully parse the C program, we can then print the ll_vargroups list.
 * /
