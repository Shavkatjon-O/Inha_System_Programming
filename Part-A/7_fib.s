# -----------------------------------------------------------------------------
# A 64-bit Linux application that writes the first 90 Fibonacci numbers.
# It needs to be linked with a C library at runtime
# To create object file using GNU assembler as
#
# $as -gstabs fib.s -o fib.o
# To create an executable file after linking
# $ld -dynamic-linker /lib64/ld-linux-x86-64.so.2 fib.o -o fib -lc
# To execute fib
# $./fib
# -----------------------------------------------------------------------------

.global _start
.data
format: .asciz "%20ld\n"
.text
_start:
    movq $90, %rcx         # ecx will countdown to 0
    xorq %rax, %rax        # rax will hold the current number
    xorq %rbx, %rbx        # rbx will hold the next number
    incq %rbx              # rbx is originally 1

    # We need to call printf, but we are using rax, rbx, and rcx. Printf may
    # destroy rax and rcx so we will save these before the call and restore
    # them afterwards.
    
print_loop:
    pushq %rax             # save current number
    pushq %rcx             # save loop counter
    movq $format, %rdi     # set 1st parameter (format)
    movq %rax, %rsi        # set 2nd parameter (current_number)
    xorq %rax, %rax        # set 3rd parameter (0)
    call printf            # call printf(format, current_number, 0)
    popq %rcx              # restore loop counter
    popq %rax              # restore current number

    addq %rbx, %rax        # calculate next Fibonacci number
    movq %rbx, %rcx        # move next number to loop counter
    movq %rax, %rbx        # move current number to next number

    loop print_loop        # repeat until loop counter reaches 0

    # Exit program
    movq $60, %rax         # syscall number for exit
    xorq %rdi, %rdi        # exit status 0
    syscall                # invoke syscall to exit

    xorq %rax, %rax        # because printf is varargs

    # Stack is already aligned because we pushed three 8 byte registers

    call printf            # printf(format, current_number)
    popq %rcx              # restore caller-save register
    popq %rax              # restore caller-save register

    movq %rax, %rdx        # save the current number
    movq %rbx, %rax        # next number is now current
    addq %rdx, %rbx        # get the new next number
    decq %rcx              # count down
    jnz print_loop         # if not done counting, jump to print_loop

    # Exit program
    movq $60, %rax         # syscall number for exit
    xorq %rdi, %rdi        # exit status 0
    syscall                # invoke syscall to exit
