#include "tests.h"
#include <stdio.h>
#include "sort-tests.h"
#include "sort.h"

static char bin[] = "bin/sort";
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
  char* argv1[] = {bin, directory, fold, numeric, reverse};
  input_flags expected1 = {true, true, true, true};
  test_parse_args_helper(5, argv1, &expected1, 0, "all flags");

  char* argv2[] = {bin, directory, fold};
  input_flags expected2 = {true, true, false, false};
  test_parse_args_helper(3, argv2, &expected2, 0, "partial flags");

  char* argv3[] = {bin, directory, fold, garbage1, garbage2};
  input_flags expected3 = {true, true, false, false};
  test_parse_args_helper(5, argv3, &expected3, -1, "valid + garbage");

  char* argv4[] = {bin};
  input_flags expected4 = {false, false, false, false};
  test_parse_args_helper(1, argv4, &expected4, 0, "no args");

  char** argv5 = NULL;
  input_flags expected5 = {false, false, false, false};
  test_parse_args_helper(0, argv5, &expected5, 0, "empty");

  printf("Args are tested.\n");
}

static void test_foldcmp_helper(const char* const s1, const char* const s2,
                                int expected, const char* const message) {
  int result = foldcmp(s1, s2);
  assert_int_eq(result, expected, "foldcmp", message);
}

void test_foldcmp() {
  test_foldcmp_helper("angelo", "AnGeLo", 0, "normal input");
  test_foldcmp_helper("ANGELO", "ANGELO", 0, "all upper");
  test_foldcmp_helper("ANGELO", "angelo", 0, "all lower");
  test_foldcmp_helper("Angelo", "Anthony", -13, "non-matching");
  test_foldcmp_helper("", "angelo", -97, "one empty");
  test_foldcmp_helper("", "", 0, "both empty");
}
