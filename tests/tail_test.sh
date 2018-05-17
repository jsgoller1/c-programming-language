#!/bin/bash

#function clean_up(){
#  rm tail-test.txt
#}
#trap clean_up EXIT

# Create test file
for LINE in `seq 1 20`; do
  echo $LINE >> tail-test.txt;
done

cat tail-test.txt | bin/tail

