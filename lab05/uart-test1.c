// ======================================================================

#include "frdm_k64f.h"		// include for FRDM-K64F board

// ======================================================================

int main(void)
{
  unsigned int x;
  char buf[512];

  soc_init();			// initialize FRDM-K64F board

  puts("============================================================\n");
  puts("If you type a character, it will be printed: ");
  gets(buf);
  putc((int) buf[0]);
  printf("\n");

  puts("If you type a hexa-decimal number, it will be printed: ");
  x = gethex();
  printf("%08x\n", x);

  puts("If you type a line of characters, it will be printed: ");
  gets(buf);
  printf("%s\n", buf);
  puts("============================================================\n");

  for (;;);			// waiting in an infinite loop

  return 0;
}

// ======================================================================
