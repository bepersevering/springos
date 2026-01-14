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
}




#endif
