// ======================================================================
// void fact_asm(unsigned int from, unsigned int to);

.globl fact_asm
fact_asm:
	push {lr}
	push {r4, r5, r6}
	mov r4, r0    // r4 for store result
	mov r5, r0    // r5 for caculate

.L0:	
	sub r5, #1    // r5 -1 == r0 -1
	mov r6, #1    // r6 == 1
	cmp r6, r5    // if r6(1) > r5
	bgt .L1	      // goto print
	mul r4, r4, r5 // r4 = r4*r5
	b .L0
	
.L1:    // r4 = result, r5 = 0, r6 = 1
	mov r5, r0	// r5 = r0
	mov r6, r1	// r6 = r1
	ldr r0, =string	// r0 = string
	mov r1, r5	// r1 = from
	mov r2, r4	// r2 = r4(result)
	bl printf	// printf("fact(r1)=r4")
	mov r0, r5	// get  r0
	mov r1, r6	// get  r1
	b .L2		//L2

.L2:
	add r0, r0, #1	// from = from + 1
	mov r4, r0  	// r4 for store result
	mov r5, r0	// r5 for caculate
	cmp r1, r0  	// if r1>=r0
	bge .L0		// goto L0
	b .L3		// else goto L3

.L3:    pop {r4, r5, r6}// pop registers
        pop {pc}     	// return
	
string:
	.asciz "fact(%d)=%d\n"
// ======================================================================
