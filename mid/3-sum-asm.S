// ======================================================================
// void sum_asm(unsigned int i, unsigned int j);

.globl sum_asm
sum_asm:

push {lr}
push {r4, r5, r6}
mov r4, r0
mov r5, r1
add r6, r4, r5
ldr r0,=string
mov r1, r4
mov r2, r5
mov r3, r6
bl printf
pop {r4, r5, r6}
pop {pc}


string:
	.asciz "%d+%d=%d\n"


// ======================================================================
