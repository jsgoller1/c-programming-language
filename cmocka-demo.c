#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
// -- cmocka has to be included last because it relies on stdlib headers --
#include <cmocka.h>

/*
cmocka is the unit testing framework I used while reading K&R. This is a little
test to demo some of the useful features. Docs:
https://api.cmocka.org/group__cmocka.html
*/

typedef struct p {
  int x;
  int y;
  int z;
  int w;
} point;

static int return_sum(int x, int y) { return x + y; }

static point *make_point(int x, int y, int z) {
  point *my_point = (point *)malloc((unsigned long)sizeof(point));
  my_point->x = x;
  my_point->y = y;
  my_point->z = z;
  my_point->w = 0;
  return my_point;
}

static char *my_name(void) {
  char *name = (char *)malloc(strlen("Joshua"));
  strcpy(name, "Joshua");
  return name;
}

static void test_my_name(void **state) {
  (void)state;
  char *name = my_name();
  char actual_name[] = {"Clarence"};
  assert_string_equal(name, actual_name);
  free(name);
}

static void test_make_point(void **state) {
  (void)state;
  point my_point = {1, 2, 3, 0};
  point *my_other_point = make_point(1, 2, 3);
  assert_memory_equal(&my_point, my_other_point, sizeof(point));
  free(my_other_point);
}

static void test_return_sum(void **state) {
  (void)state;
  assert_int_equal(4, return_sum(2, 2));
  assert_int_equal(0, return_sum(0, 0));
  assert_int_not_equal(11, return_sum(2, 5));
}

int main(void) {
  const struct CMUnitTest tests[] = {cmocka_unit_test(test_return_sum),
                                     cmocka_unit_test(test_make_point),
                                     cmocka_unit_test(test_my_name)};

  return cmocka_run_group_tests(tests, NULL, NULL);
}
