// ======================================================================

#ifndef _PRINTF_H_
#define _PRINTF_H_

// ======================================================================

#define PAD_RIGHT	1
#define PAD_ZERO	2
#define PRINT_BUF_LEN	12
#define MAX_UART_LINE	256

// ======================================================================

#define	ANSI_COLOR_BLACK	30
#define	ANSI_COLOR_RED		31
#define	ANSI_COLOR_GREEN	32
#define	ANSI_COLOR_YELLOW	33
#define	ANSI_COLOR_BLUE		34
#define	ANSI_COLOR_MAGENTA	35
#define	ANSI_COLOR_CYAN		36
#define	ANSI_COLOR_WHITE	37

// ======================================================================

extern int putc(int c);		// write a char to UART
extern int getc(void);		// read a char from UART
extern int getc_nb(void);	// read a char from UART (no bloking)

// ======================================================================

unsigned int gethex(void);	// read a 8-chars hexadecimal number
char *gets(char *str);		// read a line
int puts(const char *s);	// write a string to UART
void putclear(void);		// write VT100 clear screen string to UART
void putgoto(int x, int y);	// write a string to go to VT100 screen at (x,y)
void putcolor(unsigned int color);	// change text color
int sprintf(char *out, const char *format, ...);	// sprintf()
int printf(const char *format, ...);	// printf()

#endif

// ======================================================================
