.global _start
.data
message: .asciz "SYSTEM PROGRAMMING Lab Assignment 3\n"
nxtasciim: .space 100
.text
_start:
    movq $1, %rax      # sys_write system call
    movq $1, %rdi      # file descriptor (stdout)
    movq $message, %rsi    # pointer to the message string
    movq $36, %rdx     # message length
    syscall            # invoke system call to print the message

up:
    movq $35, %rcx     # loop counter
    movq $nxtasciim, %rdi  # destination buffer
    movq $message, %rsi    # source string
    movb (%rsi), %al   # load a byte from source
    addb $1, %al       # increment byte value (next ASCII character)
    movb %al, (%rdi)   # store the modified byte in destination
    incq %rsi          # move to the next byte in source
    incq %rdi          # move to the next byte in destination
    decq %rcx          # decrement loop counter
    jnz up             # repeat until loop counter is not zero

    movb (%rsi), %al   # copy the null terminator
    movb %al, (%rdi)   # store the null terminator in destination buffer

    movq $1, %rax      # sys_write system call
    movq $1, %rdi      # file descriptor (stdout)
    movq $nxtasciim, %rsi    # pointer to the modified string
    movq $36, %rdx     # modified string length
    syscall            # invoke system call to print the modified string

    movq $60, %rax     # sys_exit system call
    xorq %rdi, %rdi    # return code 0
    syscall            # invoke system call to exit the program
