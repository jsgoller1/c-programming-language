# Ch. 4
To avoid unnecessary code replication over minor changes, exercises 4.3 through 4.9 have been grouped into `reverse-polish-calc/`, which I completely overhauled to use more robust parsing / lexing.

## Notes about the exercises
* 4.9:
  * K&R claim that `getch()` / `ungetch()` don't handle `EOF` correctly, but the expected behavior occurs both in my implementation and theirs so I'm not quite sure what this question is asking. `EOF` does cause the program to exit correctly, although the `EOF` character gets pushed back into the array by `ungets()`.
* 4.10:
  * I sort-of skipped this because I re-architected the RPN calculator to loosely couple and more robustly handle parsing, lexing, and token handling; a solution involving parsing the entire string either would require 1) tightly-recoupling these things so that in one loop you can handle the entire string, determining symbols and pushing it to the stack, or 2) having an intermediary data structure similar to the ungetch() buffer.
