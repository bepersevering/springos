# SpringOS Minimal - 保证可工作

CC = riscv64-unknown-elf-gcc
LD = riscv64-unknown-elf-ld
OBJCOPY = riscv64-unknown-elf-objcopy

CFLAGS = -Wall -O2 -ffreestanding -nostdlib -march=rv64gc -mabi=lp64
LDFLAGS = -nostdlib -T linker.ld

SRCS = src/start.S src/main.c
OBJS = $(SRCS:.c=.o)
OBJS := $(OBJS:.S=.o)

TARGET = kernel
ELF = $(TARGET).elf
BIN = $(TARGET).bin

all: $(BIN)

$(ELF): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $@

$(BIN): $(ELF)
	$(OBJCOPY) -O binary $< $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.S
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(ELF) $(BIN)

run: $(BIN)
	qemu-system-riscv64 -machine virt -nographic \
		-bios ../bootloader/rustsbi-qemu.bin \
		-device loader,file=$(BIN),addr=0x80200000

.PHONY: all clean run