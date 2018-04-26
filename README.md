# The C Programming Language (K&R)
Exercises from "The C Programming Language" by Kernighan / Ritchie.

## Running
See the Makefile for the list of targets - each exercise has its own target (e.g. `make 5.4` will make exercise 4 in chapter 5).

## Goals
- [ ] All pages read
- [ ] All exercised solved correctly
- [ ] All solutions compile against C11 with `-Werror -Wall`
- [ ] Maximum const correctness

In some places, I have tried to avoid using concepts that may be more
"correct" idomatically but hadn't been introduced in the text yet; e.g. the RPN
calculator should probably store tokens in structs, but the exercise is from
chapter 4, whereas structs are introduced in chapter 6. I assume the authors
intended to challenge the reader or show the necessity of a feature before
introducing it.

## Notes about the exercises
See `TODO.md` for the remaining work to be done.
* Ch. 1:
  * 1.1 and 1.2 did not have any demo-able code; the instructins were just `experiment with hello world`.
  * 1.3 and 1.4 were both implemented in 1.4.c
* Ch. 4:
  * Any exercise not listed in chapter 4 was moved to the `reverse-polish-notation` directory; I re-architected the program to be more robust and implemented several of the solutions to exercises as part of the entire program.
  * I skipped 4.10, because I completely re-architected the RPN calculator to loosely couple and more robustly handle parsing, lexing, and token handling; a solution involving parsing the entire string either would require 1) tightly-recoupling these  things so that in one loop you can handle the entire string, determining symbols and pushing it to the stack, or 2) having an intermediary data structure similar to the ungetch() buffer.
  * K&R claim that in 4.9 `getch()` / `ungetch()` don't handle `EOF` correctly, but the expected behavior occurs both in my implementation and theirs so I'm not quite sure what this question is asking. `EOF` does cause the program to exit correctly, although the `EOF` character gets pushed back into the array by `ungets()`. However, given "worse is better" philosophy, it seems like it's better to have a slightly-incorrect implementation that causes this instead of a "more-correct" one that makes sure `EOF`s never wind up in the `ungets()` buffer. Of note, on Linux, the CTRL-D character is mapped to `EOF`, but flushes all bytes to the process; it only passes EOF to the program if it is the first character ([see the POSIX docs specifiying this  behavior](https://stackoverflow.com/questions/21260674/why-do-i-need-to-type-ctrl-d-twice-to-mark-end-of-file)).

## Source text
You can find the full 2nd edition text with examples [here](http://cs.indstate.edu/~cbasavaraj/cs559/the_c_programming_language_2.pdf).

## Special thanks
* [Elliott Jin (@robot-dreams)](https://github.com/robot-dreams) for the many hours of help debugging and review.
* [Steven Harris (@seh)](https://github.com/seh) for some helpful feedback on the RPN calculator.
