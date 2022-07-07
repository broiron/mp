// ======================================================================

#ifndef _SYSTICK_H_
#define _SYSTICK_H_

// ======================================================================
// Cortex-M4 SysTick register address

#define SYST_CSR	0xe000e010
#define SYST_RVR	0xe000e014
#define SYST_CVR	0xe000e018
#define SYST_CALIB	0xe000e01c

// ======================================================================

void SysTick_init(void);
void SysTick_enable(void);
void SysTick_disable(void);

#endif

// ======================================================================
