.data
	array: .float 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0
	size: .word 9
	newline:.asciiz "\n"
.text
main:
	la $s0, size
	la $t0, array
	jal printRecursive
	
exit:
	li $v0, 10
	syscall
	
printRecursive:
	addi $sp, $sp, -12
	sw $t0, 0($sp)
	sw $s0, 4($sp)
	sw $ra, 8($sp)
	
	lwc1 $f1, 0($t0)
	beq $s0, 1, L1
	
	addi $t0, $t0, 4
	
	addi $s0, $s0, -1
	jal printRecursive
	
	mov.s $f12, $f1
	li $v0, 2
	syscall
	
	lw $t0, 0($sp)
	lw $s0, 4($sp)
	lw $ra, 8($sp)
	addi $sp, $sp, 12
	jr $ra	
L1:
	
	mov.s $f12, $f1
	li $v0, 2
	syscall
	
	lw $t0, 0($sp)
	lw $s0, 4($sp)
	lw $ra, 8($sp)
	addi $sp, $sp, 12
	jr $ra
	