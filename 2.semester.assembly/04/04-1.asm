;�����:
;��������: https://vk.com/yapoxe
;����������� �������:	1 �
;����������� ������:	64 M
;������������ ���������� �������:	16
;�� ����������� ������ ����� ������� ������������������ ����������� ����� 32�-������ ����� � ���������� ������, 
;���������� ����������� ���������. 
;��������� ������� �� �� ����� ������������������, �� ������ ����� ������ ���� �������� ����� printf � ������� "0x%08X\n"
;����������� ������������ ������� �����-������ ���������� io.inc. 
;��� ������ ���� ������������ ������� ���� ������ ���� �������� �� 16 ����.

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