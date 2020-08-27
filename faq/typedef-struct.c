#include <stdio.h>

// I've always been confused about struct syntax
// with typedef. Here's some examples.

// This declares a kind of struct called "point_2d"
struct point_2d {
  int x;
  int y;
};

int main() {
  // We can use point_2d like this, and reference it
  // via "p":
  struct point_2d p;
  p.x = 5;
  printf("p.x: %d\n", p.x);

  /*
  Now for some confusing syntax. If we're _not_ using
  typedef, then a lexeme present in between the closing }
  and the semicolon in the struct declaration will cause
  the statement to be parsed as an inline struct definition
  and declaration(s) with the lexemes being names of
  instances of that struct.
  */
  struct point_3d {
    int x;
    int y;
    int z;
  } inline_struct_1, inline_struct_2;

  // inline_struct_1 and inline_struct_2 are now structs of type point_3d
  inline_struct_1.x = 666;
  printf("inline_struct_1.x: %d\n", inline_struct_1.x);
  inline_struct_2.x = 777;
  printf("inline_struct_2.x: %d\n", inline_struct_2.x);

  // We can reuse the above struct definition, despite
  // it being inline.
  struct point_3d not_inline;
  not_inline.x = 888;
  printf("not_inline.x: %d\n", not_inline.x);

  /*
  On the other hand, if we use the typedef keyword,
  this changes. Recall that the syntax is: typedef <type> <newname>
  Here's one way to create a struct and then typedef it
  to something simpler:
  */
  struct point_4d {
    int x;
    int y;
    int z;
    int w;
  };
  typedef struct point_4d Point;

  /*
  However, this can be expressed more concisely.
  The following syntax creates an inline struct
  definition called point_4d_v2 and typedefs it
  to Point_v2:
  */
  typedef struct point_4d_v2 {
    int x;
    int y;
    int z;
    int w;
  } Point_v2;

  // Then we can use Point/Point_v2 the way you'd expect:
  Point k;
  Point_v2 k2;
  k.w = 15;
  k2.w = 16;
  printf("k.w: %d\n", k.w);
  printf("k2.w: %d\n", k2.w);

  return 0;
}
