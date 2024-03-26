#!/bin/bash

# check if file path is given
if [ $# -eq 0 ]; then
    echo "Usage: $0 <file_path>"
    exit 1
fi

# get file path from command line argument
file_path="$1" 
file=$(basename -- "$file_path")
file_without_extension="${file%.*}"

# compile file
echo "[INFO]    Compiling..."
as -gstabs -o "$file_without_extension.o" "$file_path"

if [ $? -eq 0 ]; then
    echo "[INFO]    Compilation successful!"
else
    echo "[ERROR]   Compilation failed."
fi

# link file
echo "[INFO]    Linking..."
ld -o "$file_without_extension" "$file_without_extension.o"

if [ $? -eq 0 ]; then
    echo "[INFO]    Linking successful!"
else
    echo "[ERROR]   Linking failed."
fi

# run file
echo "[INFO]    Running..."

echo -e "\n-------------------------------------------------\n"

./"$file_without_extension"

echo -e "\n-------------------------------------------------\n"

if [ $? -eq 0 ]; then
    echo "[INFO]    Running successful!"
else
    echo "[ERROR]   Running failed."
fi

# clean up
echo "[INFO]    Cleaning up..."
rm "$file_without_extension.o"
rm "$file_without_extension"
echo "[INFO]    DONE!"
