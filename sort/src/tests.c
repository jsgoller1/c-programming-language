#include "tests.h"
#include <stdio.h>
#include "sort-tests.h"
#include "sort.h"

static char directory[] = "-d";
static char fold[] = "-f";
static char numeric[] = "-n";
static char reverse[] = "-r";
static char garbage1[] = "-z";
static char garbage2[] = "crap";

static void test_parse_args_helper(int argc, char** argv,
                                   input_flags* expected_flags,
                                   int expected_result, char* message) {
  input_flags flags = {false, false, false, false};
  int result = parse_args(argc, argv, &flags);
  assert_int_eq(result, expected_result, "result - parse_args", message);
  assert_int_eq(flags.directory, expected_flags->directory,
                "directory - parse_args", message);
  assert_int_eq(flags.fold, expected_flags->fold, "fold - parse_args", message);
  assert_int_eq(flags.numeric, expected_flags->numeric, "numeric - parse_args",
                message);
  assert_int_eq(flags.reverse, expected_flags->reverse, "reverse - parse_args",
                message);
}

void test_parse_args() {
  char* argv1[] = {directory, fold, numeric, reverse};
  input_flags expected1 = {true, true, true, true};
  test_parse_args_helper(4, argv1, &expected1, 0, "all flags");

  char* argv2[] = {directory, fold};
  input_flags expected2 = {true, true, false, false};
  test_parse_args_helper(2, argv2, &expected2, 0, "partial flags");

  char* argv3[] = {directory, fold, garbage1, garbage2};
  input_flags expected3 = {true, true, false, false};
  test_parse_args_helper(4, argv3, &expected3, -1, "valid + garbage");

  char** argv4 = NULL;
  input_flags expected4 = {false, false, false, false};
  test_parse_args_helper(0, argv4, &expected4, 0, "empty");

  printf("Args are tested.\n");
}
