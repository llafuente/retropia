#!/bin/sh

rm test
# -v
# linux: -fsanitize=memory -fno-omit-frame-pointer
clang controller.c nintendo.c sega.c functions.c test.c -g -O3 -o test

./test
