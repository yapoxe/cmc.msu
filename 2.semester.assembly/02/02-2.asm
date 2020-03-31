;Автор:
;Владимир: https://vk.com/yapoxe
;Ограничение времени:	1 с
;Ограничение памяти:	64 M
;Максимальное количество посылок:	16
;На вход программе подается беззнаковое 32-битное целое число N. 
;Требуется найти количество единичных битов в двоичном представлении данного числа.

%include "io.inc"

section .data
    y dd 0

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    xor ebx, ebx
    GET_UDEC 4, eax
    mov ecx, 32
    z:
        shr eax, 1
        jc k
        jmp s
    k: 
        inc ebx
    s:
        loop z
    PRINT_UDEC 4, ebx
    xor eax, eax
    ret