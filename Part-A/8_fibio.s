# -----------------------------------------------------------------------------
# A 64-bit Linux application that writes the first n Fibonacci numbers.
# The input value n is to be read from the keyboard.
# Functions called : puts, scanf, printf
# This routine needs to be linked with C library functions at runtime
# To create object file using GNU assembler as
#
# $as -gstabs fibio.s -o fibio.o
# To create an executable file after linking
#
# $ld -dynamic-linker /lib64/ld-linux-x86-64.so.2 fibio.o -o fibio -lc
# To execute fibio
#
# $./fibio
#-----------------------------------------------------------------------------
.global _start
.data
message: .asciz "ENTER A VALUE FOR n :"
format:
    .asciz "%ld"
format_output: 
    .asciz "%20ld\n"
output_message: 
    .asciz "THE LIST OF FIRST n=%ld FIBONACCI NUMBERS\n"
x:
    .quad 0
.text
_start:
    # Print message to prompt user to enter a value for n
    movq $message, %rdi    # message address (or pointer) parameter in %rdi
    call puts              # call C function puts(message pointer)

    # Read input value for n from the keyboard using C scanf function
    movq $format, %rdi     # format string for scanf
    movq $x, %rsi          # address of variable x where input will be stored
    call scanf             # call C function scanf(format, &x)

    # Load n value from variable x
    movq x(%rip), %rcx     # load n value from variable x

    # Print message about the list of first n Fibonacci numbers
    movq $output_message, %rdi   # message address (or pointer) parameter in %rdi
    movq %rcx, %rsi               # n value parameter in %rsi
    call printf                   # call C function printf(format_output, n)

    # Initialize variables for Fibonacci sequence calculation
    movq $0, %rax        # rax will hold the current number
    movq $1, %rbx        # rbx will hold the next number

    # Loop to calculate and print Fibonacci numbers
fib_loop:
    pushq %rax           # save current number
    movq %rax, %rdi      # set 1st parameter (format_output)
    call printf           # call C function printf(format_output, current_number)
    popq %rax            # restore current number

    addq %rbx, %rax      # calculate next Fibonacci number
    movq %rbx, %rcx      # move next number to temp variable
    movq %rax, %rbx      # move current number to next number
    movq %rcx, %rax      # move temp variable to current number

    decq %rcx            # decrement n
    jnz fib_loop         # repeat until n reaches 0

    # Exit program
    movq $60, %rax       # syscall number for exit
    xorq %rdi, %rdi      # exit status 0
    syscall              # invoke syscall to exit

    call puts              # puts(message)
    # READ VALUE OF n FROM KEYBOARD AND STORE IT IN MEMORY LOCATION x
    pushq %rbp             # save base pointer
    movq $0, %rax          # clear rax for proper varargs setup
    movq $format, %rdi     # put scanf 1st parameter (format f) in %rdi
    movq $x, %rsi          # put scanf 2nd parameter (pointer to location x) in %rsi
    call scanf             # scanf(f, pointer x)
    popq %rbp              # restore base pointer

    # PRINT VALUE OF n in x on the screen
    movq x, %rax           # %rax ← n, i.e. Contents of memory location x
    pushq %rax             # save n (current_number)
    pushq %rcx             # save loop counter
    movq $format1, %rdi    # put printf 1st parameter (format1) in %rdi
    movq (%rax), %rsi      # put printf 2nd parameter (n) in %rsi, n is the value to be printed
    xorq %rax, %rax        # clear rax for proper varargs setup
    call printf            # printf(format1, n)
    popq %rcx              # restore loop counter
    popq %rax              # restore n (current_number)

    # COMPUTING FIBONACCI NUMBERS
    movq %rax, %rcx        # rcx will countdown to 0
    xorq %rax, %rax        # rax will hold the current number
    xorq %rbx, %rbx        # rbx will hold the next number
    incq %rbx              # rbx is originally 1

    # We need to call printf, but we are using rax, rbx, and rcx. Printf may
    # destroy rax and rcx so we will save these before the call and restore them
    # afterwards.
    print_loop:
        pushq %rax         # save current number
        pushq %rcx         # save loop counter
        movq $format, %rdi # put printf 1st parameter (format) in %rdi
        movq %rax, %rsi    # put printf 2nd parameter (current_number) in %rsi

