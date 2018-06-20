# The C Programming Language (K&R)
Exercises from "The C Programming Language" by Kernighan / Ritchie.

## Important Note
This was the first book I read that qualifies as "one of those CS books everyone should read," and also the first time I tried doing every exercise in a textbook. As such, it's taken a long time to complete (as of writing this, I'm only a little more than halfway done with ~150 hours), but a lot of that is because in addition to learning C I also learned how to write code productively and how to read a CS textbook productively. As such, code from earlier chapters is generally worse than code from later chapters, and I'm OK with that.

## Goals
Other than learning C and "doing all the exercises," my goals for this textbook changed as I read it. I settled on the following definition for "complete":
- All pages read
- All exercises solved, with maximum const correctness
- All solutions compile against C11 with `-Werror -Wall`
- All solutions report no memory leaks in Valgrind

Beyond these, I have tried to adhere aggressively to the conventions defined in `conventions.c` and write lots of unit tests, but I make no promises about either. Also, I have _not_ tried to hold to the text as closely as possible at the cost of writing straightforward code; e.g. I may use structs in my solutions in chapter 5 despite them not being introduced til chapter 6.

## Running
Each exercise has its own target (e.g. `make 5.4` will make exercise 4 in chapter 5). `make all` compiles all exercises and runs unit tests (assuming any exist). Some exercises are refactored into their own shared subprograms when warranted; e.g. 5.14 - 5.17 are all about the `sort` program, so they exist in `sort/`. Makefile targets exist for these solutions independently.

## Highlights
* Ch-4
  * `rpc/` - the [Reverse Polish Notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation) calculator
* Ch-5
  * `decl/` - the UNIX `decl` program (similar to `cdecl`)
  * `sort/` - the UNIX `sort` program
  * `tail/` - the UNIX `tail` program
* Ch-8
  * `malloc_j/` - a storage allocator / the final boss of K&R
* Misc.
  * `tests/` - a testing library, as described below
  * `common/` - a "standard library" of various types of functions most exercises consume

## Tests
I wrote my own simple testing library for the exercises, found in `tests/`; it wraps around the `assert(3)` macro and can do basic comparison for strings, ints, and bools. Execution will immediately halt and fail
if any tests fail. Test execution relies on two preprocessor macros which can be set in the Makefile:
* `TESTS` - causes each individual test to be shown (if any exist) when testing.
* `DEBUG` - dumps information about the exercise test results.

## Conventions
See `conventions.c` for an example file and listing of conventions.

## Notes about the exercises
See `TODO.md` for the remaining work to be done.
* General:
  * For programs reading from stdin, it is expected behavior that you will need to hit CTRL-D twice to exit if the last character entered was not a newline - this behavior is defined by the POSIX standard (see this [Stack Overflow question](https://stackoverflow.com/questions/21260674/why-do-i-need-to-type-ctrl-d-twice-to-mark-end-of-file?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa)).
* Ch. 1:
  * 1.1 and 1.2 did not have any demo-able code; the instructions were just `experiment with hello world`.
  * 1.3 and 1.4 were both implemented in 1.4.c
* Ch. 4:
  * I skipped 4.10, because I re-architected the RPN calculator to loosely couple and more robustly handle parsing, lexing, and token handling; a solution involving parsing the entire string either would require 1) tightly-recoupling these  things so that in one loop you can handle the entire string, determining symbols and pushing it to the stack, or 2) having an intermediary data structure similar to the ungetch() buffer.
  * K&R claim that in 4.9 `getch()` / `ungetch()` don't handle `EOF` correctly, but the expected behavior occurs both in my implementation and theirs so I'm not quite sure what this question is asking. `EOF` does cause the program to exit correctly, although the `EOF` character gets pushed back into the array by `ungets()`.

## Source text
You can find the full 2nd edition text with examples [here](http://cs.indstate.edu/~cbasavaraj/cs559/the_c_programming_language_2.pdf).

## Special thanks
* [Elliott Jin (@robot-dreams)](https://github.com/robot-dreams) for the many hours of help debugging and review.
* [Steven Harris (@seh)](https://github.com/seh) for some helpful feedback on the RPN calculator.
