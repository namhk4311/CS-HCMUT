.data 
	array: .space 60
	count_arr: .space 60
	insert: .asciiz "enter 15 elements: \n"
	newline: .asciiz "\n"
	error: .asciiz "ERROR!\n"
	result: .asciiz "result: "
	comma: .asciiz ", "
	ele: .asciiz "a"
	e: .asciiz ": "
.text
	la $s0, array
	la $s1, count_arr
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
	
continue_input:
	sw $t1, 0($t0)
	addi $t2, $t2, 1
	beq $t2, 15, stop_input
	addi $t3, $t3, 1
	addi $t0, $t0, 4
	j start_input
stop_input:
	add $t0, $0, $s0
	addi $t2, $0, 0 #count
	addi $t3, $0, 10000 #min value
	jal findmin
	
	add $t0, $0, $s0
	addi $t2, $0, 0 #count
	addi $t4, $0, 10000
	addi $t6, $0, 0 #count cout_arr
	add $t8, $0, $s1
	jal findsecondmin
	
	
	add $a0, $0, $t4
	li $v0, 1
	syscall
	
	li $v0, 4
	la $a0, newline
	syscall
	jal print_array

	
end_program:
	li $v0, 10
	syscall

findmin:
	lw $t1, 0($t0)
	bgt $t3, $t1, update
continue_find:	
	addi $t2, $t2, 1
	beq $t2, 15, end_find
	addi $t0, $t0, 4
	j findmin
end_find:
	jr $ra
	
update:
	add $t3, $0, $t1
	j continue_find
	
findsecondmin:
	lw $t1, 0($t0)
	bge $t4, $t1, update2

continue_find2:	
	addi $t2, $t2, 1
	beq $t2, 15, end_find
	addi $t0, $t0, 4
	j findmin
end_find2:
	jr $ra
	
update2:
	bgt $t1, $t3, out
	sw $t2, 0($t8)
	addi $t6, $t6, 1 
	addi $t8, $t8, 4
out:
	j continue_find2
	
print_array:
	addi $t2, $0, 0
loop_print:
	lw $t5, 0($s1)
	
	add $a0, $0, $t5
	li $v0, 1
	syscall
	
	addi $t2, $t2, 1
	beq $t2, $t6, end_print
	
	li $v0, 4
	la $a0, comma
	syscall
	
	addi $s1, $s1, 4 
	j loop_print
end_print:
	jr $ra
