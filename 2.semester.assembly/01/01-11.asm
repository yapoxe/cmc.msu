;Автор:
;Владимир: https://vk.com/yapoxe
%include "io.inc"

section .bss
    x resd 1

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    GET_CHAR eax
    mov ebx, 'H'
    sub ebx, eax
    mov [x], ebx
    GET_DEC 4, eax
    mov ebx, 8
    sub ebx, eax
    mov eax, [x]
    imul eax, ebx
    mov ebx, 2
    xor edx, edx
    div ebx
    PRINT_DEC 4, eax
    
    xor eax, eax
    ret