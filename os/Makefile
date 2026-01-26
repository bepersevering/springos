#toolchain
CC = riscv64-unkonwn-elf-gcc
LD = riscv64=unkonwn-elf-ld

OBJCOPY = riscv64-unkonwn-elf-objcopy

#target
TARGET = kernel

#compiler flags
CFLAGS = -Wall -O2 -ffreestanding -nostdlib -mcmodel=medany -march=rv64gc -mabi=lp64

#linker flags
LDFLAGS = -nostdlib -T linker.ld -melf64lriscv

#source files
SRCS = src/start.S src/main.c
OBJS = $(SRCS:.c=.o)
OBJS := $(OBJS:.S=.o)

#default target
all: $(BIN)

# link kernel
$(ELF): $(OBJS)
