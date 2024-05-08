<!-- create static library -->
```
ar rcs <lib-file-path> <compiled-file-path>
```

<!-- create shared library -->
```
gcc -shared -o <lib-file-path> <compiled-file-path>
```

<!-- link at compile time -->
```
gcc -static -o <file-name> <c-file-path> <lib-file-path>
```

<!-- link at load time -->
```
gcc -o <file-name> <c-file-path> <lib-file-path>
```

<!-- link at run time -->
```
gcc -rdynamic -o <file-name> <c-file-path> -ldl
```
