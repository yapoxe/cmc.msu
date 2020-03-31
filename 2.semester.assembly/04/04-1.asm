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
section .rodata 
    A db "%u", 0 
    B db "0x%08X", 0
section .text 
global CMAIN 
CMAIN: 
    mov ebp, esp; for correct debugging 
    push ebp 
    mov ebp, esp 
    push ebx 
    sub esp, 20
    while: 
        lea ebx, [esp+8] 
        mov dword[esp+4], ebx 
        mov dword [esp], A 
        call scanf 
        mov esi, eax 
        cmp eax, 1 
        jne stop
        mov ebx, dword[esp+8] 
        mov dword[esp+4], ebx 
        mov dword [esp], B 
        call printf
        NEWLINE
        jmp while
    stop:
    add esp, 20
    pop ebx 
    pop ebp
    xor eax, eax
    ret