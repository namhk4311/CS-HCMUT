.data
	array: .space 40
	dup_arr: .space 40
	unique_arr: .space 40
	repeat: .space 40
	insert: .asciiz "enter 10 elements: \n"
	newline: .asciiz "\n"
	error: .asciiz "ERROR!\n"
	result: .asciiz "result: "
	comma: .asciiz ", "
	ele: .asciiz "a"
	e: .asciiz ": "
	flag: .asciiz "xxxx"
	unique_print: .asciiz "Unique values: "
	dup_print: .asciiz ". Duplicated value: "
	rep_print: .asciiz "repeated "
	times: .asciiz " times"
	semi: .asciiz "; "
	dot: .asciiz "."
.text
main:
	la $s0, array
	la $s1, unique_arr
	la $s2, dup_arr
	la $s3, repeat
	la $a1, flag
	
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
	beq $t2, 10, stop_input
	addi $t3, $t3, 1
	addi $t0, $t0, 4
	j start_input
stop_input:
	add $t0, $0, $s0 #array
	add $s5, $0, $s1 #unique
	add $s6, $0, $s2 #dup	
	add $s7, $0, $s3 #repeat
	addi $t2, $0, 0 #count
	
	addi $t8, $0, 0 #count_unique
	addi $t9, $0, 0 #count_dup
	jal check_unique
	
	add $s5, $0, $s1 #unique
	add $s6, $0, $s2 #dup	
	add $s7, $0, $s3 #repeat
	
	
	
	li $v0, 4
	la $a0, unique_print
	syscall
print_unique:
	addi $t2, $0, 0
	beq $t8, 0, stop_u
start_u:
	lw $t1, 0($s5)
	
	add $a0, $0, $t1
	li $v0, 1
	syscall
	
	addi $t2, $t2, 1
	beq $t2, $t8, stop_u
	addi $s5, $s5, 4
	li $v0, 4
	la $a0, comma
	syscall
	
	j start_u
stop_u:
	li $v0, 4
	la $a0, dup_print
	syscall
print_dup:
	addi $t2, $0, 0
	addi $t7, $t9, -1
	beq $t9, 0, end_program
start_dup:
	lw $t1, 0($s6)
	lw $t3, 0($s7)
	
	add $a0, $0, $t1
	li $v0, 1
	syscall
	
	li $v0, 4
	la $a0, comma
	syscall
	
	li $v0, 4
	la $a0, rep_print
	syscall
	
	add $a0, $0, $t3
	li $v0, 1
	syscall
	
	li $v0, 4
	la $a0, times
	syscall
	
	
	addi $t2, $t2, 1
	beq $t2, $t9, stop_dup
	
	
	addi $s6, $s6, 4
	addi $s7, $s7, 4
	
	beq $t2, $t7, stop_print_semi
	li $v0, 4
	la $a0, semi
	syscall
stop_print_semi:
	j start_dup
stop_dup:
	li $v0, 4
	la $a0, dot
	syscall
	
end_program:
	li $v0, 10
	syscall
	
check_unique:
	addi $sp, $sp, -8
	sw $t6, 0($sp)
	sw $t7, 4($sp)
	
	addi $t2, $0, 0 #index i
start_check_u:
	addi $t3, $0, 1 #check appear
	add $t4, $0, $t0 
	lw $t1, 0($t4)
	beq $t1, $a1, next
	add $t5, $0, $t2 #index j
loop_check_u:
	addi $t4, $t4, 4
	addi $t5, $t5, 1
	beq $t5, 10, end_loop_u
	lw $t6, 0($t4)
	bne $t6, $t1, continue_check_u
	addi $t3, $t3, 1 #increase appear
	sw $a1, 0($t4)
continue_check_u:
	j loop_check_u
end_loop_u:	
	beq $t3, 1, unique_ele
	bne $t3, 1, dup_ele
next:
	addi $t2, $t2, 1
	beq $t2, 10, end_check_u	
	
	add $t0, $t0, 4
	j start_check_u
end_check_u:
	sw $t6, 0($sp)
	sw $t7, 4($sp)
	addi $sp, $sp, 8
	jr $ra
	
unique_ele:
	sw $t1, 0($s5)
	addi $s5, $s5, 4
	addi $t8, $t8, 1
	j next

dup_ele:
	sw $t1, 0($s6)
	sw $t3, 0($s7)
	addi $s6, $s6, 4
	addi $s7, $s7, 4
	addi $t9, $t9, 1
	j next
	
