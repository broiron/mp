// ======================================================================

#include "uart.h"

// ======================================================================

volatile UART *UART0 = (UART *) 0x4006a000;	// UART0 of K64F

// ======================================================================

int putc(int c)
{
  if ((c == '\n') || (c == '\r')) {

    // Read UART0_S1 and check TDRE bit.

    while ((UART0->S1 & TDRE) == 0);

    // Write a character to UART0_D.

    UART0->D = '\n';

    // Read UART0_S1 and check TDRE bit.

    while ((UART0->S1 & TDRE) == 0);

    // Write a character to UART0_D.

    UART0->D = '\r';

  } else {

    // Read UART0_S1 and check TDRE bit.

    while ((UART0->S1 & TDRE) == 0);

    // Write a character to UART0_D.

    UART0->D = (unsigned char) c;

  }

  return c;
}

// ======================================================================

int getc(void)
{
  unsigned int c;

  // Read UART0_S1 and check RDRF bit.

  while ((UART0->S1 & RDRF) == 0);

  // Read a character from UART0_D.

  c = UART0->D;

  // Echo back the character.

  putc(c);

  return (int) c;
}

// ======================================================================

#define EOF	(-1)

int getc_nb(void)
{
  unsigned int c;
  if ((UART0->S1 & RDRF)==0)
    return EOF;
  else
    c = UART0->D;
  return (int) c;
}

// ======================================================================
