	.text
	.file	"hello"
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset %rbx, -16
	movl	$9, %edi
	movl	$36, %esi
	callq	gcd
	movl	%eax, %ebx
	movl	$3, %edi
	movl	$6, %esi
	callq	gcd
	movl	%eax, %ecx
	imull	%ebx, %ecx
	movl	%ecx, ans(%rip)
	movl	$.L__unnamed_1, %edi
	xorl	%eax, %eax
	movl	%ecx, %esi
	callq	printf
	movl	$.L__unnamed_2, %edi
	callq	puts
	popq	%rbx
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.globl	gcd                     # -- Begin function gcd
	.p2align	4, 0x90
	.type	gcd,@function
gcd:                                    # @gcd
	.cfi_startproc
# %bb.0:                                # %entry
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	movl	%edi, 12(%rsp)
	movl	%esi, 20(%rsp)
	testl	%esi, %esi
	je	.LBB1_1
# %bb.2:                                # %else
	movl	20(%rsp), %edi
	movl	12(%rsp), %eax
	xorl	%edx, %edx
	divl	%edi
	movl	%edx, %esi
	callq	gcd
	jmp	.LBB1_3
.LBB1_1:                                # %then
	movl	12(%rsp), %eax
.LBB1_3:                                # %ifcont
	movl	%eax, 16(%rsp)
	movl	16(%rsp), %eax
	addq	$24, %rsp
	retq
.Lfunc_end1:
	.size	gcd, .Lfunc_end1-gcd
	.cfi_endproc
                                        # -- End function
	.type	.L__unnamed_2,@object   # @0
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_2:
	.asciz	"\n"
	.size	.L__unnamed_2, 2

	.type	ans,@object             # @ans
	.local	ans
	.comm	ans,4,4
	.type	.L__unnamed_1,@object   # @1
.L__unnamed_1:
	.asciz	"%d "
	.size	.L__unnamed_1, 4


	.section	".note.GNU-stack","",@progbits
