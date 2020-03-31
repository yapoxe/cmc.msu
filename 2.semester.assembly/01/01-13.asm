;Автор:
;Владимир: https://vk.com/yapoxe
%include "io.inc"

section .bss
    x resd 1
    y resd 1

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    
    GET_CHAR eax
    mov [x], eax
    GET_DEC 4, eax
    mov [y], eax
    
    GET_CHAR ebx
    xor ebx, ebx
    GET_CHAR ebx
    mov eax, [x]
    sub eax, ebx
    cdq
    xor eax, edx
    sub eax, edx
    
    mov [x], eax
    xor edx, edx
    
    GET_DEC 4, ebx
    mov eax, [y]
    sub eax, ebx
    cdq
    xor eax, edx
    sub eax, edx
    
    mov ebx, [x]
    add eax, ebx
    
    PRINT_DEC 4, eax
    
    xor eax, eax
    ret