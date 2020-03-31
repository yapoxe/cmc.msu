;Автор:
;Владимир: https://vk.com/yapoxe
;Имя входного файла:	input.txt
;Имя выходного файла:	output.txt
;Ограничение времени:	1 с
;Ограничение памяти:	64 M
;Максимальное количество посылок:	24
;Это скучная задача.
;В текстовом файле input.txt задаётся последовательность знаковых целых 32х-битных чисел, 
;разделённых проивольными комбинациями пробельных символов и символов перевода строки. 
;Длина последовательности не превышает 1000 элементов. 
;Требуется вывести отсортированную последовательность в файл output.txt. 
;Для сортировки воспользуйтесь библиотечной функцией qsort
;Запрещается использовать макросы ввода-вывода библиотеки io.inc. 
;При вызове всех библиотечных функций стек должен быть выровнен по 16 байт.

%include "io.inc"

section .bss
    mas resd 1000
    
section .data
    y dd 0
    i dd 0
    
section .rodata 
    input db "input.txt", 0 
    read db "r", 0
    output db "output.txt", 0 
    write db "w", 0
    strnumber db "%d ", 0
    
section .text
CEXTERN fopen
CEXTERN fscanf
CEXTERN qsort
CEXTERN fprintf
CEXTERN fclose
global CMAIN 

compare:
    mov edx, dword[esp+4] 
    mov edx, dword[edx] 
    mov ecx, dword[esp+8] 
    mov ecx, dword[ecx] 
    cmp edx, ecx
    jl retminus ; Если eax < ebx
    jz retzero  ; Если eax = ebx
    mov eax, 1
    ret   ; Возвращаем 1, если eax > ebx
    retminus:
        mov eax, -1
        ret ; Возвращаем -1, если eax < ebx
    retzero:
        mov eax, 0
        ret ; Возвращаем 0, если eax = ebx
        
CMAIN:
    mov ebp, esp ; Дебаг
    push ebp
    mov ebp, esp
    sub esp, 24
    xor ecx, ecx
    mov [i], ecx
    mov dword[esp], input ; Входной файл
    mov dword[esp+4], read ; Считывание
    call fopen ; Открываем
    mov esi, eax ; Бэкап eax
    ;Считываем числа из файла в массив
    while:
        mov dword[esp], esi ; Указатель на файл
        mov dword[esp+4], strnumber ; Строчка для считывания чисел
        mov dword[esp+8], y ; Само число
        call fscanf
        cmp eax, 1 ; Если scanf не 1, то выходим
        jne stoper
        mov ebx, [y] ; Число в регистр
        mov ecx, [i] ; Кладем i, т.к. ecx не сохраняется при использовании функций fopen, fscanf
        mov dword[mas+ecx*4], ebx ; Кладем в массив число
        inc dword[i] ; i++
        jmp while
    stoper:
    ;fclose(*file)
    mov dword[esp], esi ; Указатель на файл
    call fclose
    ;qsort(*mas, n, 4, func)
    mov dword[esp+12], compare ; Функция сравнения
    mov dword[esp+8], 4 ; Размер элемента
    mov ecx, [i]
    mov dword[esp+4], ecx ; Количество элементов
    mov dword[esp], mas ; Указатель на начало массива
    call qsort
    ;fopen(*file, str)
    mov dword[esp], output ; Входной файл
    mov dword[esp+4], write ; Считывание
    call fopen ; Открываем
    mov esi, eax ; Бэкап eax
    ;printf(*file, str)
    mov ecx, [i]
    mov [y], ecx
    .while:
        mov ecx, [i]
        cmp ecx, 1
        jl ex
        mov ebx, [y]
        sub ebx, ecx
        mov ecx, [mas+ebx*4]
        mov dword[esp], esi ; Указатель на файл
        mov dword[esp+4], strnumber ; Строчка для записи чисел
        mov dword[esp+8], ecx ; Само число
        dec dword[i]
        call fprintf
        loop .while
    ex:
    add esp, 24
    pop ebp
    xor eax, eax
    ret