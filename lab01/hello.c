// ======================================================================

#include "frdm_k64f.h"		// include for FRDM-K64F board

// ======================================================================

int main(void)
{
  soc_init();			// initialize FRDM-K64F board

  printf("============================================================\n");
  printf("Hello, FRDM-K64F Board!\n");
  printf("Welcome to Cortex-M4 Microprocessor\n");
  printf("============================================================\n");

  for (;;)			// waiting in an infinite loop
    ;

  return 0;
}

// ======================================================================
