# Convert each character in a string to its next ASCII character
# Assemble with GNU assembler: $as -o nextascii.o nextascii.s
# Link with GNU linker: $ld nextascii.o -o nextascii
# Execute: $./nextascii

.global _start

.section .data
    message: .asciz "SYSTEM PROGRAMMING Lab Assignment 3\n"
    nxtasciim: .space 100

.section .text
_start:
    # write syscall (1) - write to stdout (1)
    movq $1, %rax         # syscall number 1 (write)
    movq $1, %rdi         # file descriptor (stdout)
    movq $message, %rsi   # address of the original string
    movq $36, %rdx        # number of bytes to write
    syscall

up:
    movq $35, %rcx        # loop counter
    movq $nxtasciim, %rdi # destination buffer
    movq $message, %rsi   # source string
    movb (%rsi), %al      # load current character
    addb $1, %al          # increment ASCII value by 1
    movb %al, (%rdi)      # store in buffer
    incq %rsi             # move to next character in source
    incq %rdi             # move to next location in buffer
    decq %rcx             # decrement loop counter
    jnz up                # loop until all characters processed

    movb (%rsi), %al      # load null terminator
    movb %al, (%rdi)      # copy null terminator to buffer

    # write syscall (1) - write modified string to stdout
    movq $1, %rax         # syscall number 1 (write)
    movq $1, %rdi         # file descriptor (stdout)
    movq $nxtasciim, %rsi # address of the modified string
    movq $36, %rdx        # number of bytes to write
    syscall

    # exit syscall (60) - exit with return code 0
    movq $60, %rax        # syscall number 60 (exit)
    xorq %rdi, %rdi       # return code 0
    syscall
