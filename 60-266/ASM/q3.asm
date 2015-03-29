TITLE Q3 Template						(main.asm)

; Description:
; Question 3 Assignment 1
; Revision date: Oct 18, 13

INCLUDE Irvine32.inc
.data
myarray DWORD 10 dup (0) 
.code
main PROC
mov ecx, 10 ; ten loops and then it ends
mov esi, OFFSET myarray
L1:
call ReadInt
mov [esi], eax ; inputs it into the array
add esi,4
loop L1
mov ecx, 10 ; ten loops and then it ends
mov esi, OFFSET myarray
L2: 
mov eax, ecx
call SetTextColor ;calls the color of the text
mov eax, [esi]
add esi,4
call WriteHex ;output in hexdecimal form
call crlf ; skips lines in output
loop L2

	exit
main ENDP

END main