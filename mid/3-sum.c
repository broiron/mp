// ======================================================================

#include "frdm_k64f.h"		// include for FRDM-K64F board

// ======================================================================

extern void sum_asm(unsigned int i, unsigned int j);

// ======================================================================

int main(int argc, char *argv[])
{
  soc_init();			// initialize FRDM-K64F board

  printf("===== 3-sum ======\n");
  sum_asm(10, 20);
  sum_asm(20, 30);
  sum_asm(30, 40);

  for (;;);			// waiting in an infinite loop

  return 0;
}

// ======================================================================
