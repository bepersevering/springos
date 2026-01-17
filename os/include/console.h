#ifndef __CONSOLE_H__
#define __CONSOLE_H__


#include "types.h"

// 初始化控制台
void console_init();
// 输出一个字符
void console_putchar(char ch);
// 输出字符串
void console_putstr(const char* str);
// 格式化输出
int printf(const char* format, ...);



#endif
