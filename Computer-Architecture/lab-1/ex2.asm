.data
	input_a: .asciiz "input a: "
	input_b: .asciiz "input b: "
	result_GCD: .asciiz "GCD: "
	result_LCM: .asciiz "LCM: "
	newline: .asciiz "\n"
	error: .asciiz "Error!\n"
.text
main:
input_a_again:
	li $v0, 4
	la $a0, input_a
	syscall
	
	li $v0, 5
	syscall
	add $s0, $0, $v0
	bge $s0, 0, continue1
	
	li $v0, 4
	la $a0, error
	syscall
	
	j input_a_again
continue1:
	li $v0, 4
	la $a0, input_b
	syscall
	
	li $v0, 5
	syscall
	add $s1, $0, $v0
	bge $s1, 0, continue2
	
	li $v0, 4
	la $a0, error
	syscall
	
	j continue1
continue2: 
	jal GCD
	
	li $v0, 4
	la $a0, result_GCD
	syscall

	add $a0, $0, $s3
	li $v0, 1
	syscall	
	
	li $v0, 4
	la $a0, newline
	syscall
	
	jal LCM
	
	li $v0, 4
	la $a0, result_LCM
	syscall		
	
	add $a0, $0, $s4
	li $v0, 1
	syscall
	
end:
	li $v0, 10
	syscall

GCD:
	addi $sp, $sp, -8
	sw $s0, 0($sp)
	sw $s1, 4($sp)
loop_GCD:	
	beq $s1, 0, end_loop_GCD
	add $s2, $0, $s0
	add $s0, $0, $s1
	rem $s1, $s2, $s1
	j loop_GCD
end_loop_GCD:
	add $s3, $0, $s0
	lw $s0, 0($sp)
	lw $s1, 4($sp)
	addi $sp, $sp, 8	
	jr $ra
	
LCM:
	mul $s4, $s0, $s1
	div $s4, $s4, $s3
	jr $ra		
