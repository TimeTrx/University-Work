TITLE A2Q3 Template						(a2q3.asm)

; Description:
; Question 3 Assignment 2
; Revision date: Nov 14,13

INCLUDE Irvine32.inc
.data
buffer BYTE 11 DUP(0)
byteCount DWORD ?
reply1 BYTE "Character 'a' not found", 0  ; the string return when no 'a' found
.code
main PROC
mov edx, OFFSET buffer
mov ecx, SIZEOF buffer
call ReadString ; calls for the user input
mov byteCount, eax
mov edi, OFFSET buffer
mov al, 'a' ; check for the char 'a'
mov ecx, LENGTHOF buffer
cld
repne scasb ; repeat while not equal
jnz quit
sub edi, offset buffer
mov eax, edi 
call WriteInt
	exit
quit:
mov edx, OFFSET reply1
call WriteString ; output the no character found string
	exit
main ENDP

END main