	.file	"sort.c"
	.text
	.globl	quickSort
	.type	quickSort, @function
quickSort:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	%edx, -32(%rbp)
	movl	-28(%rbp), %eax
	movl	%eax, -16(%rbp)
	movl	-32(%rbp), %eax
	movl	%eax, -12(%rbp)
	movl	-28(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -8(%rbp)
	jmp	.L2
.L5:
	subl	$1, -32(%rbp)
.L3:
	movl	-32(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	cmpl	%eax, -8(%rbp)
	jge	.L4
	movl	-28(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jl	.L5
.L4:
	movl	-28(%rbp), %eax
	cmpl	-32(%rbp), %eax
	je	.L7
	movl	-32(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	-28(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,4), %rcx
	movq	-24(%rbp), %rdx
	addq	%rcx, %rdx
	movl	(%rax), %eax
	movl	%eax, (%rdx)
	addl	$1, -28(%rbp)
	jmp	.L7
.L9:
	addl	$1, -28(%rbp)
.L7:
	movl	-28(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	cmpl	%eax, -8(%rbp)
	jle	.L8
	movl	-28(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jl	.L9
.L8:
	movl	-28(%rbp), %eax
	cmpl	-32(%rbp), %eax
	je	.L2
	movl	-28(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	-32(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,4), %rcx
	movq	-24(%rbp), %rdx
	addq	%rcx, %rdx
	movl	(%rax), %eax
	movl	%eax, (%rdx)
	subl	$1, -32(%rbp)
.L2:
	movl	-28(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jl	.L3
	movl	-28(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movl	-8(%rbp), %eax
	movl	%eax, (%rdx)
	movl	-28(%rbp), %eax
	movl	%eax, -4(%rbp)
	movl	-16(%rbp), %eax
	movl	%eax, -28(%rbp)
	movl	-12(%rbp), %eax
	movl	%eax, -32(%rbp)
	movl	-28(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jge	.L12
	movl	-4(%rbp), %eax
	leal	-1(%rax), %edx
	movl	-28(%rbp), %ecx
	movq	-24(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	quickSort
.L12:
	movl	-32(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jle	.L14
	movl	-4(%rbp), %eax
	leal	1(%rax), %ecx
	movl	-32(%rbp), %edx
	movq	-24(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	quickSort
.L14:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	quickSort, .-quickSort
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
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
