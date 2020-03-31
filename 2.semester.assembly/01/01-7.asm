;Автор:
;Владимир: https://vk.com/yapoxe
;Ограничение времени:	1 с
;Ограничение памяти:	64 M
;Максимальное количество посылок:	16
;На вход программе подаются 4 беззнаковых 8-битных целых числа: a, b, c, d. 
;Требуется построить такое беззнаковое 32-битное число X, что его младшие 8 бит равны a, 
;следующие за ними 8 бит - числу b, следующие 8 бит - числу c, и, наконец, старшие 8 бит - числу d. 
;Программа должна выводить искомое число X.
;Запрещается использовать инструкции условной передачи данных и управления.

%include "io.inc"

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    
    xor eax, eax
    GET_UDEC 1, ebx
    or eax, ebx
    ror eax, 8
    GET_UDEC 1, ebx
    or eax, ebx
    ror eax, 8
    GET_UDEC 1, ebx
    or eax, ebx
    ror eax, 8
    GET_UDEC 1, ebx
    or eax, ebx
    xor ebx, ebx
    ror eax, 8
    
    PRINT_UDEC 4, eax
    
    xor eax, eax
    ret