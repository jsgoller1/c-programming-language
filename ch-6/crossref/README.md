crossref
---
 ```
 Exercise 6-3. Write a cross-referencer that prints a list of all words in a
 document, and, for each word, a list of the line numbers on which it occurs.
 Remove noise words like "the," "and," and so on.
 -----
 We will keep a tree of words. Each node will contain an array of ints that
 will store the line numbers the word occurs on. We will dynamically resize
 these arrays as needed. We will read line by line from stdin, incrementing a
 linecount each time we see a \n. At the end, we will walk the tree and print
 the words and their counts.
```
