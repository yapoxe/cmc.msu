;�����:
;��������: https://vk.com/yapoxe
;����������� �������:	1 �
;����������� ������:	64 M
;������������ ���������� �������:	16
;�� ���� ��������� �������� ����������� 32-������ ����� ����� N � ����������� ����� K (1 ? K ? 31). 
;��������� ����� K ������� ����� ����� N � ������� ���������� ����� ������� �����.
;����������� ������������ ���������� �������� �������� ������ � ����������.

%include "io.inc"

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    GET_UDEC 4, eax
    GET_UDEC 4, ebx
    mov ecx, 32
    sub ecx, ebx
    shl eax, cl
    shr eax, cl
    PRINT_UDEC 4, eax
    xor eax, eax
    ret