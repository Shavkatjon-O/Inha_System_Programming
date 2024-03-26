# PART-A | QUESTION-4

# The following program reads a string from keyboard, stores it in memory
# starting at location givenstr and then takes each uppercase alphabet in
# that string and converts it to its lowercase alphabet and stores it in memory
# at location lowerstr :
# To create object file using GNU assembler as - $ as -gstabs upper2lower.s -o upper2lower.o
# To create an executable file after linking - $ ld upper2lower.o -o upper2lower
# To execute upper2lower - $ ./upper2lower

.global _start

.data
    message: .asciz "ENTER A STRING :"  # Prompt message
    givenstr: .skip 160                 # Space for input string
    lowerstr: .space 160                # Space for modified lowercase string

.text
_start:
    # Print prompt message

    movq $1, %rax                       # System call number for sys_write (1)
    movq $1, %rdi                       # File descriptor for stdout (1)
    movq $message, %rsi                 # Pointer to the message string
    movq $16, %rdx                      # Length of the message
    syscall                             # Invoke sys_write to print the message

    # Read input string
    
    movq $0, %rdi                       # File descriptor for stdin (0)
    movq $givenstr, %rsi                # Buffer to store input string
    movq $160, %rdx                     # Maximum length of input
    movq $0, %rax                       # System call number for sys_read (0)
    syscall                             # Invoke sys_read to read input string

    # Convert uppercase to lowercase
    
    movq $givenstr, %rsi                # Source string pointer
    movq $lowerstr, %rdi                # Destination string pointer
    movq $0, %rcx                       # Initialize loop counter

up:
    # Loop to convert uppercase to lowercase
    
    movb (%rsi, %rcx), %al              # Load byte from source string
    testb %al, %al                      # Check for end of string
    jz end_loop                         # Jump to end loop if end of string
    cmp $65, %al                        # Compare with ASCII value of 'A'
    jl skip_convert                     # Jump if less than 'A'
    cmp $90, %al                        # Compare with ASCII value of 'Z'
    jg skip_convert                     # Jump if greater than 'Z'
    addb $32, %al                       # Convert uppercase to lowercase

skip_convert:
    movb %al, (%rdi, %rcx)             # Store converted byte to destination
    incq %rcx                           # Move to next byte
    jmp up                              # Repeat the loop

end_loop:
    movq %rcx, %rdx                     # Length of the lowercase string

    # Print converted lowercase string

    movq $1, %rax                       # System call number for sys_write (1)
    movq $1, %rdi                       # File descriptor for stdout (1)
    movq $lowerstr, %rsi                # Pointer to the lowercase string
    syscall                             # Invoke sys_write to print the lowercase string

    # Exit program

    movq $60, %rax                      # System call number for sys_exit (60)
    xorq %rdi, %rdi                     # Exit status (0)
    syscall                             # Invoke sys_exit to terminate program
