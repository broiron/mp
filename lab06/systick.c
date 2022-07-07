// ======================================================================

#include "frdm_k64f.h"		// include for FRDM-K64F board
#include "systick.h"

// ======================================================================

unsigned int tick = 0;

// ======================================================================

int main(void)
{
  char input[80];

  soc_init();			// initialize FRDM-K64F board

  for (;;) {
    printf("========================================\n");
    printf("SysTick exception\n");
    printf("========================================\n");
    printf("1. Init 1,000Hz SysTick timer\n");
    printf("2. Enable SysTick timer\n");
    printf("3. Disable SysTick timer\n");
    printf("4. Print the current tick\n\n");
    printf("Select one: ");

    gets(input);
    printf("\n");
    if ((input[0] == '1') && (input[1] == '\0')) {
      tick = 0;
      printf("tick=%d\n", tick);
      SysTick_init();
    } else if ((input[0] == '2') && (input[1] == '\0')) {
      SysTick_enable();
      printf("tick=%d\n", tick);
    } else if ((input[0] == '3') && (input[1] == '\0')) {
      SysTick_disable();
      printf("tick=%d\n", tick);
    } else if ((input[0] == '4') && (input[1] == '\0')) {
      printf("tick=%d\n", tick);
    } else {
      printf("tick=%d\n", tick);
    }
    printf("\n");
  }

  return 0;
}

// ======================================================================

void SysTick_init(void)
{
  *(volatile unsigned int *) SYST_RVR = 0x0001d4bf;
  *(volatile unsigned int *) SYST_CVR = 0x00000000;
  *(volatile unsigned int *) SYST_CSR = 0x00000004;
}

// ======================================================================

void SysTick_enable(void)
{
  *(volatile unsigned int *) SYST_CSR = 0x00000007;
}

// ======================================================================

void SysTick_disable(void)
{
  *(volatile unsigned int *) SYST_CSR = 0x00000004;
}

// ======================================================================

void SysTick_Handler(void)
{
  tick = tick + 1;
}

// ======================================================================
