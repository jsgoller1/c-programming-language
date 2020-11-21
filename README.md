# The C Programming Language (K&R)
Solutions for every exercise from "The C Programming Language" by Kernighan / Ritchie. 

## Goals
 This was the first "classic CS book" that I read; in addition to learning C, I also learned how to write code productively and how to read a CS textbook. As such, my goals for this textbook changed as I read it (especially given that I jumped around a good bit). I settled on the following definition for "complete":
- All pages read, including the appendices
- All exercises solved, with maximum const correctness
- All solutions compile against C11 with `-Werror -Wall`
- All solutions report no issues from Clang's static analyzer (`scan-build`), excluding false positives
- All solutions report no memory leaks in `valgrind` when run with `--leak-check=full --show-leak-kinds=all`

I have _not_ tried to hold to the text as closely as possible at the cost of writing straightforward code; e.g. I may use structs in my solutions in chapter 5 despite them not being introduced til chapter 6.

## Running via Makefile
All exercises are built via Makefile and should be executed from the top-level of the repo, inside the Dockerized workspace (see `makefiles/docker.mk` for targets to create this workspace).

Every exercise either has its own target (e.g. `make 5.4` will make exercise 4 in chapter 5) or is grouped into a subproject with its own target (e.g. 5.14 - 5.17 are all about the `sort` program, so they exist in `ch-5/sort/` and are built with `make sort`). Chapters also have their own targets (e.g. all exercises from chapter 6 are buildable with `make ch-6`), and `make all` builds everything. All buildable targets are listed in the top-level Makefile, at the botom.

The Makefile system is divided into four parts:
* Chapter-specific Makefiles containing specific patterns for building and testing individual exercises.
* A `docker.mk` for managing the Dockerized workspace.
* A `buikding.mk` containing build settings; you can find targets for producing binaries and toggle valgrind, static analysis, and tests from this file.
* A top level Makefile tying everything together; all exercises should be built in the top-level directory of the repo.

## Top Highlights
* `ch-8/malloc_j/` - a storage allocator / the final boss of K&R
* `common/trees/` - a generic binary search tree library I wrote to handle exercises in Chapter 6
* `ch-8/fopen_j/` - buffered FILE I/O
* `common/tests/` - a simple unit testing library that wraps around the `assert(3)` macro; I wound up not using this too much beyond ch-1 as my testing stategy evolved.
* `faq/` - Experiments / questions I had to test my understanding of C as I read K&R.

## Conventions
I have my editor set up to run `clang-format -i --style=Google` on save.

## Notes about the exercises
* Each chapter / subproject has its own README.md; see these for specific notes.
* For programs reading from stdin, it is expected behavior that you will need to hit CTRL-D twice to exit if the last character entered was not a newline - this behavior is defined by the POSIX standard (see this [Stack Overflow question](https://stackoverflow.com/questions/21260674/why-do-i-need-to-type-ctrl-d-twice-to-mark-end-of-file?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa)).

## Source text
You can find the full 2nd edition text with examples [here](http://cs.indstate.edu/~cbasavaraj/cs559/the_c_programming_language_2.pdf). You can find problem statements and solutions [here](https://clc-wiki.net/wiki/K%26R2_solutions:Chapter_4).

## Special thanks
* [Elliott Jin](https://github.com/robot-dreams) for the many hours of help with debugging and review.
* [Steven Harris](https://github.com/seh) for feedback on the RPN calculator.
* [Michael McLoughlin](https://github.com/mmcloughlin) for help on buffered FILE I/O.
* [Bartosz Wróblewski](https://github.com/bawr) for feedback on the memory allocator.
