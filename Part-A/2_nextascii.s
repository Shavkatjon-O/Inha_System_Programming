# The following program takes each character in the string stored at message
# in memory and converts it to its next ascii character, stores it in buffer
# memory at nxtasciim :
# To create object file using GNU assembler as - $as -gstabs nextascii.s -o nextascii.o
# To create an executable file after linking - $ld nextascii.o -o nextascii
# To execute nextascii - $./nextascii

.global _start

.data
    message: .asciz "SYSTEM PROGRAMMING Lab Assignment 3\n"
    nxtasciim: . space 100

.text
_start:
    movq $1, %rax
    movq $1, %rdi
    movq $message, %rsi
    movq $36, %rdx
    syscall
up:
    movq $35, %rcx
    movq $nxtasciim, %rdi
    movq $message, %rsi
    movb (%rsi), %al
    addb $1, %al
    movb %al, (%rdi)
    incq %rsi
    incq %rdi
    decq %rcx
    jnz up
    movb (%rsi), %al
    movb %al, (%rdi)
    movq $1, %rax
    movq $1, %rdi
    movq $nxtasciim, %rsi
    movq $36, %rdx
    syscall

    movq $60, %rax
    xorq %rdi, %rdi
    syscall
    