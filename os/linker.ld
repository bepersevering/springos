OUTPUT_ARCH(riscv)
ENTRY(_start)

SECTIONS {
    /* qem vm loads kernel at 0x80200000 */
    . = 0x80200000;

    /* code section */
    .text: {
        *(.text.entry)
        *(.text .text.*)
    }

    /* data section */
    .data {
        *(.data .data.*)
    }

    /* bss section (uninitialized data) */
    .bss {
        *(.bss .bss.*)
        *(COMMON)
    }

    /* kernel stack (16KB) */
    . = ALIGN(16);
    .stack_bottom = .;
    . += 16K;
    .stack_top = .;

    /* discard unnecessary sections */
    /DISCARD/: {
        *(.comment)
        *(.note.*)
    }

}
