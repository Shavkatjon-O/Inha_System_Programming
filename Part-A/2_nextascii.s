# The following program takes each character in the string stored at message
# in memory and converts it to its next ascii character, stores it in buffer
# memory at nxtasciim :
# To create object file using GNU assembler as - $ as -gstabs nextascii.s -o nextascii.o
# To create an executable file after linking - $ ld nextascii.o -o nextascii
# To execute nextascii - $ ./nextascii

.global _start

.data
    message:    .asciz "SYSTEM PROGRAMMING Lab Assignment 3\n"
    nxtasciim:  .space 100

.text
_start:
    # Print initial message
    movq $1, %rax           # syscall number for sys_write
    movq $1, %rdi           # file descriptor 1 (stdout)
    movq $message, %rsi     # message to print
    movq $37, %rdx          # message length (including null-terminator)
    syscall                 # invoke syscall to print message

up:
    # Loop to modify message
    movq $36, %rcx          # loop counter (message length without null-terminator)
    movq $nxtasciim, %rdi   # destination address for modified message
    movq $message, %rsi     # source address for original message

loop_start:
    movb (%rsi), %al        # load a byte from source
    addb $1, %al            # increment byte by 1
    movb %al, (%rdi)        # store byte to destination

    incq %rsi               # move to next byte in source
    incq %rdi               # move to next byte in destination
    loop loop_start         # loop until rcx is zero

    # Add null-terminator to modified message
    movb $0, (%rdi)         # store null-terminator at the end of modified message

    # Print modified message
    movq $1, %rax           # syscall number for sys_write
    movq $1, %rdi           # file descriptor 1 (stdout)
    movq $nxtasciim, %rsi   # message to print
    movq $37, %rdx          # message length (including null-terminator)
    syscall                 # invoke syscall to print modified message

    # Exit program
    movq $60, %rax          # syscall number for sys_exit
    xorq %rdi, %rdi         # exit status 0
    syscall                 # invoke syscall to exit
