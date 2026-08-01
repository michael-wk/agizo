#!/bin/bash


# building obj files for azigo

echo "Starting Build"

echo "> creating build dir"
mkdir -p build/temp

echo "> assembling lexer"
gcc -Iagizo/include -c agizo/source/lexer.c -o build/temp/lexer.o

echo "> assembling parser"
gcc -Iagizo/include -c agizo/source/parser.c -o build/temp/parser.o

echo "> assembling evaluator"
gcc -Iagizo/include -c agizo/source/evaluator.c -o build/temp/evaluator.o

echo "> assembling runtime"
gcc -Iagizo/include -c agizo/source/runtime.c -o build/temp/runtime.o

echo "> assembling dtypes"
gcc -Iagizo/include -c agizo/source/dtypes.c -o build/temp/dtypes.o

echo "> assembling main"
gcc -Iagizo/include -c agizo/main.c -o build/temp/main.o




echo "> linking program"
gcc build/temp/lexer.o build/temp/parser.o build/temp/evaluator.o build/temp/runtime.o build/temp/dtypes.o build/temp/main.o -o build/agizo.out



rm -d -r build/temp

echo "> build completed"

