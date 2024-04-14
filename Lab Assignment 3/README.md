6. arithxy.s

```
as -gstabs arithxy.s -o arithxy.o
ld -dynamic-linker /lib64/ld-linux-x86-64.so.2 arithxy.o -o arithxy -lc
./arithxy
```