;�����:
;��������: https://vk.com/yapoxe
;����������� �������:	1 �
;����������� ������:	64000000
;������������ ���������� �������:	24
;������� ������� ������������, ��������� ������������ ��� ������.
;�� ���� ��������� �������� ����� x1, y1, x2, y2, x3, y3 - ���������� ������. 
;��� ����� �����, �� ������������� �� ������ 10000.
;��������� ������ ������� ������� ������������ � ��������� �� ������ ����� ����� �������.
;��� ������� ������ ����������� ������������ ���������� �������� �������� ������ � ����������.

%include "io.inc"

section .bss
    x1 resd 1
    y1 resd 1
    x2 resd 1
    y2 resd 1
    x3 resd 1
    y3 resd 1
    s resd 1

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    GET_DEC 4, eax
    mov [x1], eax
    GET_DEC 4, eax
    mov [y1], eax
    GET_DEC 4, eax
    mov [x2], eax
    GET_DEC 4, eax
    mov [y2], eax
    GET_DEC 4, eax
    mov [x3], eax
    GET_DEC 4, eax
    mov [y3], eax
    
    GET_DEC 4, eax
    mov eax, [x1]
    sub eax, [x3]
    mov [x1], eax

    mov eax, [y1]
    sub eax, [y3]
    mov [y1], eax
    
    mov eax, [x2]
    sub eax, [x3]
    mov [x2], eax
    
    mov eax, [y2]
    sub eax, [y3]
    mov [y2], eax
    
    mov eax, [x1]
    imul eax, [y2]
    mov [x1], eax    

    mov eax, [y1]
    imul eax, [x2]
    mov [y1], eax

    
    mov eax, [x1]
    sub eax, [y1]
    mov [s], eax
    cdq
    xor eax, edx
    sub eax, edx
    xor edx, edx
    mov ebx, 2
    xor edx, edx
    div ebx
    imul edx, 5
    
    PRINT_DEC 4, eax
    PRINT_CHAR "."
    PRINT_DEC 4, edx
    
    xor eax, eax
    xor edx, edx
    xor ebx, ebx
    ret