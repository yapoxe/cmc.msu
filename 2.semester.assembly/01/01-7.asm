;�����:
;��������: https://vk.com/yapoxe
;����������� �������:	1 �
;����������� ������:	64 M
;������������ ���������� �������:	16
;�� ���� ��������� �������� 4 ����������� 8-������ ����� �����: a, b, c, d. 
;��������� ��������� ����� ����������� 32-������ ����� X, ��� ��� ������� 8 ��� ����� a, 
;��������� �� ���� 8 ��� - ����� b, ��������� 8 ��� - ����� c, �, �������, ������� 8 ��� - ����� d. 
;��������� ������ �������� ������� ����� X.
;����������� ������������ ���������� �������� �������� ������ � ����������.

%include "io.inc"

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    
    xor eax, eax
    GET_UDEC 1, ebx
    or eax, ebx
    ror eax, 8
    GET_UDEC 1, ebx
    or eax, ebx
    ror eax, 8
    GET_UDEC 1, ebx
    or eax, ebx
    ror eax, 8
    GET_UDEC 1, ebx
    or eax, ebx
    xor ebx, ebx
    ror eax, 8
    
    PRINT_UDEC 4, eax
    
    xor eax, eax
    ret