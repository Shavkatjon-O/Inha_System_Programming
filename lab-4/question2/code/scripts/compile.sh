#!/bin/bash

SOURCE_DIR="src/matrix"
STATIC_OUTPUT_DIR="bin/static"
SHARED_OUTPUT_DIR="bin/shared"

STATIC_LIB_DIR="lib/static"
SHARED_LIB_DIR="lib/shared"

mkdir -p $STATIC_OUTPUT_DIR
mkdir -p $SHARED_OUTPUT_DIR

mkdir -p $STATIC_LIB_DIR
mkdir -p $SHARED_LIB_DIR


# compile routines for static library
for file in $SOURCE_DIR/*.c; do
    filename=$(basename "$file")
    gcc -c -Wall -Werror -O2 $file -o $STATIC_OUTPUT_DIR/${filename%.c}.o
done

# compile routines for shared library
for file in $SOURCE_DIR/*.c; do
    filename=$(basename "$file")
    gcc -c -fPIC -Wall -Werror -O2 $file -o $SHARED_OUTPUT_DIR/${filename%.c}.o
done

# create static library
ar rcs $STATIC_LIB_DIR/libmatrix.a $STATIC_OUTPUT_DIR/*.o

# create shared library
gcc -shared -o $SHARED_LIB_DIR/libmatrix.so $SHARED_OUTPUT_DIR/*.o
