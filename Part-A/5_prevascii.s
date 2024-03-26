# Convert Characters to Previous ASCII program
# Assemble with GNU assembler: $as -o prevascii.o prevascii.s
# Link with GNU linker: $ld prevascii.o -o prevascii
# Execute: $./prevascii

.global _start

.section .data
    message: .asciz "ENTER A STRING:"
    givenstr: .skip 160
    prevchars: .space 160

.section .text
_start:
    # Prompt user to enter a string
    movq $1, %rax         # sys_write
    movq $1, %rdi         # stdout file descriptor
    movq $message, %rsi   # message to print
    movq $16, %rdx        # message length
    syscall

    # Read string from stdin
    movq $0, %rdi         # stdin file descriptor
    movq $givenstr, %rsi  # buffer to read into
    movq $160, %rdx       # buffer length
    movq $0, %rax         # sys_read
    syscall

    # Convert characters to previous ASCII
    movq %rax, %r8        # save input length
    movq %r8, %rcx        # set loop counter
up:
    movq $givenstr, %rsi  # source string
    movq $prevchars, %rdi # destination string
    movb (%rsi), %al      # load character into AL
    subb $1, %al          # decrement ASCII value
    movb %al, (%rdi)      # store in prevchars buffer
    incq %rsi             # move to next character in input string
    incq %rdi             # move to next position in prevchars string
    decq %rcx             # decrement loop counter
    jnz up                # loop until all characters are processed

    movq %r8, %rdx        # message length for sys_write
    movq $1, %rax         # sys_write
    movq $1, %rdi         # stdout file descriptor
    movq $prevchars, %rsi # message to print
    syscall

    # Exit
    movq $60, %rax        # sys_exit
    xorq %rdi, %rdi       # return code = 0
    syscall
