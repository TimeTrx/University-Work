INCLUDE irvine32.inc
.data
myarray DWORD 1,2,3,4,5,6,7,8,0
mysum WORD 0

.code
main PROC
mov edi, OFFSET myarray
mov ecx, LENGTHOF myarray
mov edx, SIZEOF myarray
mov ecx, (LENGTHOF myarray + 1) /2

L1: 
add eax, myarray[edi]
add edi, 8
loop L1


mov mysum, ax

call dumpregs
exit 

main ENDP
END main