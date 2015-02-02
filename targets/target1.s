	.file	"target1.c"
	.text
.globl bar
	.type	bar, @function
bar:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	strcpy
	movl	$0, %eax
	leave
	ret
	.size	bar, .-bar
.globl foo
	.type	foo, @function
foo:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$264, %esp
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	leal	-248(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	bar
	leave
	ret
	.size	foo, .-foo
	.section	.rodata
.LC0:
	.string	"target1: argc != 2\n"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$16, %esp
	cmpl	$2, 8(%ebp)
	je	.L6
	movl	stderr, %eax
	movl	%eax, %edx
	movl	$.LC0, %eax
	movl	%edx, 12(%esp)
	movl	$19, 8(%esp)
	movl	$1, 4(%esp)
	movl	%eax, (%esp)
	call	fwrite
	movl	$1, (%esp)
	call	exit
.L6:
	movl	12(%ebp), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	movl	%eax, (%esp)
	call	puts
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	foo
	movl	$0, %eax
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-4)"
	.section	.note.GNU-stack,"",@progbits
