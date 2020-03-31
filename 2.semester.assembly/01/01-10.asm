;Автор:
;Владимир: https://vk.com/yapoxe
%include "io.inc"

section .bss
    x resd 1
    s resd 1

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    GET_DEC 4, eax
    sub eax, 1
    mov [x], eax
    imul eax, 41
    mov [s], eax
    xor eax, eax
    mov eax, [x]
    xor edx, edx
    mov ebx, 2
    div ebx
    xor ebx, ebx
    mov ebx, [s]
    add ebx, eax
    xor eax, eax
    GET_DEC 4, eax
    add ebx, eax
    PRINT_DEC 4, ebx
    
    xor eax, eax
    ret