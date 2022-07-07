// ======================================================================

#include "frdm_k64f.h"		// include for FRDM-K64F board

// ======================================================================

#define	MEM_SIZE	10

char mem[MEM_SIZE] = { 0, };

// ======================================================================

extern char memset_asm(char *start, char *end, char c);

// ======================================================================

void print_mem(void)
{
  int i;

  printf("mem[%d]=", MEM_SIZE);
  for (i = 0; i < MEM_SIZE; i++)
    printf("%d%s", mem[i], ((i % 10) == 9 ? "\n" : " "));
}

// ======================================================================

int main(int argc, char *argv[])
{
  char c;

  soc_init();			// initialize FRDM-K64F board

  printf("============================================================\n");
  printf("memset_asm(&mem[0], &mem[MEM_SIZE - 1], 11)\n");
  printf("============================================================\n");
  c = memset_asm(&mem[0], &mem[MEM_SIZE - 1], 11);
  printf("return=%d\n", c);
  print_mem();
  printf("============================================================\n");
  printf("memset_asm(&mem[0], &mem[MEM_SIZE - 1], 22)\n");
  printf("============================================================\n");
  c = memset_asm(&mem[0], &mem[MEM_SIZE - 1], 22);
  printf("return=%d\n", c);
  print_mem();
  printf("============================================================\n");
  printf("memset_asm(&mem[0], &mem[MEM_SIZE - 1], 33)\n");
  printf("============================================================\n");
  c = memset_asm(&mem[0], &mem[MEM_SIZE - 1], 33);
  printf("return=%d\n", c);
  print_mem();
  printf("============================================================\n");

  for (;;);			// waiting in an infinite loop

  return 0;
}

// ======================================================================
