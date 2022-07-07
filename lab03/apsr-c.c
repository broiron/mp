// ======================================================================

#include "frdm_k64f.h"		// include for FRDM-K64F board

// ======================================================================

void apsr_print(unsigned int apsr)
{
  unsigned int x, N, Z, C, V, Q;
  unsigned int GE[4];
  int i;

  x = __get_APSR();
  N = (x>>31)&1;
  Z = (x>>30)&1;
  C = (x>>29)&1;
  V = (x>>28)&1;
  Q = (x>>27)&1;

  for (i=0; i<4; i++){
    GE[i]=(x>>(19-i)&1);
  }
  printf("N=%d, Z=%d, C=%d, V=%d, Q=%d, GE[3:0]=", N, Z, C, V, Q);
  for (i=0; i<4; i++){
    printf("%d", GE[i]);
  }
  printf("\n");
  __asm("mov      r2, %0": :"r"(apsr));
  __asm("msr      apsr_nzcvqg, r2");
  
}

// ======================================================================

int main(void)
{
  soc_init();			// initialize FRDM-K64F board

  printf("========================================\n");
  printf("setting APSR=0x00000000...\n");
  __asm("	ldr	r0, =#0x00000000");
  __asm("	msr	apsr_nzcvqg, r0");
  apsr_print(__get_APSR());	// print twice to check apsr is preserved
  apsr_print(__get_APSR());

  printf("========================================\n");
  printf("setting C=1 of APSR...\n");
  __asm("       ldr     r0, =#0xffffffff");
  __asm("       ldr     r1, =#0x00000011");
  __asm("       adds    r0, r0, r1");

  apsr_print(__get_APSR());	// print twice to check apsr is preserved
  apsr_print(__get_APSR());
  printf("========================================\n");

  for (;;)			// waiting in an infinite loop
    ;

  return 0;
}

// ======================================================================
