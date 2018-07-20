Ch-5
---

## Notes about the exercises
* `decl`
  * I rewrote `decl` such that it does not run in a loop, and only accepts one line of input, so `recovering from errors` isn't really necessary anymore - instead, I added checks to ensure the program terminates immediately if erroneous input is detected.
  * `scan-build` throws an error about `TYPE` being unused in `dirdecl()`, but this is acceptable given that it is a global variable.
