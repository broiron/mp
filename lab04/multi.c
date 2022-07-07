// ======================================================================

#include "frdm_k64f.h"		// include for FRDM-K64F board

// ======================================================================

extern unsigned int multi_asm(unsigned int i, unsigned int j);

// ======================================================================

int main(int argc, char *argv[])
{
  int i, j, m;

  soc_init();			// initialize FRDM-K64F board

  printf("============================================================\n");
  printf("Multiplication table\n");
  printf("============================================================\n");
  for (i = 2; i <= 9; i++) {
    for (j = 2; j <= 9; j++) {
      m = multi_asm(i, j);
      printf("%d*%d=%-2d ", i, j, m);
    }
    printf("\n");
  }
  printf("============================================================\n");

  for (;;);			// waiting in an infinite loop

  return 0;
}

// ======================================================================
