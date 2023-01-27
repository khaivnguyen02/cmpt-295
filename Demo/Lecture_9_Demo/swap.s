	.file	"swap.c"
	.text
	.globl	swap
	.type	swap, @function
swap:
.LFB0:
	.cfi_startproc
	# Suggestion: indicate parameter-to-register mapping
	# xp -> %rdi, yp -> %rsi
	endbr64
	movq	(%rdi), %rax  #  L1 = *xp, L1 -> %rax  
	movq	(%rsi), %rdx  #  L2 = *yp, L2 -> %rdx
	movq	%rdx, (%rdi)  # *xp = L2
	movq	%rax, (%rsi)  # *yp = L1
	ret
	.cfi_endproc
.LFE0:
	.size	swap, .-swap
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4: