;�����:
;��������: https://vk.com/yapoxe
;����������� �������:	1 �
;����������� ������:	64 M
;������������ ���������� �������:	16
;�� ����������� ������ ����� ������� ����� 32�-������ ����������� �����. 
;��������� ������� ��� � ������������ ������� ��������� ��� ���������� �����.
;����������� ������������ �����-���� ������������ �������, �� ����������� ������������ ������ 
;�������� �����-������ ���������� io.inc.

%include "io.inc"

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    GET_UDEC 4, eax
    mov ecx, 1
    mov ebx, 8
    xor esi, esi
    inc esi
    z:
        xor edx, edx
        div ebx
        push edx
        cmp eax, 1
        jb s
        inc ecx
        inc esi
        loop z
    s:
        mov ecx, esi
        jmp k
    k:
        pop eax
        PRINT_DEC 4, eax
        loop k
    xor eax, eax
    ret