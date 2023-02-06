	.file	"main.c"
	.text
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"x = %ld, y = %ld, z = %ld and result of arith is %ld\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB23:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	movl	$4, %edx
	movl	$3, %esi
	movl	$2, %edi
	call	arith@PLT
	movq	%rax, %rbx
	movq	%rax, %r9
	movl	$4, %r8d
	movl	$3, %ecx
	movl	$2, %edx
	leaq	.LC0(%rip), %rbp
	movq	%rbp, %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movq	%rbx, globalA(%rip)
	movl	$1, %edx
	movl	$4, %esi
	movq	$-3, %rdi
	call	arith@PLT
	movq	%rax, %r9
	movl	$1, %r8d
	movl	$4, %ecx
	movq	$-3, %rdx
	movq	%rbp, %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movl	$0, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE23:
	.size	main, .-main
	.globl	globalA
	.bss
	.align 8
	.type	globalA, @object
	.size	globalA, 8
globalA:
	.zero	8
	.ident	"GCC: (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
