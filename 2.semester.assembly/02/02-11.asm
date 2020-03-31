;Автор:
;Владимир: https://vk.com/yapoxe
;Ограничение времени:	1 с
;Ограничение памяти:	64 M
;Максимальное количество посылок:	24
;В данной задаче вам необходимо найти наибольший общий делитель двух заданных натуральных чисел.
;На вход программе подаются два целых числа A и B (2 ? A, B ? 1000000000). 
;Программа должна вывести единственное целое число — ответ задачи.

%include "io.inc"
section .data
    a dd 0
    b dd 0
section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    GET_UDEC 4, eax
    mov [a], eax
    GET_UDEC 4, eax
    mov [b], eax
    mov ecx, 65535
    z:
        mov eax, [a]
        mov ebx, [b]
        cmp eax, 1
        jb c
        cmp ebx, 1
        jb c
        cmp eax, ebx
        ja k
        jna l
        loop z
    k:
        xor edx, edx
        div ebx
        mov [a], edx
        loop z
    l:
        mov eax, [b]
        mov ebx, [a]
        xor edx, edx
        div ebx
        mov [b], edx
        loop z
    c:  
        add eax, ebx
        PRINT_DEC 4, eax
        xor eax, eax
        ret
