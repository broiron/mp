// ======================================================================

#include "frdm_k64f.h"		// include for FRDM-K64F board

// ======================================================================

void goto_and_puts(int x, int y, char *str);

// ======================================================================

int main(void)
{
  soc_init();			// initialize FRDM-K64F board

  putclear();
  puts("============================================================\n");

  goto_and_puts(5, 2, "Are you there!");
  goto_and_puts(10, 5, "I am here!");
  goto_and_puts(15, 8, "Please help me!");
  goto_and_puts(0, 11, "\n");

  puts("============================================================\n");

  for (;;);			// waiting in an infinite loop

  return 0;
}

// ======================================================================

void goto_and_puts(int x, int y, char *str)
{
  putgoto(x, y);
  printf("*(%d,%d) %s", x, y, str);
}

// ======================================================================
