/*
 * --------------------------------------------------------
 *  Maths
 * --------------------------------------------------------
 */

int powi(const int base, const int exp) {
  if (exp == 0) {
    return 1;
  } else {
    return base * powi(base, exp - 1);
  }
}
