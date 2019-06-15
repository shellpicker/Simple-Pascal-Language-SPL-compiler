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
	movl	$0, k(%rip)
	movl	$k, %edi
	movl	$5, %esi
	callq	go
	movl	%eax, %ecx
	movl	%ecx, f(%rip)
	movl	$.L__unnamed_1, %edi
	xorl	%eax, %eax
	movl	%ecx, %esi
	callq	printf
	movl	$.L__unnamed_2, %edi
	callq	puts
	movl	k(%rip), %esi
	movl	$.L__unnamed_3, %edi
	xorl	%eax, %eax
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
	movq	%rdi, 8(%rsp)
	movl	%esi, 4(%rsp)
	testl	%esi, %esi
	je	.LBB1_2
# %bb.1:                                # %then
	movl	4(%rsp), %ebx
	movq	8(%rsp), %rdi
	leal	-1(%rbx), %esi
	callq	go
	imull	%ebx, %eax
	movl	%eax, (%rsp)
	jmp	.LBB1_3
.LBB1_2:                                # %else
	movl	$1, (%rsp)
.LBB1_3:                                # %ifcont
	movq	8(%rsp), %rax
	movl	(%rsp), %ecx
	addl	%ecx, (%rax)
	movl	(%rsp), %eax
	addl	%eax, k(%rip)
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

	.type	f,@object               # @f
	.local	f
	.comm	f,4,4
	.type	k,@object               # @k
	.local	k
	.comm	k,4,4
	.type	fk,@object              # @fk
	.local	fk
	.comm	fk,4,4
	.type	t,@object               # @t
	.local	t
	.comm	t,8,8
	.type	.L__unnamed_1,@object   # @1
.L__unnamed_1:
	.asciz	"%d "
	.size	.L__unnamed_1, 4

	.type	.L__unnamed_3,@object   # @2
.L__unnamed_3:
	.asciz	"%d "
	.size	.L__unnamed_3, 4


	.section	".note.GNU-stack","",@progbits
