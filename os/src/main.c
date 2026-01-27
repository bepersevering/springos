#define SBI_CONSOLE_PUTCHAR 1

/* simple sbi call */
static inline void sbi_console_putchar(int ch) {
    register long a0 asm("a0") = ch;
    register long a6 asm("a6") = 0;
    register long a7 asm("a7") = 1;

    asm volatile("ecall"
                : /* no outupt */
                : "r"(a0), "r"(a6), "r"(a7)
                : "memory");
}

/* print a string */
void print_str(const char *str) {
    while(*str) {
        sbi_console_putchar(*str++);
    }
}

int main() {
    print_str("Hello, World!\n");

    /* hang forever */
    while(1) {
        asm volatile("wfi");
    }

    return 0;
}
