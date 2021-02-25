; Aqui debe ir la logica del juego, para este caso PONG

.global main

.data
player1: .byte "Player 1:   ", 0
player2: .byte "Player 2:   ", 0
.text
main:
    addi $sp, $sp, -4
    sw $ra, 0($sp)
    
    
    jal desing_level

    li $a1, 0 ; color
    li $v0, 22 ; color
    syscall ; color
    li $t1, 1 ; background
    li $v0, 20 ; background
    syscall ; background
    li $a0, player1
    jal print_str
    li $v0, 23
    syscall
    
for_main:
li $t0, 0 ; i=0
correr:
    slti $t1, $t0, 100
    beq $t1, $zero, end_for_main
    li $a0, 32
    jal print_char
    addi $t0, $t0, 1
    j correr
end_for_main:
    li $a1, 0 ; color
    li $v0, 22 ; color
    syscall ; color
    li $t1, 3 ; background
    li $v0, 20 ; background
    syscall ; background
    li $a0, player2
    jal print_str
    li $v0, 23
    syscall
    
    li $a0, 10
    jal print_char


    lw $ra, 0($sp)
    addi $sp, $sp, 4

    jr $ra
