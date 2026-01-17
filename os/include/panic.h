#ifndef __PANIC_H__
#define __PANIC_H__

#include "types.h"

// 内核panic处理
__attribute__((noreturn)) void panic(const char* msg);



#endif
