;�����:
;��������: https://vk.com/yapoxe
;��� �������� �����:	input.txt
;��� ��������� �����:	output.txt
;����������� �������:	1 �
;����������� ������:	64 M
;������������ ���������� �������:	24
;��� ������� ������.
;� ��������� ����� input.txt ������� ������������������ �������� ����� 32�-������ �����, 
;���������� ������������ ������������ ���������� �������� � �������� �������� ������. 
;����� ������������������ �� ��������� 1000 ���������. 
;��������� ������� ��������������� ������������������ � ���� output.txt. 
;��� ���������� �������������� ������������ �������� qsort
;����������� ������������ ������� �����-������ ���������� io.inc. 
;��� ������ ���� ������������ ������� ���� ������ ���� �������� �� 16 ����.

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
    jl retminus ; ���� eax < ebx
    jz retzero  ; ���� eax = ebx
    mov eax, 1
    ret   ; ���������� 1, ���� eax > ebx
    retminus:
        mov eax, -1
        ret ; ���������� -1, ���� eax < ebx
    retzero:
        mov eax, 0
        ret ; ���������� 0, ���� eax = ebx
        
CMAIN:
    mov ebp, esp ; �����
    push ebp
    mov ebp, esp
    sub esp, 24
    xor ecx, ecx
    mov [i], ecx
    mov dword[esp], input ; ������� ����
    mov dword[esp+4], read ; ����������
    call fopen ; ���������
    mov esi, eax ; ����� eax
    ;��������� ����� �� ����� � ������
    while:
        mov dword[esp], esi ; ��������� �� ����
        mov dword[esp+4], strnumber ; ������� ��� ���������� �����
        mov dword[esp+8], y ; ���� �����
        call fscanf
        cmp eax, 1 ; ���� scanf �� 1, �� �������
        jne stoper
        mov ebx, [y] ; ����� � �������
        mov ecx, [i] ; ������ i, �.�. ecx �� ����������� ��� ������������� ������� fopen, fscanf
        mov dword[mas+ecx*4], ebx ; ������ � ������ �����
        inc dword[i] ; i++
        jmp while
    stoper:
    ;fclose(*file)
    mov dword[esp], esi ; ��������� �� ����
    call fclose
    ;qsort(*mas, n, 4, func)
    mov dword[esp+12], compare ; ������� ���������
    mov dword[esp+8], 4 ; ������ ��������
    mov ecx, [i]
    mov dword[esp+4], ecx ; ���������� ���������
    mov dword[esp], mas ; ��������� �� ������ �������
    call qsort
    ;fopen(*file, str)
    mov dword[esp], output ; ������� ����
    mov dword[esp+4], write ; ����������
    call fopen ; ���������
    mov esi, eax ; ����� eax
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
        mov dword[esp], esi ; ��������� �� ����
        mov dword[esp+4], strnumber ; ������� ��� ������ �����
        mov dword[esp+8], ecx ; ���� �����
        dec dword[i]
        call fprintf
        loop .while
    ex:
    add esp, 24
    pop ebp
    xor eax, eax
    ret