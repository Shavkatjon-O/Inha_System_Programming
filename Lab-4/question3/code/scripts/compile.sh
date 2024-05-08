#!/bin/bash

# compile time interposition
gcc -Wall -DCOMPILETIME -c src/wrappers/malloc_compile.c -o bin/wrappers/malloc_compile.o
gcc -Wall -I./include -o main_compile src/main.c bin/wrappers/malloc_compile.o

# link time interposition
gcc -Wall -DLINKTIME -c src/wrappers/malloc_link.c -o bin/wrappers/malloc_link.o
gcc -Wall -Wl,--wrap,malloc -Wl,--wrap,free -o main_link src/main.c bin/wrappers/malloc_link.o