// ======================================================================
// unsigned int multi_asm(unsigned int i, unsigned int j);

.globl multi_asm
multi_asm:
	push {r4, r5}
	mov r4, #1
	mov r5, r0

.L0:	add r4, r4, #1
	cmp r4, r1
	bgt .L1
	add r0, r0, r5
	b .L0

.L1:	pop {r4, r5}
	bx lr

// ======================================================================
