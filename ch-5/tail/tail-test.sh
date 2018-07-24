#!/bin/bash
# This file is explicitly for testing the 5.13 exercise for replicating
# the GNU tail program and should be called via the Makefile.

TESTFILE=tail-test.txt

function clean_up(){
  rm $TESTFILE
}
trap clean_up EXIT

function fatal(){
  local MESSAGE=${1}
  echo $MESSAGE
  echo "5.13: FAIL."
  exit
}

function tail_test(){
  if [[ -z ${1} ]]
  then
    local N=""
  else
    local N="-n ${1}"
  fi

  local EXPECTED_OUT_LINES=${2}
  local TEST_NAME=${3}


  ACTUAL_OUT_LINES=$(cat $TESTFILE | valgrind -q --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=42 bin/tail $N 2>&1 | wc -l )

  if [[ $ACTUAL_OUT_LINES -ne $EXPECTED_OUT_LINES || $? -eq 42 ]]
  then
    fatal "Test failure, $TEST_NAME: $ACTUAL_OUT_LINES != $EXPECTED_OUT_LINES (check Valgrind output)"
  fi
}

function generate_test_file(){
  local SIZE=${1}
  for LINE in `seq 1 $SIZE`; do
    echo $LINE >> $TESTFILE;
  done
}

generate_test_file 20
tail_test "" 10 "basic input"
tail_test 25 20 "larger n"
tail_test 1 1 "n = 1"
tail_test 0 0 "n = 0"

#clean_up
#echo "Generating huge input for tail; this is slow."
#generate_test_file 20000
#echo "Huge input generated."
#tail_test "" 10 "Huge input"

echo "5.13: PASS!"
