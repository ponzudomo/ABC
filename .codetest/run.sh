#!/bin/zsh

g++ main.cpp -o a.out -O2 \
-fdiagnostics-color=always \
-Wall -Wextra \
-fconstexpr-depth=2147483647 \
-fsanitize=address

gtime -f "Time: %e sec\nMemory: %M Kbyte" -o res.txt \
./a.out < in.txt > out.txt 2> err.txt