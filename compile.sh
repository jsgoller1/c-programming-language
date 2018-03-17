#!/bin/bash

clang -std=c11 -g -Weverything $1 -o out && ./out
