.section .text.entry
.global _start
_start:
    la sp, _stack_top

    call main

halt_loop:
    wfi
    j halt_loop
