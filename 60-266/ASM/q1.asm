TITLE Q1 Template						(main.asm)

; Description:
; Question 1 Assignment 1
; Revision date: Oct 18, 13

INCLUDE Irvine32.inc
.data
X1 SDWORD 6
X2 SDWORD 7
X3 SDWORD 3
X4 SDWORD -10
FinalVal SDWORD ?

.code
main PROC

mov eax, X1
mov edx, X2
mov ebx, X3
mov esi, X4
add eax, edx
sub ebx, esi
sub eax, ebx
mov FinalVal,  eax ; FinalVal = X1+X2-(X3-X4)
call DumpRegs
	exit
main ENDP

END main