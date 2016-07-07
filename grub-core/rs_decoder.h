	.file	"reed_solomon.c"
	.text
	.type	pol_evaluate, @function
pol_evaluate:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	movl	%eax, %esi
	movl	%ecx, %edi
	xorl	%ebx, %ebx
	xorl	%eax, %eax
.L2:
	testl	%edx, %edx
	js	.L11
	movzbl	(%esi,%edx), %ecx
	testb	%cl, %cl
	je	.L3
	movzbl	1049088(%ecx), %ecx
	xorb	1048576(%ebx,%ecx), %al
.L3:
	addl	%edi, %ebx
	cmpl	$254, %ebx
	jle	.L4
	subl	$255, %ebx
.L4:
	decl	%edx
	jmp	.L2
.L11:
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.size	pol_evaluate, .-pol_evaluate
	.type	gf_mul, @function
gf_mul:
	pushl	%ebp
	movl	%esp, %ebp
	testb	%al, %al
	je	.L14
	testb	%dl, %dl
	je	.L14
	movzbl	%al, %eax
	movzbl	1049088(%eax), %ecx
	movzbl	%dl, %edx
	movzbl	1049088(%edx), %eax
	movb	1048576(%ecx,%eax), %al
	jmp	.L13
.L14:
	xorl	%eax, %eax
.L13:
	popl	%ebp
	ret
	.size	gf_mul, .-gf_mul
	.type	gauss_solve.constprop.2, @function
gauss_solve.constprop.2:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$40, %esp
	movl	%eax, -28(%ebp)
	movl	%edx, -16(%ebp)
	movl	%ecx, -32(%ebp)
	xorl	%eax, %eax
.L17:
	cmpl	-28(%ebp), %eax
	jge	.L46
	movl	$-1, 1049344(,%eax,4)
	incl	%eax
	jmp	.L17
.L46:
	xorl	%eax, %eax
.L19:
	cmpl	-16(%ebp), %eax
	jge	.L47
	movl	-32(%ebp), %edx
	movb	$0, (%edx,%eax)
	incl	%eax
	jmp	.L19
.L47:
	movl	-16(%ebp), %eax
	incl	%eax
	movl	%eax, -24(%ebp)
	movl	$0, -36(%ebp)
	xorl	%edi, %edi
	movl	$0, -20(%ebp)
.L21:
	movl	-28(%ebp), %eax
	cmpl	%eax, -20(%ebp)
	jge	.L34
	xorl	%ebx, %ebx
.L35:
	cmpl	-16(%ebp), %ebx
	jl	.L22
.L26:
	cmpl	-16(%ebp), %ebx
	je	.L27
	movl	-20(%ebp), %eax
	movl	%ebx, 1049344(,%eax,4)
	movzbl	1052672(%ebx,%edi), %eax
	movzbl	1049088(%eax), %eax
	movl	$255, %edx
	subl	%eax, %edx
	xorl	%esi, %esi
	movzbl	1048576(%edx), %eax
	movl	%eax, -40(%ebp)
	jmp	.L28
.L22:
	movl	-36(%ebp), %eax
	cmpb	$0, 1052672(%ebx,%eax)
	jne	.L26
	incl	%ebx
	jmp	.L35
.L28:
	cmpl	%esi, -16(%ebp)
	jl	.L48
	movzbl	1052672(%esi,%edi), %eax
	movl	-40(%ebp), %edx
	call	gf_mul
	movb	%al, 1052672(%esi,%edi)
	incl	%esi
	jmp	.L28
.L48:
	movl	-20(%ebp), %eax
	incl	%eax
	movl	%eax, -40(%ebp)
	movl	-24(%ebp), %eax
	leal	(%eax,%edi), %ecx
.L30:
	movl	-28(%ebp), %eax
	cmpl	%eax, -40(%ebp)
	je	.L27
	xorl	%esi, %esi
	movzbl	1052672(%ebx,%ecx), %eax
	movl	%eax, -48(%ebp)
.L31:
	cmpl	%esi, -16(%ebp)
	jl	.L49
	movb	1052672(%esi,%ecx), %al
	movl	%ecx, -52(%ebp)
	movb	%al, -41(%ebp)
	movzbl	1052672(%esi,%edi), %eax
	movl	-48(%ebp), %edx
	call	gf_mul
	xorb	-41(%ebp), %al
	movl	-52(%ebp), %ecx
	movb	%al, 1052672(%esi,%ecx)
	incl	%esi
	jmp	.L31
.L49:
	incl	-40(%ebp)
	addl	-24(%ebp), %ecx
	jmp	.L30
.L27:
	incl	-20(%ebp)
	movl	-24(%ebp), %eax
	addl	%eax, %edi
	addl	%eax, -36(%ebp)
	jmp	.L21
.L34:
	movl	-28(%ebp), %ebx
	decl	%ebx
	movl	-16(%ebp), %edx
	movl	%edx, %eax
	notl	%eax
	movl	%eax, -28(%ebp)
	movl	-24(%ebp), %edi
	imull	%ebx, %edi
	leal	1052672(%edx,%edi), %eax
	movl	%eax, -20(%ebp)
.L36:
	testl	%ebx, %ebx
	js	.L50
	movl	1049344(,%ebx,4), %eax
	movl	%eax, -24(%ebp)
	incl	%eax
	je	.L37
	xorl	%ecx, %ecx
	xorl	%esi, %esi
.L38:
	cmpl	-16(%ebp), %esi
	jge	.L51
	movl	%ecx, -36(%ebp)
	movl	-32(%ebp), %eax
	movzbl	(%eax,%esi), %edx
	movzbl	1052672(%esi,%edi), %eax
	call	gf_mul
	movl	-36(%ebp), %ecx
	xorl	%eax, %ecx
	incl	%esi
	jmp	.L38
.L51:
	movl	-20(%ebp), %eax
	xorb	(%eax), %cl
	movl	-32(%ebp), %eax
	movl	-24(%ebp), %edx
	movb	%cl, (%eax,%edx)
.L37:
	decl	%ebx
	movl	-28(%ebp), %eax
	addl	%eax, -20(%ebp)
	addl	%eax, %edi
	jmp	.L36
.L50:
	addl	$40, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.size	gauss_solve.constprop.2, .-gauss_solve.constprop.2
	.globl	grub_reed_solomon_recover
	.type	grub_reed_solomon_recover, @function
grub_reed_solomon_recover:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$64, %esp
	movl	%eax, -64(%ebp)
	movl	%edx, -32(%ebp)
	movl	%ecx, -36(%ebp)
	addl	%edx, %eax
	movl	%eax, -48(%ebp)
	testl	%ecx, %ecx
	je	.L52
	leal	-1(%eax,%ecx), %ebx
	movl	%ebx, %eax
.L54:
	cmpl	-48(%ebp), %eax
	jb	.L59
	cmpb	$0, (%eax)
	je	.L55
.L59:
	subl	%eax, %ebx
	movl	$2, %ecx
	movl	-36(%ebp), %eax
	cltd
	idivl	%ecx
	cmpl	%eax, %ebx
	jg	.L52
	movb	$0, 1049088
	movb	$1, %al
	xorl	%edx, %edx
	jmp	.L64
.L55:
	decl	%eax
	jmp	.L54
.L60:
	sall	%eax
.L61:
	incl	%edx
	cmpl	$255, %edx
	je	.L63
.L64:
	movb	%al, 1048576(%edx)
	movb	%al, 1048831(%edx)
	movzbl	%al, %ecx
	movb	%dl, 1049088(%ecx)
	testb	%al, %al
	jns	.L60
	leal	(%ecx,%ecx), %eax
	xorl	$29, %eax
	jmp	.L61
.L98:
	movl	-36(%ebp), %ecx
	addl	-32(%ebp), %ecx
	cmpl	$102400, %ecx
	jbe	.L99
	imull	$200, -32(%ebp), %eax
	xorl	%edx, %edx
	divl	%ecx
	movl	%eax, -24(%ebp)
	sall	$9, -24(%ebp)
	imull	$200, -36(%ebp), %eax
	xorl	%edx, %edx
	divl	%ecx
	movl	%eax, -40(%ebp)
	sall	$9, -40(%ebp)
.L65:
	movl	-24(%ebp), %eax
	leal	511(%eax), %edi
	movl	%edi, -44(%ebp)
	movl	-64(%ebp), %edi
	movl	%edi, -52(%ebp)
	leal	-1(%eax), %ebx
	movl	%ebx, -68(%ebp)
	movl	-48(%ebp), %edi
	leal	511(%edi,%eax), %eax
	movl	%eax, -72(%ebp)
.L97:
	movl	-44(%ebp), %ebx
	movl	%ebx, %eax
	shrl	$9, %eax
	movl	%eax, -20(%ebp)
	movl	-40(%ebp), %eax
	subl	-24(%ebp), %eax
	addl	%ebx, %eax
	shrl	$9, %eax
	movl	%eax, -16(%ebp)
	jne	.L103
.L66:
	decl	-44(%ebp)
	incl	-52(%ebp)
	movl	-68(%ebp), %eax
	cmpl	%eax, -44(%ebp)
	jne	.L97
	movl	-24(%ebp), %eax
	addl	%eax, -64(%ebp)
	movl	-40(%ebp), %esi
	addl	%esi, -48(%ebp)
	subl	%eax, -32(%ebp)
	subl	%esi, -36(%ebp)
.L63:
	cmpl	$0, -32(%ebp)
	jne	.L98
	jmp	.L52
.L99:
	movl	-36(%ebp), %eax
	movl	%eax, -40(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, -24(%ebp)
	jmp	.L65
.L103:
	xorl	%eax, %eax
	cmpl	$0, -20(%ebp)
	je	.L66
.L67:
	cmpl	-20(%ebp), %eax
	jge	.L104
	movl	%eax, %edx
	sall	$9, %edx
	movl	-52(%ebp), %esi
	movb	(%esi,%edx), %dl
	movb	%dl, 1052160(%eax)
	incl	%eax
	jmp	.L67
.L104:
	xorl	%eax, %eax
.L71:
	cmpl	-16(%ebp), %eax
	jge	.L105
	movl	-72(%ebp), %ecx
	subl	-44(%ebp), %ecx
	movl	%eax, %edx
	sall	$9, %edx
	movb	(%ecx,%edx), %dl
	movl	-20(%ebp), %ebx
	movb	%dl, 1052160(%eax,%ebx)
	incl	%eax
	jmp	.L71
.L105:
	movl	-16(%ebp), %eax
	movl	%eax, %ebx
	shrl	%ebx
	movl	%ebx, -28(%ebp)
	xorl	%esi, %esi
	movl	-20(%ebp), %edi
	leal	-1(%edi,%eax), %eax
	movl	%eax, -56(%ebp)
.L73:
	movl	%esi, %ecx
	movl	-56(%ebp), %edx
	movl	$1052160, %eax
	call	pol_evaluate
	movb	%al, 1051904(%esi)
	incl	%esi
	cmpl	-16(%ebp), %esi
	jl	.L73
	xorl	%eax, %eax
.L76:
	cmpb	$0, 1051904(%eax)
	jne	.L75
	incl	%eax
	cmpl	-16(%ebp), %eax
	jl	.L76
.L75:
	cmpl	-16(%ebp), %eax
	je	.L77
	movl	-28(%ebp), %eax
	leal	1(%eax), %esi
	xorl	%ecx, %ecx
	xorl	%edx, %edx
	jmp	.L78
.L77:
	xorl	%eax, %eax
	jmp	.L79
.L83:
	movb	1051904(%eax,%edx), %bl
	movb	%bl, 1052672(%eax,%ecx)
	incl	%eax
	cmpl	%eax, -28(%ebp)
	jge	.L83
	incl	%edx
	addl	%esi, %ecx
.L78:
	xorl	%eax, %eax
	cmpl	-28(%ebp), %edx
	jl	.L83
.L82:
	cmpl	-28(%ebp), %eax
	jge	.L106
	movb	$0, 1050368(%eax)
	incl	%eax
	jmp	.L82
.L106:
	movl	$1050368, %ecx
	movl	-28(%ebp), %ebx
	movl	%ebx, %edx
	movl	%ebx, %eax
	call	gauss_solve.constprop.2
	xorl	%esi, %esi
	xorl	%edi, %edi
	movl	-16(%ebp), %eax
	addl	-20(%ebp), %eax
	movl	%eax, -28(%ebp)
	decl	%ebx
.L85:
	cmpl	-28(%ebp), %esi
	jge	.L107
	movl	$255, %ecx
	subl	%esi, %ecx
	movl	%ebx, %edx
	movl	$1050368, %eax
	call	pol_evaluate
	cmpb	1048576(%esi), %al
	jne	.L86
	movl	%edi, %edx
	movb	%al, 1050624(%edi)
	incl	%edi
	movl	-56(%ebp), %eax
	subl	%esi, %eax
	movl	%eax, 1050880(,%edx,4)
.L86:
	incl	%esi
	jmp	.L85
.L107:
	xorl	%eax, %eax
.L88:
	cmpl	%edi, %eax
	jge	.L108
	movb	$1, 1052672(%eax)
	incl	%eax
	jmp	.L88
.L108:
	movb	1051904, %al
	movb	%al, 1052672(%edi)
	leal	1(%edi), %eax
	movl	%eax, -56(%ebp)
	leal	(%edi,%edi), %eax
	movl	%eax, -28(%ebp)
	xorl	%ecx, %ecx
	movl	$1, %esi
.L90:
	cmpl	-16(%ebp), %esi
	jge	.L92
	movl	-56(%ebp), %eax
	addl	%ecx, %eax
	movl	%eax, -60(%ebp)
	xorl	%ebx, %ebx
.L93:
	cmpl	%edi, %ebx
	jge	.L109
	movzbl	1052672(%ebx,%ecx), %edx
	movl	%ecx, -76(%ebp)
	movzbl	1050624(%ebx), %eax
	call	gf_mul
	movl	-60(%ebp), %ecx
	movb	%al, 1052672(%ebx,%ecx)
	incl	%ebx
	movl	-76(%ebp), %ecx
	jmp	.L93
.L109:
	movb	1051904(%esi), %al
	movl	-28(%ebp), %ebx
	movb	%al, 1052673(%ebx)
	incl	%esi
	movl	-56(%ebp), %eax
	addl	%eax, -28(%ebp)
	movl	-60(%ebp), %ecx
	jmp	.L90
.L92:
	movl	$1052416, %ecx
	movl	%edi, %edx
	movl	-16(%ebp), %eax
	call	gauss_solve.constprop.2
	xorl	%eax, %eax
.L94:
	cmpl	%edi, %eax
	jge	.L77
	movl	1050880(,%eax,4), %edx
	movb	1052416(%eax), %cl
	xorb	%cl, 1052160(%edx)
	incl	%eax
	jmp	.L94
.L79:
	movb	1052160(%eax), %dl
	movl	%eax, %ecx
	sall	$9, %ecx
	movl	-52(%ebp), %esi
	movb	%dl, (%esi,%ecx)
	incl	%eax
	cmpl	-20(%ebp), %eax
	jl	.L79
	jmp	.L66
.L52:
	addl	$64, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.size	grub_reed_solomon_recover, .-grub_reed_solomon_recover
	.section	.note.GNU-stack,"",@progbits
