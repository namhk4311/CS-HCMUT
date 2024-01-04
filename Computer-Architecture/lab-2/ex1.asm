.data
	shape_option: .asciiz "Shape:\n1.Rectangular box\n2.Cube\n3.Cylinder\n4.Sphere\n"
	choose_shape: .asciiz "Which SHAPE would you like to choose: "
	l: .asciiz "Length: "
	w: .asciiz "Width: "
	h: .asciiz "Height: "
	e: .asciiz "Edge: "
	r: .asciiz "Radius: "
	error: .asciiz "error!\n"
	v_or_t: .asciiz "Vomlume or Total surface area (1: Volume, 2: Total surface area): "
	const0: .float 0.0
	const2: .float 2.0
	
	const6: .float 6.0
	const4: .float 4.0
	constPi: .float 3.1415
	const4_3: .float 1.3333
	res: .asciiz "result: "
	
.text
main:
	li $v0, 4
	la $a0, shape_option
	syscall
	
	li $v0, 4
	la $a0, choose_shape
	syscall
	
	li $v0, 5
	syscall
	add $s0, $0, $v0
	
	l.s $f11, const0
	l.s $f13, const2
	l.s $f14, const6
	l.s $f15, constPi
	l.s $f16, const4_3
	l.s $f17, const4
	
	beq $s0, 1, rec
	beq $s0, 2, cube
	beq $s0, 3, cylinder
	beq $s0, 4, sphere
	
exit:
	li $v0, 10
	syscall

rec:	
l_rec:
	li $v0, 4
	la $a0, l
	syscall
	
	li $v0, 6
	syscall
	mov.s $f1, $f0
	
	c.le.s $f1, $f11
	bc1f continue_w_rec
	
	li $v0, 4
	la $a0, error
	syscall
	
	j l_rec 
continue_w_rec:
w_rec:
	li $v0, 4
	la $a0, w
	syscall
	
	li $v0, 6
	syscall
	mov.s $f2, $f0
	
	c.le.s $f2, $f11
	bc1f continue_h_rec
	
	li $v0, 4
	la $a0, error
	syscall
	
	j w_rec 
continue_h_rec:
h_rec:
	li $v0, 4
	la $a0, h
	syscall
	
	li $v0, 6
	syscall
	mov.s $f3, $f0
	
	c.le.s $f3, $f11
	bc1f continue_rec
	
	li $v0, 4
	la $a0, error
	syscall
	
	j h_rec 
continue_rec:
	
	li $v0, 4
	la $a0, v_or_t
	syscall
	
	li $v0, 5
	syscall
	add $s1, $0, $v0
	
	li $v0, 4
	la $a0, res
	syscall
	
	beq $s1, 1, vol_rec
	beq $s1, 2, tot_rec
	
vol_rec:
	mul.s $f1, $f1, $f2
	mul.s $f1, $f1, $f3
	
	mov.s $f12, $f1
	li $v0, 2
	syscall
	
	j exit	
tot_rec:
	mul.s $f4, $f1, $f2
	mul.s $f5, $f2, $f3
	mul.s $f6, $f1, $f3
	
	add.s $f4, $f4, $f5
	add.s $f4, $f4, $f6
	
	mul.s $f4, $f4, $f13
	mov.s $f12, $f4
	li $v0, 2
	syscall
	
	j exit
#===============================
cube:
e_cube:
	li $v0, 4
	la $a0, e
	syscall
	
	li $v0, 6
	syscall
	mov.s $f1, $f0
	
	c.le.s $f1, $f11
	bc1f continue_cube
	
	li $v0, 4
	la $a0, error
	syscall
	
	j e_cube 
continue_cube:
	
	li $v0, 4
	la $a0, v_or_t
	syscall
	
	li $v0, 5
	syscall
	add $s1, $0, $v0
	
	li $v0, 4
	la $a0, res
	syscall
	
	beq $s1, 1, vol_cube
	beq $s1, 2, tot_cube
	
vol_cube:
	mul.s $f2, $f1, $f1
	mul.s $f2, $f2, $f1 
	
	mov.s $f12, $f2
	li $v0, 2
	syscall
	
	j exit	
tot_cube:
	mul.s $f1, $f1, $f1
	mul.s $f1, $f1, $f14
	
	mov.s $f12, $f1
	li $v0, 2
	syscall
	
	j exit
#========================
cylinder:
r_cy:
	li $v0, 4
	la $a0, r
	syscall
	
	li $v0, 6
	syscall
	mov.s $f1, $f0
	
	c.le.s $f1, $f11
	bc1f continue_h_cy
	
	li $v0, 4
	la $a0, error
	syscall
	
	j r_cy 
continue_h_cy:
h_cy:
	li $v0, 4
	la $a0, h
	syscall
	
	li $v0, 6
	syscall
	mov.s $f2, $f0
	
	c.le.s $f2, $f11
	bc1f continue_cyl
	
	li $v0, 4
	la $a0, error
	syscall
	
	j h_cy 
continue_cyl:
	
	li $v0, 4
	la $a0, v_or_t
	syscall
	
	li $v0, 5
	syscall
	add $s1, $0, $v0
	
	li $v0, 4
	la $a0, res
	syscall
	
	beq $s1, 1, vol_cy
	beq $s1, 2, tot_cy
	
vol_cy:
	mul.s $f1, $f1, $f1
	mul.s $f1, $f1, $f2
	mul.s $f1, $f1, $f15
	
	mov.s $f12, $f1
	li $v0, 2
	syscall
	
	j exit	
tot_cy:
	add.s $f2, $f1, $f2
	mul.s $f2, $f2, $f1
	mul.s $f2, $f2, $f15
	mul.s $f2, $f2, $f13
	
	mov.s $f12, $f2
	li $v0, 2
	syscall
	
	j exit
#=================================
sphere:
r_sp:
	li $v0, 4
	la $a0, r
	syscall
	
	li $v0, 6
	syscall
	mov.s $f1, $f0
	
	c.le.s $f1, $f11
	bc1f continue_sp
	
	li $v0, 4
	la $a0, error
	syscall
	
	j r_sp 
continue_sp:
	
	li $v0, 4
	la $a0, v_or_t
	syscall
	
	li $v0, 5
	syscall
	add $s1, $0, $v0
	
	li $v0, 4
	la $a0, res
	syscall
	
	beq $s1, 1, vol_sp
	beq $s1, 2, tot_sp
	
vol_sp:
	mul.s $f2, $f1, $f1
	mul.s $f2, $f2, $f1 
	
	mul.s $f2, $f2, $f15
	mul.s $f2, $f2, $f16
	
	mov.s $f12, $f2
	li $v0, 2
	syscall
	
	j exit	
tot_sp:
	mul.s $f1, $f1, $f1
	mul.s $f1, $f1, $f15
	mul.s $f1, $f1, $f17
			
	mov.s $f12, $f1
	li $v0, 2
	syscall
	
	j exit
