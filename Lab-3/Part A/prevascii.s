# PART-A | QUESTION-5

# The following program reads a string from keyboard, stores it in memory
# at location givenstr and then takes each character from that location and
# converts it to its previous ascii character stores it in buffer prevchars:
# To create object file using GNU assembler as - $ as -gstabs prevascii.s -o prevascii.o
# To create an executable file after linking - $ ld prevascii.o -o prevascii
# To execute nextchar - $ ./prevascii

.global _start

.data
    message: .asciz "ENTER A STRING :"
    givenstr: .skip 160
    prevchars: .space 160

.text
_start:
    movq $1, %rax           # sys_write
    movq $1, %rdi
    movq $message, %rsi
    movq $16, %rdx
    syscall

    movq $0, %rdi           # sys_read
    movq $givenstr, %rsi
    movq $160, %rdx
    movq $0, %rax
    syscall

    movq %rax, %r8
    movq %r8, %rcx
    decq %rcx
    movq $givenstr, %rsi
    movq $prevchars, %rdi
up:
    movb (%rsi), %al
    subb $1, %al
    movb %al, (%rdi)
    incq %rsi
    incq %rdi
    decq %rcx
    jnz up
    movb (%rsi), %al
    movb %al, (%rdi)

    movq $1, %rax           # sys_write
    movq $1, %rdi
    movq $prevchars, %rsi
    movq %r8, %rdx
    syscall

    movq $60, %rax          # sys_exit
    xorq %rdi, %rdi
    syscall