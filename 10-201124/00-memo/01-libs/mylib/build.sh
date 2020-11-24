#!/bin/bash
set -e  # Если хотя бы одна команда упала, то скрипт тоже падает

g++ src/mylib.cpp -c -Iinclude
g++ src/mylib_private.cpp -c -Iinclude
ar rcs libmy.a mylib.o mylib_private.o
