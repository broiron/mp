// ======================================================================
// char memset_asm(char *start, char *end, char c);

.globl memset_asm //asm directive
memset_asm: 

.L0:	cmp r0, r1	 //compare start and end
	bgt .L1 	 //if r0>r1(start>end) goto .L1
	strb r2, [r0]	 //*start = c 
	add r0, r0, #1	 //start = start + 1
	b .L0	    	 //goto .L0 (repeat)

.L1:	mov r0, r2	 //return c
	bx lr


// ======================================================================
