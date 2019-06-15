	.text
	.file	"hello"
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$10, %edi
	callq	go
	movl	%eax, %ecx
	movl	%ecx, i(%rip)
	movl	$.L__unnamed_1, %edi
	xorl	%eax, %eax
	movl	%ecx, %esi
	callq	printf
	movl	$.L__unnamed_2, %edi
	callq	puts
	popq	%rax
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.globl	go                      # -- Begin function go
	.p2align	4, 0x90
	.type	go,@function
go:                                     # @go
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rbx
	.cfi_def_cfa_offset 16
	subq	$16, %rsp
	.cfi_def_cfa_offset 32
	.cfi_offset %rbx, -16
	movl	%edi, 8(%rsp)
	cmpl	$1, %edi
	je	.LBB1_1
# %bb.2:                                # %else
	cmpl	$2, 8(%rsp)
	jne	.LBB1_4
.LBB1_1:                                # %then
	movl	$1, 12(%rsp)
	jmp	.LBB1_5
.LBB1_4:                                # %else4
	movl	8(%rsp), %edi
	decl	%edi
	callq	go
	movl	%eax, %ebx
	movl	8(%rsp), %edi
	addl	$-2, %edi
	callq	go
	addl	%ebx, %eax
	movl	%eax, 12(%rsp)
.LBB1_5:                                # %ifcont7
	movl	12(%rsp), %eax
	addq	$16, %rsp
	popq	%rbx
	retq
.Lfunc_end1:
	.size	go, .Lfunc_end1-go
	.cfi_endproc
                                        # -- End function
	.type	.L__unnamed_2,@object   # @0
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_2:
	.asciz	"\n"
	.size	.L__unnamed_2, 2

	.type	i,@object               # @i
	.local	i
	.comm	i,4,4
	.type	.L__unnamed_1,@object   # @1
.L__unnamed_1:
	.asciz	"%d "
	.size	.L__unnamed_1, 4


	.section	".note.GNU-stack","",@progbits
