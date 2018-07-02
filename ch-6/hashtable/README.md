hashtable
---

### Problem statements
Exercise 6-5: Write a function `undef` that will remove a name and definition from the table maintained by lookup and install.

Exercise 6-6: Implement a simple version of the #define processor (i.e. no arguments) suitable for use with C programs, based on the routines of this section. You may also find `getch` and `ungetch` helpful.

### Strategies
6-5: `undef` need only engage in linked list deletion - it can do a lookup, match a kv mapping, and then set prev's next to next->next, then free the current node. In conjunction with 6.6, we can implement the `#undef` macro.

6-6: The `#define` processor can just read words from stdin; if `#define` is encountered, the next word is the key, and the following word is the value. Then, hash each following word - if we get a match, emit to stdout the value, otherwise just emit the word.
