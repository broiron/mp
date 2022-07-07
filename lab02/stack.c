// ======================================================================

#include "frdm_k64f.h"		// include for FRDM-K64F board

// ======================================================================
// Addresses for start and end of sections in link.ld.

extern unsigned int __stack_start__;
extern unsigned int __stack_end__;

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

  // Stack section
  printf("============================================================\n");
  printf("Stack section: 0x%08x-0x%08x\n", &__stack_start__, &__stack_end__);
  

  fun1();
  fun3();

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
  printf("fun1: &x[0]=0x%08x, &x[1023]=0x%08x\n", &x[0], &x[1023]);
  

  fun2();

  return 0;
}

// ======================================================================
// Function fun2 is in text section.

int fun2(void)
{
  // Local variables are in stack section.
  int y[1024];

  printf("fun2: &y[0]=0x%08x, &y[1023]=0x%08x\n", &y[0], &y[1023]);

  return 0;
}

// ======================================================================
// Function fun3 is in text section.

int fun3(void)
{
  // Local variables are in stack section.
  int z[2048];

  printf("fun3: &z[0]=0x%08x, &z[2047]=0x%08x\n", &z[0], &z[2047]);

  return 0;
}

// ======================================================================
