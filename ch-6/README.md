Ch-6
---

## Notes about the exercises
* `charmatch`
  * I wound up narrowing the scope of this problem significantly and ignoring a few legitimate edge cases; I would need to write a complete C parser and preprocessor to catch every possible variable, which is out of scope.
  * I left stubbed out code in for handling `typedefs` and `#defines`; I consider this in-scope and will return to it.
* `crossref`
  * I spent a few days chasing memory-related bugs in this program, so I didn't bother trying to filter out `noise words` from the final output.
  * I copied and modified the tree code in `crossref` into `common/` to be usable as a generic tree library for 6.4 and other exercises, but I didn't bother making 6.3 use it; I can and probably should refactor 6.3 if I ever get around to it.
