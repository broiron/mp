// ======================================================================

#include "frdm_k64f.h"		// include for FRDM-K64F board

// ======================================================================

void pbit(char data)
{
  int i;
  char p;
  p = 0x80;
  for(i=0; i<8; i++){
    if(data&p){
      putc('1');
    }
    else{
      putc('0');
    }
    p=p>>1;
  }
  
  
}

// ======================================================================

int main(void)
{
  unsigned int i, start, end, step;

  soc_init();			// initialize FRDM-K64F board

  printf("===== 1-pbit ======\n");

  start = 0x80;
  end = start + 20;
  step = 2;
  for (i = start; i <= end; i = i + step) {
    printf("%d(10)=", i);
    pbit(i);
    printf("(2)\n");
  }

  for (;;)			// waiting in an infinite loop
    ;

  return 0;
}

// ======================================================================
