Ch-5
---

## Notes about the exercises
* `5.1` and `5.2`
  * Calling `ungetc(c, stdin)` before a function exits appears to cause a false positive in Valgrind for that character being lost (even though the character is read back by the caller if the function returns -1)
* `5.2`
  * I wrote `getdouble()` instead.
* `decl`
  * I rewrote `decl` such that it does not run in a loop, and only accepts one line of input, so `recovering from errors` isn't really necessary anymore - instead, I added checks to ensure the program terminates immediately if erroneous input is detected.
  * `scan-build` throws an error about `TYPE` being unused in `dirdecl()`, but this is acceptable given that it is a global variable.
