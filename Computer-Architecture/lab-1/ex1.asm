.data
	input_string: .asciiz "abdeefggff"
	count_array: .space 1000
	result: .space 128
	count_value: .word 10
	flag: .asciiz "$"
.text
main:
	la $s0, input_string
	la $s1, count_value
	la $s2, result
	la $a1, flag
	
	add $t0, $0, $s0
	add $s5, $0, $s1
	add $s6, $0, $s2
	addi $s7, $0, 0 #count result
	lw $t1, 0($s1)
counting:
	addi $t2, $0, 0 #index i
start_counting:
	addi $t3, $0, 1 #check appear
	add $t4, $0, $t0
	lb $t5, 0($t4) #t5 compare t6
	beq $t5, $a1, next
	add $t7, $0, $t2 #index j
loop_count:
	addi $t4, $t4, 1
	add $t7, $t7, 1
	beq $t7, $t1, end_loop_count
	lb $t6, 0($t4)
	bne $t5, $t6, continue_count
	addi $t3, $t3, 1
	sb $a1, 0($t4)
continue_count:
	j loop_count
end_loop_count:
	sb $t5, 0($s5)
	sw $t3, 0($s6)
	addi $s5, $s5, 1
	addi $s6, $s6, 1
	addi $s7, $s7, 1
next:
	addi $t2, $t2, 1
	beq $t2, $t1, end_count	
	add $t0, $t0, 1
	j start_counting
end_count:
	add $t0, $0, $s0
	add $s5, $0, $s1
	add $s6, $0, $s2
	
	jal sort


end_program:
	li $v0, 10
	syscall
	
sort: 	
	
