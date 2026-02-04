/* 
 * SpringOS 链接脚本
 * RISC-V 64位
 */
OUTPUT_ARCH(riscv)
ENTRY(_start)

SECTIONS {
    /* 内核加载地址 */
    . = 0x80200000;
    
    /* 代码段 */
    .text : {
        *(.text.entry)    /* 启动代码 */
        *(.text .text.*)  /* 其他代码 */
    }
    
    /* 只读数据段 */
    .rodata : ALIGN(8) {
        *(.rodata .rodata.*)
    }
    
    /* 数据段 */
    .data : ALIGN(8) {
        *(.data .data.*)
    }
    
    /* BSS段起始 */
    . = ALIGN(8);
    _bss_start = .;
    
    /* BSS段（未初始化数据） */
    .bss : ALIGN(8) {
        *(.bss .bss.*)
        *(COMMON)
    }
    
    /* BSS段结束 */
    _bss_end = .;
    
    /* 内核栈空间 */
    . = ALIGN(16);
    _stack_bottom = .;
    . += 16K;  /* 16KB栈空间 */
    _stack_top = .;
    
    /* 结束符号 */
    _end = .;
}