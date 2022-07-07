# ======================================================================

FRDM_K64F_DIR=/home/mp/frdm_k64f
CMSIS_DIR=/home/mp/cmsis

# ======================================================================

CROSS_COMPILE=arm-none-eabi-

AS=$(CROSS_COMPILE)as
CC=$(CROSS_COMPILE)gcc
LD=$(CROSS_COMPILE)ld
AR=$(CROSS_COMPILE)ar
OBJCOPY=$(CROSS_COMPILE)objcopy
OBJDUMP=$(CROSS_COMPILE)objdump

# ======================================================================

ASFLAGS=-g -mcpu=cortex-m4 -mthumb
CFLAGS=-g -O3 -Wall -mcpu=cortex-m4 -mthumb -fno-builtin -I$(FRDM_K64F_DIR) -I$(CMSIS_DIR)/CMSIS/Include -I$(CMSIS_DIR)/Device/ARM/ARMCM3/Include -I$(CMSIS_DIR)/Device/ARM/ARMCM4/Include
LDFLAGS=-T $(FRDM_K64F_DIR)/link.ld -L $(FRDM_K64F_DIR)

# ======================================================================

all:	systick


# ======================================================================

systick:
	export PROG="systick"; export OBJS="systick.o"; make one

# ======================================================================

one:	$(PROG).elf $(PROG).dis1 $(PROG).dis2 $(PROG).bin

$(PROG).elf:	$(OBJS)
	$(LD) $(LDFLAGS) $(FRDM_K64F_DIR)/crt0.o $(OBJS) -lfrdm_k64f -o $(PROG).elf

$(PROG).dis1 $(PROG).dis2:	$(PROG).elf
	$(OBJDUMP) -Dx $(PROG).elf > $(PROG).dis1
	$(OBJDUMP) -DSx $(PROG).elf > $(PROG).dis2

$(PROG).bin:	$(PROG).elf
	$(OBJCOPY) -O binary $(PROG).elf $(PROG).bin

# ======================================================================

send:	all
	kermit -s *.bin

# ======================================================================

cp:	all
	cp *.bin ~/win/Desktop/

# ======================================================================

indent:
	@indent -i2 -kr -nfca *.c
	@rm -f *.c~

# ======================================================================

clean:
	@rm -f *~ *.o *.elf *.dis1 *.dis2 *.bin

# ======================================================================
