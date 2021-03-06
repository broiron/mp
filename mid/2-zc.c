// ======================================================================

#include "frdm_k64f.h"		// include for FRDM-K64F board

// ======================================================================

void apsr_print(unsigned int apsr)
{
  unsigned int x, p, tmp;
  unsigned int GE[4];
  int i;
  char name[5];
  name[0] = 'N';
  name[1] = 'Z';
  name[2] = 'C';
  name[3] = 'V';
  name[4] = 'Q';

  x = __get_APSR();
  p = 0x80000000;
  for (i=0; i<4; i++){
    GE[i]=(x>>(19-i)&1);
  }
  for(i=0; i<5; i++){
    tmp = (x&p)?1:0;
    printf("%c=%d, ", name[i], tmp);
    p = p>>1;
  }
  printf("GE[3:0]=");
  for(i=0; i<4; i++){
    printf("%d", GE[i]);
  }
  printf("\n");
  __asm("mov      r2, %0": :"r"(apsr));
  __asm("msr      apsr_nzcvqg, r2");
  
  
}

// ======================================================================

int main(void)
{
  soc_init();			// initialize FRDM-K64F board

  printf("===== 2-zc ======\n");

  printf("setting APSR=0xffffffff...\n");
  __asm("	ldr	r0, =#0xffffffff");
  __asm("	msr	apsr_nzcvqg, r0");
  apsr_print(__get_APSR());	// print twice to check apsr is preserved
  apsr_print(__get_APSR());

  printf("setting APSR=0x00000000...\n");
  __asm("	ldr	r0, =#0x00000000");
  __asm("	msr	apsr_nzcvqg, r0");
  apsr_print(__get_APSR());	// print twice to check apsr is preserved
  apsr_print(__get_APSR());

  printf("setting Z=1 and C=1 of APSR...\n");

  __asm("       ldr     r0, =#0xffffffff");
  __asm("       adds    r0, r0, #1");
    
  apsr_print(__get_APSR());	// print twice to check apsr is preserved
  apsr_print(__get_APSR());

  for (;;)			// waiting in an infinite loop
    ;

  return 0;
}

// ======================================================================
