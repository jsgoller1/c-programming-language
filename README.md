# The C Programming Language (K&R)
Exercises from "The C Programming Language" by Kernighan / Ritchie.

## Running
See the Makefile for the list of targets - each exercise has its own target (e.g. `make 5.4` will make exercise 4 in chapter 5).

## Goals
Other than learning C, my aim with this text was for it to be an exercise in `fanatical conscientiousness`, so my goals are:
- [ ] All pages read
- [ ] All exercised solved correctly
- [ ] All solutions compile against C11 with `-Werror -Wall`
- [ ] Aggressive adherence to conventions (see below)

Admittedly, I have cheated some in my solutions - this was not my experience with C, so I jumped around while reading and thus used concepts that may not have been introduced yet in the
text. The overall strategy with the solutions was `write the best C I possibly can`, not `hold to the text as closely as possible`.

## Conventions
- Everything should be `lower_snake_case`.
- Every non-main function should have a single comment above the definition, starting with `name(): ...` and a description using its parameters.
  - E.g.: `swap(): swaps s[i] and s[j] in s`.
- Constants should always be `#define`ed in `UPPER_SNAKE_CASE`.
- Every function parameter should be const (pointers and values) unless they need to mutate.
- Comments longer than one line should use `/* ... */`, oneliners use `//`. 
- The order of things in each file is:
  - `#include`s
  - Problem statement, starting with `Ex <chapter>.<problem>: ...`
  - `#define`s
  - `typedefs` and struct definitions
  - `main()`
  - Other function definitions in alphabetical order (by name)

## Notes about the exercises
See `TODO.md` for the remaining work to be done.
* General:
  * For programs reading from stdin, it is expected behavior that you will need to hit CTRL-D twice to exit if the last character entered was not a newline - this behavior is defined by the POSIX standard (see this [Stack Overflow question](https://stackoverflow.com/questions/21260674/why-do-i-need-to-type-ctrl-d-twice-to-mark-end-of-file?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa)).
* Ch. 1:
  * 1.1 and 1.2 did not have any demo-able code; the instructins were just `experiment with hello world`.
  * 1.3 and 1.4 were both implemented in 1.4.c
* Ch. 4:
  * Any exercise not listed in chapter 4 was moved to the `reverse-polish-notation` directory; I re-architected the program to be more robust and implemented several of the solutions to exercises as part of the entire program.
  * I skipped 4.10, because I completely re-architected the RPN calculator to loosely couple and more robustly handle parsing, lexing, and token handling; a solution involving parsing the entire string either would require 1) tightly-recoupling these  things so that in one loop you can handle the entire string, determining symbols and pushing it to the stack, or 2) having an intermediary data structure similar to the ungetch() buffer.
  * K&R claim that in 4.9 `getch()` / `ungetch()` don't handle `EOF` correctly, but the expected behavior occurs both in my implementation and theirs so I'm not quite sure what this question is asking. `EOF` does cause the program to exit correctly, although the `EOF` character gets pushed back into the array by `ungets()`.

## Source text
You can find the full 2nd edition text with examples [here](http://cs.indstate.edu/~cbasavaraj/cs559/the_c_programming_language_2.pdf).

## Special thanks
* [Elliott Jin (@robot-dreams)](https://github.com/robot-dreams) for the many hours of help debugging and review.
* [Steven Harris (@seh)](https://github.com/seh) for some helpful feedback on the RPN calculator.
