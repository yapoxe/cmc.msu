;Автор:
;Владимир: https://vk.com/yapoxe
%include "io.inc"

section .bss
    a11 resd 1
    a12 resd 1
    a21 resd 1
    a22 resd 1
    b1 resd 1
    b2 resd 1
    a1 resd 1
    a2 resd 1
    b resd 1
    am resd 1
    bm resd 1

section .text
global CMAIN
CMAIN:
    GET_UDEC 4, eax
    mov [a11], eax
    GET_UDEC 4, eax
    mov [a12], eax
    GET_UDEC 4, eax
    mov [a21], eax
    GET_UDEC 4, eax
    mov [a22], eax
    GET_UDEC 4, eax
    mov [b1], eax
    GET_UDEC 4, ebx
    mov [b2], ebx
    or eax, ebx
    mov [b], eax
    
    mov eax, [a11]
    mov ebx, [a21]
    or eax, ebx
    mov [a1], eax
    
    mov eax, [a12]
    mov ebx, [a22]
    or eax, ebx
    mov [a2], eax
    
    mov eax, [a11]
    mov ebx, [a22]
    and eax, ebx
    mov [am], eax
    
    mov eax, [a12]
    mov ebx, [a21]
    and eax, ebx
    mov ebx, [am]
    xor ebx, eax
    xor ebx, -1
    mov [am], ebx
    
    
    mov eax, [b1]
    mov ebx, [a22]
    and eax, ebx
    mov [bm], eax
    
    mov eax, [a12]
    mov ebx, [b2]
    and eax, ebx
    mov ebx, [bm]
    xor ebx, eax
    mov [bm], ebx

    mov eax, [a1]
    mov ebx, [b]
    and eax, ebx
    mov ebx, [am]
    and eax, ebx
    mov ebx, [bm]
    xor eax, ebx
    PRINT_UDEC 4, eax
    PRINT_CHAR " "
    
    
    mov eax, [a11]
    mov ebx, [b2]
    and eax, ebx
    mov [bm], eax
    
    mov eax, [b1]
    mov ebx, [a21]
    and eax, ebx
    mov ebx, [bm]
    xor ebx, eax
    mov [bm], ebx

    mov eax, [a1]
    not eax
    mov ebx, [a2]
    and eax, ebx
    mov ebx, [b]
    and eax, ebx
    mov ebx, [am]
    and eax, ebx
    mov ebx, [bm]
    xor eax, ebx
    PRINT_UDEC 4, eax

    
    xor eax, eax

    ret