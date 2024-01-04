.data:
	u_type: .asciiz "u: "
	v_type: .asciiz "v: "
	a_type: .asciiz "a: "
	b_type: .asciiz "b: "
	c_type: .asciiz "c: "
	d_type: .asciiz "d: "
	error: .asciiz "error!\n"
	const2: .float 2.0
	const1: .float 1.0
	const5: .float 5.0
	const4: .float 4.0
	const3: .float 3.0
.text:

	li $v0, 4
	la $a0, u_type
	syscall
	
	li $v0, 6
	syscall
	mov.s $f1, $f0
	
	li $v0, 4
	la $a0, v_type
	syscall
	
	li $v0, 6
	syscall
	mov.s $f2, $f0
	
	li $v0, 4
	la $a0, a_type
	syscall
	
	li $v0, 6
	syscall
	mov.s $f3, $f0
	
	li $v0, 4
	la $a0, b_type
	syscall
	
	li $v0, 6
	syscall
	mov.s $f4, $f0
	
	li $v0, 4
	la $a0, c_type
	syscall
	
	li $v0, 6
	syscall
	mov.s $f5, $f0
	
	li $v0, 4
	la $a0, d_type
	syscall
	
	li $v0, 6
	syscall
	mov.s $f6, $f0
	
	l.s $f7, const2
	mul.s $f7, $f7, $f7

	l.s $f8, const5
	l.s $f9, const4
	l.s $f10, const3
#first	
	addi $s0, $0, 5
	mov.s $f11, $f1
	jal exponent
	mov.s $f14, $f13
	
	addi $s0, $0, 5
	mov.s $f11, $f2
	jal exponent
	mov.s $f15, $f13
	
	sub.s $f14, $f14, $f15
	div.s $f14, $f14, $f8
	
#a/e2
	div.s $f16, $f3, $f7
	mul.s $f14, $f14, $f16
	mov.s $f17, $f14
#second	
	addi $s0, $0, 4
	mov.s $f11, $f1
	jal exponent
	mov.s $f14, $f13
	
	addi $s0, $0, 4
	mov.s $f11, $f2
	jal exponent
	mov.s $f15, $f13

	sub.s $f14, $f14, $f15
	div.s $f14, $f14, $f9
#b/e2
	div.s $f16, $f4, $f7
	mul.s $f14, $f14, $f16
	add.s $f17, $f17, $f14
#third
	addi $s0, $0, 3
	mov.s $f11, $f1
	jal exponent
	mov.s $f14, $f13
	
	addi $s0, $0, 3
	mov.s $f11, $f2
	jal exponent
	mov.s $f15, $f13

	sub.s $f14, $f14, $f15
	div.s $f14, $f14, $f10
#c/e2
	div.s $f16, $f5, $f7
	mul.s $f14, $f14, $f16
	add.s $f17, $f17, $f14
#forth
	addi $s0, $0, 1
	mov.s $f11, $f1
	jal exponent
	mov.s $f14, $f13
	
	addi $s0, $0, 1
	mov.s $f11, $f2
	jal exponent
	mov.s $f15, $f13

	sub.s $f14, $f14, $f15
#b/e2
	div.s $f16, $f6, $f7
	mul.s $f14, $f14, $f16
	add.s $f17, $f17, $f14

	mov.s $f12, $f17
	li $v0, 2
	syscall
	
	
#second	
	
	
exit:
	li $v0, 10
	syscall

exponent:
	l.s $f13, const1
loop_ex:
	beq $s0, 0, done_loop_ex
	mul.s $f13, $f13, $f11
	addi $s0, $s0, -1
	j loop_ex
done_loop_ex:
	jr $ra

	