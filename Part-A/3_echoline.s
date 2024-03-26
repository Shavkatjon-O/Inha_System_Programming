# The following program just reads one line from stdin, using sys_read, then
# echoes it to stdout:
# To create object file using GNU assembler as - $as -gstabs echoline.s -o echoline.o
# To create an executable file after linking - $ld echoline.o -o echoline
# To execute rwstring - $./echoline

.global _start

.data
    buf: .skip 1024

.text
_start:
    movq $0, %rdi               # stdin file descriptor
    movq $buf, %rsi             # buffer
    movq $80, %rdx              # buffer length
    movq $0, %rax               # sys_read
    syscall

    # The sys_read function returns the number of bytes that were read in the rax
    # register, so we use that as the message length in the call to sys_write.

    movq $1, %rdi               # stdout file descriptor
    movq $buf, %rsi             # message to print
    movq %rax, %rdx             # message length
    movq $1, %rax               # sys_write
    syscall

    movq $0, %rdi               # exit with return code =0
    movq $60, %rax
    syscall                     # sys_exit
