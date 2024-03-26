# Convert Uppercase to Lowercase program
# Assemble with GNU assembler: $as -o upper2lower.o upper2lower.s
# Link with GNU linker: $ld upper2lower.o -o upper2lower
# Execute: $./upper2lower

.global _start

.section .data
    message: .asciz "ENTER A STRING:"
    givenstr: .skip 160
    lowerstr: .space 160

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

    # Convert uppercase to lowercase
    movq %rax, %r8        # save input length
    movq %r8, %rcx        # set loop counter
up:
    movb (%rsi), %al      # load character into AL
    cmp $65, %al          # compare with 'A'
    jl down1              # if less than 'A', go to down1
    cmp $90, %al          # compare with 'Z'
    jg down1              # if greater than 'Z', go to down1
    addb $32, %al         # convert to lowercase
    movb %al, (%rdi)      # store in lowercase string
    incq %rsi             # move to next character in input string
    incq %rdi             # move to next position in lowercase string
    decq %rcx             # decrement loop counter
    jnz up                # loop until all characters are processed

down1:
    movb (%rsi), %al      # copy null terminator
    movb %al, (%rdi)      # to end of lowercase string

    # Print lowercase string
    movq $1, %rax         # sys_write
    movq $1, %rdi         # stdout file descriptor
    movq $lowerstr, %rsi  # message to print
    movq %r8, %rdx        # message length from input
    syscall

    # Exit
    movq $60, %rax        # sys_exit
    xorq %rdi, %rdi       # return code = 0
    syscall
