#!/bin/bash

echo "__________________________________________"
echo "*mk*"

echo "vars : $1 $2 $3"

gcc -I"$2" -c test_1/main.c -o main.o

shopt -s extglob
gcc "$1" "$(find "$1"/temp -name '*.o' ! -name 'main.o')" main.o -o program.out

