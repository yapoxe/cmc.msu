;�����:
;��������: https://vk.com/yapoxe
;��� �������� �����:	data.in
;����������� �������:	1 �
;����������� ������:	64 M
;������������ ���������� �������:	16
;��� ��������� ��������� ���������� ����� ����� �� ������� ����� � ������� ��� �� ����������� �����. 
;������ ����� ����� ���������� � 32-� ��������� ����������� ���. 
;���������� ����� �� ����������� 100000 � �� ����� ����.
;����������� ������������ ������� �����-������ ���������� io.inc. 
;��� ������ ���� ������������ ������� ���� ������ ���� �������� �� 16 ����.

%include "io.inc" 
section .data
    x dd 0
    y dd 0
section .rodata 
    A db "data.in", 0 
    B db "r", 0
    C db "%d", 0
section .text
CEXTERN fopen
CEXTERN fscanf
CEXTERN fclose
global CMAIN 
CMAIN:
    mov ebp, esp; for correct debugging
    push ebp
    mov ebp, esp
    sub esp, 24
    mov dword[esp], A
    mov dword[esp+4], B
    call fopen
    mov esi, eax
    while:
        mov dword[esp], esi
        mov dword[esp+4], C
        mov dword[esp+8], y
        call fscanf
        cmp eax, 1
        jne stop
        inc dword[x]
        jmp while
    stop:
    mov dword[esp], esi
    call fclose
    add esp, 24
    pop ebp
    PRINT_DEC 4, [x]
    xor eax, eax
    ret