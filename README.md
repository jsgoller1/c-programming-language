# The C Programming Language (K&R)
Exercises from "The C Programming Language" by Kernighan / Ritchie. Each chapter has three subfolders:

* **examples/** - examples from the chapter text
* **exercises/** - solutions to chapter exercises.
* **faq/** - questions I ask myself to check my understanding, with my own examples.

The examples code is aimed to be as self-contained and close to the original as possible, so it may contain
code duplication and things not considered best practices for modern C (braceless `for` / `if` statements, no `const` use, etc).
In following the 2nd ed. of K&R, examples are C89 compliant but may compile with warnings.

Oppositely, the exercise code is aimed to be as high quality as I can make it. Per the Makefile, it should
compile without issue at the maximum warning level (with all warnings being errors), be C11 compliant, enforce
`const`-correctness, have no unnecessary replication, and be adequately commented.

## Source text
You can find the full 2nd edition text [here](http://cs.indstate.edu/~cbasavaraj/cs559/the_c_programming_language_2.pdf).

## Running
Everything compiles out of the Makefile.

## Notes about the exercises
I didn't really have a good reason to separate function declarations and definitions until after Chapter 4 (especially given that K&R hadn't covered headers yet), so for most of chapter 4 and before everything is in one file. I tried working with GDB on OSX but couldn't get it to work, so I moved to lldb / clang and started using more aggressive compiler flags and C11 instead of C98. Earlier exercises will probably not compile with the same settings, see above.

* Ch. 1:
  * Skipped
    * 1-14 (write a program to print a histogram of frequencies of different chars in input).
    * 1-22 (write a program to "fold" long input lines into two or more short lines after the last non-blank char that occurs before the nth column of input).
  * "Completed, but..."
    * 1-20 and 1-21, but not using tab stops (which I didn't understand when I wrote the solution); they are simply written as search-and-replace algorithms for the specified characters.
* Ch. 3:
  * "Completed, but..."
    * 3.3, but not as cleanly as @robot-dreams 's [solution](https://gist.github.com/robot-dreams/34d10248bc474f5a4312fa72e325656a).
* Ch. 4:
  * Skipped
    * 4.10, because I completely re-architected the RPN calculator to loosely couple and more robustly handle parsing, lexing, and token handling; a solution involving parsing the entire string either would require 1) tightly-recoupling these  things so that in one loop you can handle the entire string, determining symbols and pushing it to the stack, or 2) having an intermediary data structure similar to the ungetch() buffer.
  * "Completed, but..."
    * 4.9: K&R claim that `getch()` / `ungetch()` don't handle `EOF` correctly, but the expected behavior occurs both in my implementation and theirs so I'm not quite sure what this question is asking. `EOF` does cause the program to exit correctly, although the `EOF` character gets pushed back into the array by `ungets()`. However, given "worse is better" philosophy, it seems like it's better to have a slightly-incorrect implementation that causes this instead of a "more-correct" one that makes sure `EOF`s never wind up in the `ungets()` buffer. Of note, on Linux, the CTRL-D character is mapped to `EOF`, but flushes all bytes to the process; it only passes EOF to the program if it is the first character ([see the POSIX docs specifiying this  behavior](https://stackoverflow.com/questions/21260674/why-do-i-need-to-type-ctrl-d-twice-to-mark-end-of-file)).
* Ch. 5:
  * Skipped
    * 5.6 (rewriting previously written functions but with pointers).


## Special thanks
* [Elliott Jin (@robot-dreams)](https://github.com/robot-dreams) for the many hours of help debugging and review.
* [Steven Harris (@seh)](https://github.com/seh) for some helpful feedback on the RPN calculator.
