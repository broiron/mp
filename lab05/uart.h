// ======================================================================

#ifndef _UART_H_
#define _UART_H_

// ======================================================================
// K64 Sub-Family Reference Manual, Document Number: K64P144M120SF5RM
// Rev. 2, Freescale Semiconductor, Inc., January 2014. (Chapter 52
// Universal Asynchronous Receiver/Transmitter)

typedef struct uart_struct {
  volatile unsigned char BDH;	/* Baud rate register high */
  volatile unsigned char BDL;	/* Baud rate register low */
  volatile unsigned char C1;	/* Control register 1 */
  volatile unsigned char C2;	/* Control register 2 */
  volatile const unsigned char S1;	/* Status register 1 */
  volatile unsigned char S2;	/* Status register 2 */
  volatile unsigned char C3;	/* Control register 3 */
  volatile unsigned char D;	/* Data register */
} UART;

#define TDRE		0x80u	// Transmit data register empty in S1
#define RDRF		0x20u	// Receive data register full in S1

// ======================================================================

int putc(int c);		// write a char to UART
int getc(void);			// read a char from UART
int getc_nb(void);		// read a char from UART (no blocking)

#endif

// ======================================================================
