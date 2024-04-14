# -----------------------------------------------------------------------------
# A 64-bit Linux application that reads two long integers x & y from the
# keyboard, performs long integer addition x+y, subtraction x-y, multiplication 
# x*y, division x/y and prints the results. The inputs x & y are to be read from 
# the keyboard. C Functions called : scanf, printf. This routine needs to be 
# linked with C library functions at runtime. To create object file using GNU assembler 
# as $as -gstabs arithxy.s -o arithxy.o To create an executable file after linking
# $ld -dynamic-linker /lib64/ld-linux-x86-64.so.2 arithxy.o -o arithxy -lc Execute the 
# code arithxy generated using the following command : $ ./arithxy
# -----------------------------------------------------------------------------

.global _start

# Data Declaration Section
.data
x:
    .space 8,0
y:
    .space 8,0
f:
    .asciz "%ld"
format:
    .asciz "%ld\n"
message1:
    .asciz "ENTER A LONG INTEGER x="
message2:
    .asciz "ENTER A LONG INTEGER y="
message3:
    .asciz "ENTERED VALUE OF x="
message4:
    .asciz "ENTERED VALUE OF y="
message5:
    .asciz "SUM = x + y ="
message6:
    .asciz "DIFFERENCE = x - y ="
message7:
    .asciz "PRODUCT = x * y ="
message8:
    .asciz "QUOTIENT = x / y ="
message9:
    .asciz "REMINDER = x % y ="

# Program Text (code) section
.text
_start:
    # Display message to prompt user to enter long integer value of x
    movq $1, %rax
    movq $1, %rdi
    movq $message1, %rsi
    movq $23, %rdx
    syscall

    # Read long integer value of x from the keyboard using C scanf function
    # Parameters passed - scanf format f in %rdi and address of x in %rsi
    movq $0, %rax   # clear rax
    movq $f, %rdi   # load format string
    movq $x, %rsi   # set storage to address of x
    call scanf

    # Display message about value of x entered
    movq $1, %rax
    movq $1, %rdi
    movq $message3, %rsi
    movq $19, %rdx
    syscall

    # Display the long integer value of x entered using C printf function
    # Parameters passed – printf format in %rdi and x value in %rsi
    movq $x, %rsi
    movq (%rsi), %rax
    pushq %rax
    pushq %rcx
    movq $format, %rdi
    movq %rax, %rsi
    xorq %rax, %rax
    call printf
    popq %rcx
    popq %rax

    # Display message to prompt user to enter long integer value of y
    movq $1, %rax
    movq $1, %rdi
    movq $message2, %rsi
    movq $23, %rdx
    syscall

    # Read long integer value of y from the keyboard using C scanf function
    # Parameters passed - scanf format f in %rdi and address of y in %rsi
    movq $0, %rax   # clear rax
    movq $f, %rdi   # load format string
    movq $y, %rsi   # set storage to address of y
    call scanf

    # Display message about value of y entered
    movq $1, %rax
    movq $1, %rdi
    movq $message4, %rsi
    movq $19, %rdx
    syscall

    # Display the long integer value of y entered using C printf function
    # Parameters passed – printf format in %rdi and x value in %rsi
    movq $y, %rsi
    movq (%rsi), %rax
    pushq %rax
    pushq %rcx
    movq $format, %rdi
    movq %rax, %rsi
    xorq %rax, %rax
    call printf
    popq %rcx
    popq %rax

    # Display message about computation x + y
    movq $1, %rax
    movq $1, %rdi
    movq $message5, %rsi
    movq $13, %rdx
    syscall

    # Perform addition x + y and display the result using printf
    movq $x, %rcx
    movq $y, %rdx
    movq (%rcx), %rax
    movq (%rdx), %rbx
    addq %rbx, %rax
    pushq %rax
    pushq %rcx
    movq $format, %rdi
    movq %rax, %rsi
    xorq %rax, %rax
    call printf
    popq %rcx
    popq %rax

    # Display message about computation x - y
    movq $1, %rax
    movq $1, %rdi
    movq $message6, %rsi
    movq $20, %rdx
    syscall

    # Perform subtraction x - y and display the result using printf
    movq $x, %rcx
    movq $y, %rdx
    movq (%rcx), %rax
    movq (%rdx), %rbx
    subq %rbx, %rax
    pushq %rax
    pushq %rcx
    movq $format, %rdi
    movq %rax, %rsi
    xorq %rax, %rax
    call printf
    popq %rcx
    popq %rax

    # Display message about computation x * y
    movq $1, %rax
    movq $1, %rdi
    movq $message7, %rsi
    movq $17, %rdx
    syscall

    # Perform multiplication x * y and display the product using printf
    movq $x, %rcx
    movq $y, %rdx
    movq (%rcx), %rax
    movq (%rdx), %rbx
    imulq %rbx
    pushq %rax
    pushq %rcx
    movq $format, %rdi
    movq %rax, %rsi
    xorq %rax, %rax
    call printf
    popq %rcx
    popq %rax

    # Display message about computation x / y to obtain Quotient
    movq $1, %rax
    movq $1, %rdi
    movq $message8, %rsi
    movq $18, %rdx
    syscall

    # Perform division x / y and display the quotient in %rax using printf
    movq $x, %rcx
    movq $y, %rdx
    movq (%rdx), %rbx
    movq (%rcx), %rax
    cqo
    # Sign extending dividend 64-bit in %rax into %rdx
    idivq %rbx
    pushq %rax
    pushq %rcx
    movq $format, %rdi
    movq %rax, %rsi
    xorq %rax, %rax
    call printf
    popq %rcx
    popq %rax

    # Display message about computation x % y to obtain Remainder
    movq $1, %rax
    movq $1, %rdi
    movq $message9, %rsi
    movq $18, %rdx
    syscall

    # Perform division x % y and display the remainder in %rdx using printf
    movq $x, %rcx
    movq $y, %rdx
    movq (%rdx), %rbx
    movq (%rcx), %rax
    cqo
    # Sign extending dividend 64-bit in %rax into %rdx
    idivq %rbx
    movq %rdx, %rax # remainder in %rdx
    pushq %rax
    pushq %rcx
    movq $format, %rdi
    movq %rax, %rsi
    xorq %rax, %rax
    call printf
    popq %rcx
    popq %rax
    
    # System exit
    movq $60, %rax
    xorq %rdi, %rdi
    syscall