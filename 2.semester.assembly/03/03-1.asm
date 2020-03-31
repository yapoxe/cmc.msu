;Автор:
;Владимир: https://vk.com/yapoxe
;Ограничение времени:	1 с
;Ограничение памяти:	64 M
;Максимальное количество посылок:	16
;На стандартном потоке ввода задаётся последовательность беззнаковых целых 32х-битных чисел в десятичной записи, 
;разделённых пробельными символами. 
;Требуется вывести ту же самую последовательность, но каждое число должно быть выведено через printf в формате "0x%08X\n"
;Запрещается использовать макросы ввода-вывода библиотеки io.inc. 
;При вызове всех библиотечных функций стек должен быть выровнен по 16 байт.

%include "io.inc"
section .data
    a dd 0
    b dd 0
    v dd 0
    d dd 0
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
        mov [v], eax
    GET_UDEC 4, eax
    mov [a], eax
    GET_UDEC 4, eax
    mov [b], eax
    mov ecx, 65535
    .z:
        mov eax, [a]
        mov ebx, [b]
        cmp eax, 1
        jb .c
        cmp ebx, 1
        jb .c
        cmp eax, ebx
        ja .k
        jna .l
        loop .z
    .k:
        xor edx, edx
        div ebx
        mov [a], edx
        loop .z
    .l:
        mov eax, [b]
        mov ebx, [a]
        xor edx, edx
        div ebx
        mov [b], edx
        loop .z
    .c:  
        add eax, ebx
        mov [d], eax
        
    mov eax, [v]
    mov [a], eax
    mov eax, [d]
    mov [b], eax
    mov ecx, 65535
    .i:
        mov eax, [a]
        mov ebx, [b]
        cmp eax, 1
        jb .h
        cmp ebx, 1
        jb .h
        cmp eax, ebx
        ja .r
        jna .j
        loop .i
    .r:
        xor edx, edx
        div ebx
        mov [a], edx
        loop .i
    .j:
        mov eax, [b]
        mov ebx, [a]
        xor edx, edx
        div ebx
        mov [b], edx
        loop .i
    .h:  
        add eax, ebx
        PRINT_DEC 4, eax
        xor eax, eax
        ret
