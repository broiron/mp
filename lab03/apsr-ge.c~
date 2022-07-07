// ======================================================================

#include "frdm_k64f.h"		// include for FRDM-K64F board

// ======================================================================

void apsr_print(unsigned int apsr)
{
  ...
}

// ======================================================================

int main(void)
{
  soc_init();			// initialize FRDM-K64F board

  printf("========================================\n");
  printf("setting APSR=0x00000000...\n");
  __asm("	ldr	r0, =#0x00000000");
  __asm("	msr	apsr_nzcvqg, r0");
  apsr_print(__get_APSR());	// print twice to check apsr is preserved
  apsr_print(__get_APSR());

  printf("========================================\n");
  printf("setting GE[3:0]=0101 of APSR...\n");
  ...

  apsr_print(__get_APSR());	// print twice to check apsr is preserved
  apsr_print(__get_APSR());
  printf("========================================\n");

  for (;;)			// waiting in an infinite loop
    ;

  return 0;
}

// ======================================================================
