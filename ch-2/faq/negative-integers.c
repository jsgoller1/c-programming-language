#include <stdio.h>
#include <limits.h>

// How do negative integers work in C?

int main(){
  /*
  The C spec doesn't designate how negative integers should be stored, but
  typically most arches use the most significant bit of the word to store
  the sign; values with it set are negative, and unset are positive.
  Whenever we see any hex value from 0x80000000 to 0xFFFFFFFF representing a signed int,
  we know they're negative, and any value from 0x00000001 to 0x7FFFFFFF is positive (zero
  is not positive or negative but it "counts" as a positive number, which we will revisit at the end).

  With this convention, we use the "two's complement" procedure to derive a negative
  int from a positive one. The two's complement can be calculated by flipping all
  bits and adding one. Take the number 8 on a 32-bit machine as an example:
  8 = 0b0000...1000 = 0x00000008.
  Flip all bits: 0b1111...0111 (0xFFFFFFF7)
  Add 1 (0b0000...0001): 0b1111...1000 (0xFFFFFFF8)
  */
  printf(" 0x8: %4x\n-0x8: %4x\n", 8, -8);

  /*
  Another example:
  351 on a 32-bit machine.
  351 = 0x0000015f = 0b0000....0001 0101 1111
  Flip bits:         0b1111....1110 1010 0000
  Add one:           0b1111....1110 1010 0001
  Hex:               0xFFFFF    E    A    1
  */
  printf(" 351: %4x\n-351: %4x\n", 351, -351);


  /*
  What if we want to go from a negative number to a positive? Same procedure.
  -754 = 0xFFFFFD0E = 0b1111....1101 0000 1110
  Flip all bits:      0b0000....0010 1111 0001
  Add one:            0b0000....0010 1111 0010
  Hex:                0x00000    2    F    2

  What if we want to go back to the negative? Can "flip, add one" be applied repeatedly?
  0x754:              0x00000    2    F    2
  Binary:             0b0000....0010 1111 0010
  Flip all bits:      0b1111....1101 0000 1101
  Add one:            0b1111....1101 0000 1110
  Hex:                0xFFFFF    D    0    E

  Note that this is the value we started with.
  */
  printf("-754: %4x\n 754: %4x\n\n", -754, 754);

  /*
  Armed with this knowledge, we can now as an important question: what is the biggest
  possible positive number, and least possible negative number? Let's calculate it.
  My current machine (2017 Macbook Pro w/ Intel Core i7) has a 32bit address space,
  which can be determined with WORD_BIT from limits.h
  */
  printf("CPU word size: %d\n\n", WORD_BIT);

  /*
  Recall from before that most arches use the most significant bit of the word to store
  the sign; values with it set are negative, and unset are positive.  With this in mind,
  0x7FFFFFFF is the greatest possible positive value, but what represents the least
  possible negative value - 0x80000000 or 0xFFFFFFFF?

  Well, let's think about our range of positive numbers - the negative version of the greatest positive number
  will almost certainly give us the least negative number, and the negative version of the least positive
  integer will give us the greatest negative integer. Flipping all bits for 0x00000001 gives
  us 0xFFFFFFFE, and then adding 1 gives us 0xFFFFFFFF - so we can hazard a guess that 0x80000000
  is less than 0xFFFFFFFF. But there's an interesting issue here - two's complement of the greatest
  possible positive number, 0x7FFFFFFF is 0x80000001 (flipping all bits is 0x80000000, then add 1
  to get 0x80000001), not 0x80000000. What gives? If two's complement is the binary equivalent
  of multiplying a decimal number by -1, why does performing this operation on the greatest positive
  integer _not_ give us the least negative one?

  Remember above that I said zero "counts" as a positive integer. If you pair
  up all all of the positive values in a 32-bit address space with their negative values -
  (0x0xFFFFFFFF, 0x00000001), (0xFFFFFFFE, 0x00000002), (0xFFFFFFFD, 0x00000003), and so on - you
  wind up with two values left in the address space: 0x00000000 and 0x800000000. 0x00000000 is
  zero, but since there's no such thing as "negative zero", we simply go on to the next possible
  negative value after 0x800000001 - as such, we have one more negative value than positive values.

  So, to find the least negative value, set the sign bit and no other bits; to find the
  greatest positive value, set all other bits except for the sign bit.

  To double check, you can use the following constants from <limits.h> to see your architecture's
  various max and min values for different types:

  CHAR_BIT    |   Number of bits in the smallest variable that is not a bit field.
  SCHAR_MIN   |   Minimum value for a variable of type signed char.
  SCHAR_MAX   |   Maximum value for a variable of type signed char.
  UCHAR_MAX   |   Maximum value for a variable of type unsigned char.
  CHAR_MIN    |   Minimum value for a variable of type char.
  CHAR_MAX    |   Maximum value for a variable of type char.
  MB_LEN_MAX  |   Maximum number of bytes in a multicharacter constant.
  SHRT_MIN    |   Minimum value for a variable of type short.
  SHRT_MAX    |   Maximum value for a variable of type short.
  USHRT_MAX   |   Maximum value for a variable of type unsigned short.
  INT_MIN     |   Minimum value for a variable of type int.
  INT_MAX     |   Maximum value for a variable of type int.
  UINT_MAX    |   Maximum value for a variable of type unsigned int.
  LONG_MIN    |   Minimum value for a variable of type long.
  LONG_MAX    |   Maximum value for a variable of type long.
  ULONG_MAX   |   Maximum value for a variable of type unsigned long.
  */

  signed int neg_1 = 0xffffffff;
  signed int max_pos = 0x7fffffff;
  signed int min_neg = 0x80000000;
  signed int min2_neg = 0x80000001;
  printf("0x7fffffff: %i\nINT_MAX: %i\n0x80000000: %i\n0xffffffff: %i\nINT_MIN: %i\n0x80000001: %i\n", max_pos, INT_MAX, min_neg, neg_1, INT_MIN, min2_neg);

  return 0;
}