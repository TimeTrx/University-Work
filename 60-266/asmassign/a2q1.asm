TITLE A2Q1 Template						(a2q1.asm)

; Description:
; Question 1 Assignment 2
; Revision date: Nov 14,13

INCLUDE Irvine32.inc
.data
list DWORD 50 Dup(?) 
count DWORD 0
a1 BYTE "A+", 0
a2 BYTE "A", 0
a3 BYTE "A-", 0
b1 BYTE "B+", 0
b2 BYTE "B", 0
b3 BYTE "B-", 0
c1 BYTE "C+", 0
c2 BYTE "C", 0
c3 BYTE "C-", 0
d1 BYTE "D+", 0
d2 BYTE "D", 0
d3 BYTE "D-", 0
f BYTE "F", 0
input SDWORD ?
.code
main PROC
mov esi, OFFSET list
mov ecx, LENGTHOF list
.REPEAT
call ReadInt
mov input, eax
mov list, eax
add esi, 4
call gradereturn
inc count
.UNTIL count == 50 || input == -1

	exit
main ENDP


gradereturn PROC
mov eax, input
.IF eax < 101 && eax > 89
mov edx, OFFSET a1
call WriteString
.ENDIF
.IF eax < 90 && eax > 84
mov edx, OFFSET a2
call WriteString
.ENDIF
.IF eax < 80 && eax > 69
mov edx, OFFSET a3
call WriteString
.ENDIF
.IF eax < 101 && eax > 69
mov edx, OFFSET b1
call WriteString
.ENDIF
.IF eax < 101 && eax > 89
mov edx, OFFSET b2
call WriteString
.ENDIF
.IF eax < 101 && eax > 89
mov edx, OFFSET b3
call WriteString
.ENDIF
.IF eax < 101 && eax > 89
mov edx, OFFSET c1
call WriteString
.ENDIF
.IF eax < 101 && eax > 89
mov edx, OFFSET c2
call WriteString
.ENDIF
.IF eax < 101 && eax > 89
mov edx, OFFSET c3
call WriteString
.ENDIF
.IF eax < 101 && eax > 89
mov edx, OFFSET d1
call WriteString
.ENDIF
.IF eax < 101 && eax > 89
mov edx, OFFSET d2
call WriteString
.ENDIF
.IF eax < 101 && eax > 89
mov edx, OFFSET d3
call WriteString
.ENDIF
.IF eax < 101 && eax > 89
mov edx, OFFSET f
call WriteString
.ENDIF
ret
gradereturn ENDP

END main