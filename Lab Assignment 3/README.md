1. helloworld.s

```
as -gstabs helloworld.s -o helloworld.o
ld helloworld.o -o 
./helloworld
```

2. nextascii.s

```
as -gstabs nextascii.s -o nextascii.o
ld nextascii.o -o nextascii
./nextascii
```

3. echoline.s

```
as -gstabs echoline.s -o echoline.o
ld echoline.o -o echoline
./echoline
```

4. upper2lower.s

```
as -gstabs upper2lower.s -o upper2lower.o
ld upper2lower.o -o upper2lower
./upper2lower
```

5. prevascii.s

```
as -gstabs prevascii.s -o prevascii.o
ld prevascii.o -o prevascii
./prevascii
```

6. arithxy.s

```
as -gstabs arithxy.s -o arithxy.o
ld -dynamic-linker /lib64/ld-linux-x86-64.so.2 arithxy.o -o arithxy -lc
./arithxy
```

7. fib.s

```
as -gstabs fib.s -o fib.o
ld -dynamic-linker /lib64/ld-linux-x86-64.so.2 fib.o -o fib -lc
./fib
```
