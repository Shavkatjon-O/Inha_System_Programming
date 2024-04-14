# PART-A | QUESTION-8

# -----------------------------------------------------------------------------
# A 64-bit Linux application that writes the first n Fibonacci numbers. The input 
# value n is to be read from the keyboard. Functions called : puts, scanf, printf
# This routine needs to be linked with C library functions at runtime. To create object 
# file using GNU assembler as $as -gstabs fibio.s -o fibio.o. To create an executable
# file after linking $ld -dynamic-linker /lib64/ld-linux-x86-64.so.2 fibio.o -o fibio -lc
# To execute fibio $./fibio
#-----------------------------------------------------------------------------

.global _start

.data
message: .asciz "ENTER A VALUE FOR n :"
format: .asciz "%20ld\n"
format1: .asciz "THE LIST OF FIRST n=%8ld FIBONACCI NUMBERS\n"
f: .string "%d"
x: .quad 0

.text
_start:
    # To call C function puts(message pointer); first store message pointer in
    # register %rdi
    # message pointer → %rdi
    movq $message, %rdi

    # Call puts(message)
    call puts

    # READ VALUE OF n FROM KEYBOARD AND STORE IT IN MEMORY LOCATION x
    pushq %rbp
    movq $0, %rax
    movq $f, %rdi       # Put scanf 1st parameter (format f - see .data section) in %rdi
    movq $x, %rsi       # Put scanf 2nd parameter (pointer to location x - see .data section) in %rsi
    call scanf          # scanf(f, pointer x)
    popq %rbp

    # PRINT VALUE OF n in x on the screen
    movq x, %rax        # %rax ← n, i.e. Contents of memory location x
    pushq %rax          # Caller-save register
    pushq %rcx          # Caller-save register
    movq $format1, %rdi # Put printf 1st parameter (format1 - see .data section) in %rdi
    movq %rax, %rsi     # Put printf 2nd parameter (n) in %rsi, n is the value to be printed
    xorq %rax, %rax
    call printf         # printf(format1, current_number)
    popq %rcx           # Restore caller-save register
    popq %rax           # Restore caller-save register

    # COMPUTING FIBONACCI NUMBERS
    movq %rax, %rcx     # rcx will countdown to 0
    xorq %rax, %rax     # rax will hold the current number
    xorq %rbx, %rbx     # rbx will hold the next number
    incq %rbx           # rbx is originally 1

print:
    push %rax           # Caller-save register
    push %rcx           # Caller-save register
    movq $format, %rdi  # Put printf 1st parameter (format - see .data section) in %rdi
    movq %rax, %rsi     # Put printf 2nd parameter (current_number - currently generated Fibonacci number) in %rsi

    xorq %rax, %rax            # Reset rax to 0
    call printf                # Call printf(format, current_number)
    pop %rcx                   # Restore caller-save register
    pop %rax                   # Restore caller-save register
    movq %rax, %rdx            # Save the current number
    movq %rbx, %rax            # Set the next number as the current number
    addq %rdx, %rbx            # Calculate the new next number
    decq %rcx                  # Count down
    jnz print                  # If not done counting, jump to print
    movq $60, %rax             # Exit syscall number
    xorq %rdi, %rdi            # Set the exit status to 0
    syscall                    # Invoke syscall to exit
