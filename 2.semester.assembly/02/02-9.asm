;�����:
;��������: https://vk.com/yapoxe
;����������� �������:	1 �
;����������� ������:	64 M
;������������ ���������� �������:	24
;� ������ ������ ��� ���������� ���������, ����� �� ����� P ������ �������������� ABCD.
;�� ���� ��������� �������� 5 ��� �����: ������� ���������� ������ ��������������, � ����� ���������� ����� P. 
;��� ���������� ����� � �� ������ �� ����������� 1000. ������� �������������� ����� ���� ����������� � ������������ �������. 
;�������������, ��� ������� �������������� ����������� ���� ���������.
;��������� ������ ������� YES, ���� ����� P ����� ������ ������ �������������� ABCD, � NO � ��������� ������.

%include "io.inc"

section .data
    max dd 0
    mix dd 0
    may dd 0
    miy dd 0
    xx dd 0
    yy dd 0
    
section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    
    GET_UDEC 4, eax
    mov [max], eax
    GET_UDEC 4, eax
    mov [may], eax
    
    GET_UDEC 4, eax
    mov ebx, [max]
    cmp eax, ebx
    jnz a
    s:
    GET_UDEC 4, eax
    mov ebx, [may]
    cmp eax, ebx
    jnz b
    jmp q
    a:
        mov [mix], eax
        jmp s
    b:
        mov [miy], eax
    q:

    GET_UDEC 4, eax
    mov ebx, [max]
    cmp eax, ebx
    jnz c
    f:
    GET_UDEC 4, eax
    mov ebx, [may]
    cmp eax, ebx
    jnz d
    jmp w
    c:
        mov [mix], eax
        jmp f
    d:
        mov [miy], eax
    w:
    
    GET_UDEC 4, eax
    mov ebx, [max]
    cmp eax, ebx
    jnz t
    o:
    GET_UDEC 4, eax
    mov ebx, [may]
    cmp eax, ebx
    jnz u
    jmp i
    t:
        mov [mix], eax
        jmp o
    u:
        mov [miy], eax
    i:
    
    GET_UDEC 4, eax
    mov [xx], eax
    GET_UDEC 4, eax
    mov [yy], eax    
    
    mov eax, [max]
    mov ebx, [mix]
    cmp eax, ebx
    jl r 
    jmp y
    r:
        mov [max], ebx
        mov [mix], eax
    y:
    mov eax, [may]
    mov ebx, [miy]
    cmp eax, ebx
    jl l 
    jmp m
    l:
        mov [may], ebx
        mov [miy], eax
    m:
    
    mov eax, [max]
    mov ebx, [xx]
    cmp ebx, eax
    jge v
    
    mov eax, [mix]
    mov ebx, [xx]
    cmp ebx, eax
    jle v

    mov eax, [may]
    mov ebx, [yy]
    cmp ebx, eax
    jge v
    
    mov eax, [miy]
    mov ebx, [yy]
    cmp ebx, eax
    jle v
    
    PRINT_STRING "YES"
    xor eax, eax
    ret
    v:
        PRINT_STRING "NO"
        xor eax, eax
        ret