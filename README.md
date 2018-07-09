# The C Programming Language (K&R)
Exercises from "The C Programming Language" by Kernighan / Ritchie.

## Important Note
This was the first book I read that qualifies as "one of those CS books everyone should read," and also the first time I tried doing every exercise in a textbook. As such, it's taken a _very_ long time to complete (200+ hours over 6 months), but a lot of that is because in addition to learning C I also learned how to write code productively and how to read a CS textbook productively. As such, I jumped around a lot and code quality varies wildly
in some places because I got better at programming as I went along.

## Goals
My goals for this textbook changed as I read it. I settled on the following definition for "complete":
- All pages read
- All exercises solved, with maximum const correctness
- All solutions compile against C11 with `-Werror -Wall`
- All solutions report no issues from Clang's static analyzer (`scan-build`), excluding false positives
- All solutions report no memory leaks in `valgrind` when run with `--leak-check=full --show-leak-kinds=all`

I have _not_ tried to hold to the text as closely as possible at the cost of writing straightforward code; e.g. I may use structs in my solutions in chapter 5 despite them not being introduced til chapter 6.

## Running
Each exercise has its own target (e.g. `make 5.4` will make exercise 4 in chapter 5). `make all` compiles all exercises, and runs some with test input. Some exercises are refactored into their own shared subprograms when warranted; e.g. 5.14 - 5.17 are all about the `sort` program, so they exist in `ch-5/sort/`. Makefile targets exist for these solutions independently.

## Highlights
* Ch-4
  * `rpc/` - the [Reverse Polish Notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation) calculator
* Ch-5
  * `decl/` - the UNIX `decl` program (similar to `cdecl`)
  * `sort/` - the UNIX `sort` program
  * `tail/` - the UNIX `tail` program
* Ch-8
  * `fopen_j/` - buffered FILE I/O
  * `malloc_j/` - a storage allocator / the final boss of K&R
* Misc.
  * `common/` - a "standard library" of various types of functions most exercises consume
  * `common/trees/` - a generic binary search tree library I wrote to handle exercises in Chapter 6
  * `common/tests/` - a simple unit testing library that wraps around the `assert(3)` macro; I wound up not using this too much.
  * [C FAQ](https://github.com/jsgoller1/c-faq) - this is a separate repo I started to help work through questions I had about C as I read K&R.

## Conventions
I have my editor set up to run `clang-format -i --style=Google` on save. See `conventions.c` for an example file and listing of conventions.

## Notes about the exercises
* General:
  * For programs reading from stdin, it is expected behavior that you will need to hit CTRL-D twice to exit if the last character entered was not a newline - this behavior is defined by the POSIX standard (see this [Stack Overflow question](https://stackoverflow.com/questions/21260674/why-do-i-need-to-type-ctrl-d-twice-to-mark-end-of-file?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa)).
* Ch. 1:
  * 1.1, 1.2:
    * These did not have any demo-able code; the instructions were just `experiment with hello world`.
* Ch. 4:
  * 4.9:
    * K&R claim that `getch()` / `ungetch()` don't handle `EOF` correctly, but the expected behavior occurs both in my implementation and theirs so I'm not quite sure what this question is asking. `EOF` does cause the program to exit correctly, although the `EOF` character gets pushed back into the array by `ungets()`.
  * 4.10:
    * I sort-of skipped this because I re-architected the RPN calculator to loosely couple and more robustly handle parsing, lexing, and token handling; a solution involving parsing the entire string either would require 1) tightly-recoupling these things so that in one loop you can handle the entire string, determining symbols and pushing it to the stack, or 2) having an intermediary data structure similar to the ungetch() buffer.
* Ch. 5:
  * 5.18 (`decl`):
    * I rewrote `decl` such that it does not run in a loop, and only accepts one line of input, so `recovering from errors` isn't really necessary anymore - instead, I added checks to ensure the program terminates immediately if erroneous input is detected.
    * `scan-build` throws an error about `TYPE` being unused in `dirdecl()`, but this is acceptable given that it is a global variable.
* Ch. 6:
  * 6.2 (`charmatch`):
    * I wound up narrowing the scope of this problem significantly and ignoring a few legitimate edge cases; I would need to write a complete C parser and preprocessor to catch every possible variable, which is out of scope.
    * I left stubbed out code in for handling `typedefs` and `#defines`; I consider this in-scope and will return to it.
  * 6.3 (`crossref`):
    * I spent a few days chasing memory-related bugs in this program, so I didn't bother trying to filter out `noise words` from the final output.
    * I copied and modified the tree code in `crossref` into `common/` to be usable as a generic tree library for 6.4 and other exercises, but I didn't bother making 6.3 use it; I can and probably should refactor 6.3 if I ever get around to it.
* Ch. 7:
  * 7.3: _technically_ is done since all I did was make it possible to print hex / octal values, but I'd like to return to it and see if I can get min / max width working too.

## Source text
You can find the full 2nd edition text with examples [here](http://cs.indstate.edu/~cbasavaraj/cs559/the_c_programming_language_2.pdf).

## Special thanks
* [Elliott Jin](https://github.com/robot-dreams) for the many hours of help with debugging and review.
* [Steven Harris](https://github.com/seh) for feedback on the RPN calculator.
* [Michael McLoughlin](https://github.com/mmcloughlin) for help on buffered FILE I/O.
* [Bartosz Wróblewski](https://github.com/bawr) for feedback on the memory allocator.
