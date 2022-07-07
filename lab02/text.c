// ======================================================================

#include "frdm_k64f.h"		// include for FRDM-K64F board

// ======================================================================
// Addresses for start and end of sections in link.ld.

extern unsigned int __text_start__;
extern unsigned int __text_end__;

// ======================================================================
// String constants are in rodata section.

char *hello = "Hello!";
char *bye = "Bye!";

// ======================================================================
// Initialized global variables are data section.

unsigned int i = 0x12345678;
unsigned int j = 0x90abcdef;
unsigned int k = 0x12345678;
unsigned int l = 0x90abcdef;

// ======================================================================
// Uninitialized global variables are bss section.

unsigned int array[1024] = { 0. };

// ======================================================================

int fun1(void);			// main calls fun1
int fun2(void);			// fun1 calls fun2
int fun3(void);			// main calls fun3

// ======================================================================
// Function main is in text section.

int main(int argc, char *argv[])
{
  soc_init();			// initialize FRDM-K64F board

  unsigned int *mainadd, *fun1add, *fun3add;
  
  // Text section
  printf("============================================================\n");
  printf("Text section: 0x%08x-0x%08x\n", &__text_start__, &__text_end__);
  mainadd = main;
  printf("main=0x%08x\n", mainadd);
  fun1();
  fun3();
  fun1add = fun1;
  fun3add = fun3;
  printf("fun1=0x%08x\n", fun1add);
  printf("fun3=0x%08x\n", fun3add);
  
  printf("============================================================\n");

  for (;;);			// waiting in an infinite loop

  return 0;
}

// ======================================================================
// Function fun1 is in text section.

int fun1(void)
{
  // Local variables are in stack section.
  int x[1024];

  x[0] = x[1] = 0;

  fun2();

  return 0;
}

// ======================================================================
// Function fun2 is in text section.

int fun2(void)
{
  // Local variables are in stack section.
  int y[1024];

  y[0] = y[1] = 0;

  return 0;
}

// ======================================================================
// Function fun3 is in text section.

int fun3(void)
{
  // Local variables are in stack section.
  int z[2048];

  z[0] = z[1] = 0;

  return 0;
}

// ======================================================================
