; Автор:
; Владимир: https://vk.com/yapoxe
%include "io.inc"

section .bss
    x resd 1
    y resd 1

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging

    GET_UDEC 4, eax
    mov [x], eax
    GET_UDEC 4, eax
    GET_UDEC 4, ebx
    sub eax, ebx
    mov [y], eax
    GET_UDEC 4, ebx
    sub ebx, 2011
    mov eax, [y]
    imul ebx, eax
    mov eax, [x]
    add eax, ebx
    
    PRINT_UDEC 4, eax
    
    xor eax, eax
    ret