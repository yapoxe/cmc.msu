;�����:
;��������: https://vk.com/yapoxe
;����������� �������:	1 �
;����������� ������:	64 M
;������������ ���������� �������:	24
;� ������ ������ ��� ���������� ����� ���������� ����� �������� ���� �������� ����������� �����.
;�� ���� ��������� �������� ��� ����� ����� A � B (2 ? A, B ? 1000000000). 
;��������� ������ ������� ������������ ����� ����� � ����� ������.

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
