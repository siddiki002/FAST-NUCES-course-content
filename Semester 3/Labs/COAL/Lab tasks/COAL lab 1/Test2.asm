TITLE My First Program (Test.asm)
INCLUDE Irvine32.inc
.code
abc PROC
mov eax, 47h
mov ebx, 39h
mov ecx, 60h
add eax, ebx
add eax, ecx
mov ebx, 85h
mov ecx, 64h
add eax, ebx
add eax, ecx
call DumpRegs
exit
abc ENDP
END abc