;�����:
;��������: https://vk.com/yapoxe
;����������� �������:	1 �
;����������� ������:	64 M
;������������ ���������� �������:	16
;�� ���� ��������� �������� ����������� 32-������ ����� ����� N. 
;��������� ����� ���������� ��������� ����� � �������� ������������� ������� �����.

%include "io.inc"

section .data
    y dd 0

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    xor ebx, ebx
    GET_UDEC 4, eax
    mov ecx, 32
    z:
        shr eax, 1
        jc k
        jmp s
    k: 
        inc ebx
    s:
        loop z
    PRINT_UDEC 4, ebx
    xor eax, eax
    ret