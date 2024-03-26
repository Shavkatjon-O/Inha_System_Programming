# Echo Line program
# Assemble with GNU assembler: $as -o echoline.o echoline.s
# Link with GNU linker: $ld echoline.o -o echoline
# Execute: $./echoline

.global _start

.section .data
    buf: .skip 1024

.section .text
_start:
    # Read from stdin
    movq $0, %rdi        # stdin file descriptor
    movq $buf, %rsi      # buffer to read into
    movq $80, %rdx       # buffer length
    movq $0, %rax        # sys_read syscall number
    syscall

    # Write to stdout
    movq $1, %rdi        # stdout file descriptor
    movq $buf, %rsi      # message to print
    movq %rax, %rdx      # message length from sys_read
    movq $1, %rax        # sys_write syscall number
    syscall

    # Exit
    movq $0, %rdi        # return code = 0
    movq $60, %rax       # sys_exit syscall number
    syscall
