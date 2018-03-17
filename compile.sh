#!/bin/bash

clang -std=c11 -g -Weverything -Werror $1 -o out && ./out
