	.globl times

times:
	xorl %eax, %eax
	movl %edi, %ecx
	movl %esi, %edx
	imull %edx, %ecx
	movl %ecx, %eax
	ret
