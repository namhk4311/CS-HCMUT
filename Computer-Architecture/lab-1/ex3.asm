.data
	array: .space 32
	insert: .asciiz "enter 8 elements: \n"
	newline: .asciiz "\n"
	error: .asciiz "ERROR!\n"
	result: .asciiz "result: "
	comma: .asciiz ", "
	ele: .asciiz "a"
	e: .asciiz ": "
	
.text
main:
	la $s0, array
	
	li $v0, 4
	la $a0, insert
	syscall
	
	add $t0, $0, $s0
	addi $t2, $0, 0 #count
	addi $t3, $0, 1 #index
start_input:
	li $v0, 4
	la $a0, ele
	syscall
	
	add $a0, $0, $t3
	li $v0, 1
	syscall
	
	li $v0, 4
	la $a0, e
	syscall
	
	li $v0, 5
	syscall
	add $t1, $0, $v0
	
	bge $t1, 0, continue_input 
	
	li $v0, 4
	la $a0, error
	syscall
	
	j start_input
continue_input:
	sw $t1, 0($t0)
	addi $t2, $t2, 1
	beq $t2, 8, stop_input
	addi $t3, $t3, 1
	addi $t0, $t0, 4
	j start_input
stop_input:
	add $t0, $0, $s0
	jal check_array

	li $v0, 4
	la $a0, result
	syscall

	add $t0, $0, $s0
	jal print_array

end:
	li $v0, 10
	syscall
	
check_array:
	addi $t2, $0, 0
	addi $t3, $0, 0
start_check:
	lw $t1, 0($t0)
	rem $t4, $t1, 3
	beq $t4, 0, divisible
	ble $t4, 1, less_than_1_rem
	bge $t4, 2, greater_than_2_rem 
 divisible:
 	div $t1, $t1, 3
 	addi $t1, $t1, 1		
 	
 	j continue_check
 less_than_1_rem:
 	addi $t1, $t1, -1
 	j continue_check
 greater_than_2_rem:
 	addi $t1, $t1, 1	
 	
 continue_check:
 	sw $t1, 0($t0)
	addi $t2, $t2, 1
	beq $t2, 8, end_check
	addi $t0, $t0, 4
	j start_check
end_check:
	jr $ra
	
	
print_array:
	addi $t2, $0, 0
loop_print:
	lw $t1, 0($t0)
	
	add $a0, $0, $t1
	li $v0, 1
	syscall
	
	addi $t2, $t2, 1
	beq $t2, 8, end_print
	
	li $v0, 4
	la $a0, comma
	syscall
	
	addi $t0, $t0, 4 
	j loop_print
end_print:
	jr $ra
	
	