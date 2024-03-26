# Hello World program
# Assemble with GNU assembler: $as -o helloworld.o helloworld.s
# Link with GNU linker: $ld helloworld.o -o helloworld
# Execute: $./helloworld

.global _start

.section .data
    message: .ascii "Hello World\n"

.section .text
_start:
    # write syscall (1) - write to stdout (1)
    movq $1, %rax         # syscall number 1 (write)
    movq $1, %rdi         # file descriptor (stdout)
    movq $message, %rsi   # address of the string
    movq $13, %rdx        # number of bytes to write
    syscall

    # exit syscall (60) - exit with return code 0
    movq $60, %rax        # syscall number 60 (exit)
    xorq %rdi, %rdi       # return code 0
    syscall
