TITLE Q2 Template						(main.asm)

; Description:
; Question 2 Assignment 1
; Revision date: Oct 18, 13

INCLUDE Irvine32.inc
.data
myarray DWORD 1,1,0,0,0,0,0,0
.code
main PROC
mov esi, 0
mov ecx, 8
L1:
mov eax, myarray[esi]
add eax, myarray[esi+4]
mov myarray[esi+8], eax
add esi, 4
loop L1
mov esi, 0
mov ecx, 8
L2:
mov eax, myarray[esi]
call WriteHex
call crlf
call WriteInt
call crlf
call WriteBin
call crlf
add esi, 4
loop L2

	exit
main ENDP

END main