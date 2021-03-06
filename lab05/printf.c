// ======================================================================

#include "printf.h"

// ======================================================================

unsigned int gethex(void)
{
  int arr[10];
  int tmp=0;
  int j;
  int bit = 28;
  unsigned int result=0x00000000;

  for (j=0; j<9; j++){
    arr[j] = getc();
  }
  for (j=0; j<8; j++){
    if(arr[j] > 96){
      arr[j] = arr[j] - 87;
    }
    else arr[j] = arr[j] - 48;
    tmp = arr[j];
    tmp = (unsigned int) tmp;
    result = result + (tmp<<bit);
    bit= bit-4;   
  }
  return result;
}

// ======================================================================

char *gets(char *str)
{
  int index = 0;
  int data = 0;
  while(1){
    data = getc();
    if((data == '\r')|| (data == '\n')){
      str[index] = '\0';
      break;}
    str[index] = data;
    index++;
  }
  return str;
}

// ======================================================================

int puts(const char *s)
{
  int index = 0;
  while(1){
    if ((s[index] == '\0')){
      break;}
    else{
      putc(s[index]);
      index++;
    }
  }
  return 1;    
}

// ======================================================================

void putclear(void)
{
  printf("%c[2J", 27);
  printf("%c[H", 27);
}

// ======================================================================

void putgoto(int x, int y)
{
  printf("%c[%d;%df", 27, y+1, x);  
}

// ======================================================================

void putcolor(unsigned int color)
{
  puts("[");
  switch (color) {
  case ANSI_COLOR_BLACK:
    puts("30");
    break;
  case ANSI_COLOR_RED:
    puts("31");
    break;
  case ANSI_COLOR_GREEN:
    puts("32");
    break;
  case ANSI_COLOR_YELLOW:
    puts("33");
    break;
  case ANSI_COLOR_BLUE:
    puts("34");
    break;
  case ANSI_COLOR_MAGENTA:
    puts("35");
    break;
  case ANSI_COLOR_CYAN:
    puts("36");
    break;
  case ANSI_COLOR_WHITE:
    puts("37");
    break;
  default:
    puts("30");
    break;
  }
  putc('m');
}

// ======================================================================

void printchar(char **str, int c)
{
  if (str) {
    **str = c;
    ++(*str);
  } else
    (void) putc(c);
}

// ======================================================================

int prints(char **out, const char *string, int width, int pad)
{
  register int pc = 0, padchar = ' ';

  if (width > 0) {
    register int len = 0;
    register const char *ptr;
    for (ptr = string; *ptr; ++ptr)
      ++len;
    if (len >= width)
      width = 0;
    else
      width -= len;
    if (pad & PAD_ZERO)
      padchar = '0';
  }
  if (!(pad & PAD_RIGHT)) {
    for (; width > 0; --width) {
      printchar(out, padchar);
      ++pc;
    }
  }
  for (; *string; ++string) {
    printchar(out, *string);
    ++pc;
  }
  for (; width > 0; --width) {
    printchar(out, padchar);
    ++pc;
  }

  return pc;
}

// ======================================================================

int printi(char **out, int i, int b, int sg, int width, int pad,
	   int letbase)
{
  char print_buf[PRINT_BUF_LEN];
  register char *s;
  register int t, neg = 0, pc = 0;
  register unsigned int u = i;

  if (i == 0) {
    print_buf[0] = '0';
    print_buf[1] = '\0';
    return prints(out, print_buf, width, pad);
  }

  if (sg && b == 10 && i < 0) {
    neg = 1;
    u = -i;
  }

  s = print_buf + PRINT_BUF_LEN - 1;
  *s = '\0';

  while (u) {
    t = u % b;
    if (t >= 10)
      t += letbase - '0' - 10;
    *--s = t + '0';
    u /= b;
  }

  if (neg) {
    if (width && (pad & PAD_ZERO)) {
      printchar(out, '-');
      ++pc;
      --width;
    } else {
      *--s = '-';
    }
  }

  return pc + prints(out, s, width, pad);
}

// ======================================================================

int print(char **out, int *varg)
{
  register int width, pad;
  register int pc = 0;
  register char *format = (char *) (*varg++);
  char scr[2];

  for (; *format != 0; ++format) {
    if (*format == '%') {
      ++format;
      width = pad = 0;
      if (*format == '\0')
	break;
      if (*format == '%')
	goto out;
      if (*format == '-') {
	++format;
	pad = PAD_RIGHT;
      }
      while (*format == '0') {
	++format;
	pad |= PAD_ZERO;
      }
      for (; *format >= '0' && *format <= '9'; ++format) {
	width *= 10;
	width += *format - '0';
      }
      if (*format == 's') {
	register char *s = *((char **) varg++);
	pc += prints(out, s ? s : "(null)", width, pad);
	continue;
      }
      if (*format == 'd') {
	pc += printi(out, *varg++, 10, 1, width, pad, 'a');
	continue;
      }
      if (*format == 'x') {
	pc += printi(out, *varg++, 16, 0, width, pad, 'a');
	continue;
      }
      if (*format == 'X') {
	pc += printi(out, *varg++, 16, 0, width, pad, 'A');
	continue;
      }
      if (*format == 'u') {
	pc += printi(out, *varg++, 10, 0, width, pad, 'a');
	continue;
      }
      if (*format == 'c') {
	/* char are converted to int then pushed on the stack */
	scr[0] = *varg++;
	scr[1] = '\0';
	pc += prints(out, scr, width, pad);
	continue;
      }
    } else {
    out:
      printchar(out, *format);
      ++pc;
    }
  }
  if (out)
    **out = '\0';
  return pc;
}

// ======================================================================

int sprintf(char *out, const char *format, ...)
{
  register int *varg = (int *) (&format);
  return print(&out, varg);
}

// ======================================================================

int printf(const char *format, ...)
{
  char line[MAX_UART_LINE];
  char *out = line;

  register int *varg = (int *) (&format);
  print(&out, varg);
  return puts(line);
}

// ======================================================================
