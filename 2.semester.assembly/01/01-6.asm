;Автор:
;Владимир: https://vk.com/yapoxe
;Ограничение времени:	1 с
;Ограничение памяти:	64 M
;Максимальное количество посылок:	16
;На вход программе подается беззнаковое 32-битное целое число N и натуральное число K (1 ? K ? 31). 
;Требуется взять K младших битов числа N и вывести полученное таким образом число.
;Запрещается использовать инструкции условной передачи данных и управления.

%include "io.inc"

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    GET_UDEC 4, eax
    GET_UDEC 4, ebx
    mov ecx, 32
    sub ecx, ebx
    shl eax, cl
    shr eax, cl
    PRINT_UDEC 4, eax
    xor eax, eax
    ret