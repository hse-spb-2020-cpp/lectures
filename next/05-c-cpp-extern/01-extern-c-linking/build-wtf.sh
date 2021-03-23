#!/bin/bash
gcc a.c -c        # gcc or `-x c`, otherwise will assume c++ regardless of extension
gcc -fno-exceptions b.cpp -c      # gcc or g++ both work(?)
gcc a.o b.o -o a
