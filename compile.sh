#!/bin/bash

clang -std=c11 -g -Weverything -Werror -I ./include/* $1 -o out && ./out
