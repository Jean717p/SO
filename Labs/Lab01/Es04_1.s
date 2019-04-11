	.file	"Es04_1.c"
	.section	.rodata
.LC0:
	.string	"%s.1"
.LC1:
	.string	"r"
.LC2:
	.string	"w"
.LC3:
	.string	"%c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$1056, %rsp
	movl	%edi, -1044(%rbp)
	movq	%rsi, -1056(%rbp)
	movq	-1056(%rbp), %rax
	addq	$16, %rax
	movq	(%rax), %rdx
	leaq	-1040(%rbp), %rax
	movl	$.LC0, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	sprintf
	movq	-1056(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movl	$.LC1, %esi
	movq	%rax, %rdi
	call	fopen
	movq	%rax, -8(%rbp)
	movq	-1056(%rbp), %rax
	addq	$16, %rax
	movq	(%rax), %rax
	movl	$.LC2, %esi
	movq	%rax, %rdi
	call	fopen
	movq	%rax, -16(%rbp)
	jmp	.L2
.L3:
	movzbl	-17(%rbp), %eax
	movsbl	%al, %eax
	movq	-16(%rbp), %rdx
	movq	%rdx, %rsi
	movl	%eax, %edi
	call	fputc
.L2:
	leaq	-17(%rbp), %rdx
	movq	-8(%rbp), %rax
	movl	$.LC3, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_fscanf
	cmpl	$-1, %eax
	jne	.L3
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	fclose
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	fclose
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 5.1.1 20150618 (Red Hat 5.1.1-4)"
	.section	.note.GNU-stack,"",@progbits
