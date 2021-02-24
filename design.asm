.global desing_level

desing_level:
    addi $sp, $sp, -4
    sw $ra, 0($sp)
    
    li $s0, 130 ; tamanioH -> se puede poner como constante con slti
    li $s1, 20 ; tamanioV -> se puede poner como constante con slti
    li $t0, 0  ; i=0
forHorizontal:
    slt $t1, $t0, $s0
    beq $t1, $zero, end_forHorizontal
    li $a0, 42
    jal print_char
    addi $t0, $t0, 1
    j forHorizontal
end_forHorizontal:
    li $a0, 10
    jal print_char

for_vertical:
    li $t0, 0 ; i=0
    
for_abajo:
    slt $t2, $t0, $s1
    beq $t2, $zero, for_abajo_horizontal
    li $a0, 42
    jal print_char
    jal print_char
    li $t1, 0 ; j=0
    for_espacios:
        slti $t2, $t1, 126
        beq $t2, $zero, end_for_espacios
        li $a0, 32
        jal print_char
        addi $t1, $t1, 1
        j for_espacios
    end_for_espacios:
    li $a0, 42
    jal print_char
    jal print_char
    
end_for_abajo:
    addi $t0, $t0, 1
    li $a0, 10
    jal print_char
    j for_abajo
    
for_abajo_horizontal:
    li $t0, 0
    
for_dentro:
    slt $t1, $t0, $s0
    beq $t1, $zero, end_desing_level
    li $a0, 42
    jal print_char
    addi $t0, $t0, 1
    j for_dentro
    
end_desing_level:
 li $a0, 10
    jal print_char
    lw $ra, 0($sp)
    addi $sp, $sp, 4
    jr $ra

; Pendiente colorear el contorno y colocar jugadores con stats
    

    
