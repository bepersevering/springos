#ifndef __SIB_H__
#define __SIB_H__

#include "types.h"

// SBI 扩展ID
#define SBI_EXT_0_1_CONSOLE_PUTCHAR 0x1
#define SBI_EXT_BASE 0x10

// SBI 函数ID
#define SBI_CONSOLE_PUTCHAR 0
#define SBI_CONSOLE_GETCHAR 1

struct sbiret {
    long error;
    long value;
};


// SBI 调用封装
static inline struct sbiret sbi_ecall(int ext, int fid, uint64_t arg0, 
                                      uint64_t arg1, uint64_t arg2,
                                      uint64_t arg3, uint64_t arg4,
                                      uint64_t arg5) {
    struct sbiret ret;
    register uint64_t a0 asm ("a0") = (uint64_t)(arg0);
    register uint64_t a1 asm ("a1") = (uint64_t)(arg1);
    register uint64_t a2 asm ("a2") = (uint64_t)(arg2);
    register uint64_t a3 asm ("a3") = (uint64_t)(arg3);
    register uint64_t a4 asm ("a4") = (uint64_t)(arg4);
    register uint64_t a5 asm ("a5") = (uint64_t)(arg5);
    register uint64_t a6 asm ("a6") = (uint64_t)(fid);
    register uint64_t a7 asm ("a7") = (uint64_t)(ext);

    asm volatile("ecall"
                : "=r" (a0), "=r" (a1)
                : "r" (a0), "r" (a1), "r" (a2), "r" (a3),
                 "r" (a4), "r" (a5), "r" (a6), "r" (a7)
                : "memory");
    ret.error = a0;
    ret.value = a1;
    return ret;
}


// SBI 控制台输出字符
static inline void sbi_console_putchar(int ch) {
    sbi_ecall(SBI_EXT_0_1_CONSOLE_PUTCHAR, SBI_CONSOLE_PUTCHAR, ch, 0, 0, 0, 0, 0);
}





#endif
