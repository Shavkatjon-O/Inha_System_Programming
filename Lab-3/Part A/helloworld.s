# PART-A | QUESTION-1

# Program helloworld.s
# To create object file using GNU assembler as - $ as -gstabs helloworld.s -o helloworld.o
# To create an executable file after linking - $ ld helloworld.o -o helloworld
# To execute helloworld - $ ./helloworld

.global _start

.data
    message: .ascii "Hello World\n"

.text
_start:
    movq $1, %rax           # system call 1 is write
    movq $1, %rdi           # file handle 1 is stdout
    movq $message, %rsi     # address of string in memory to output
    movq $13, %rdx          # number of bytes
    syscall                 # invoke operating system to print

    movq $60, %rax          # system call 60 is exit
    xorq %rdi, %rdi         # return code 0
    syscall                 # invoke operating system to exit
