incr(entier $a)
{retour $a+1;}
main()
entier $b;
{
$b = incr(1);
}

# .text
# start: 
#    jal main
#    li $v0 10
#    syscall
# main:
#    subu $sp $sp 4
#    sw $fp 0($sp)
#    move $fp $sp
#    subu $sp $sp 4
#    sw $ra 0($sp)
#    subu $sp $sp 4
#    subu $sp $sp 4
#    li $t0 1
#    subu $sp $sp 4
#    sw $to $sp
#    jal iner
#    addu $sp $sp 4
#    lw $t0
#    addu $sp $sp 4
#    sw $t0 $fp -8($sp)
#    addu $sp $sp 4
#    lw $ra $sp
#    addu $sp $sp 4

# TODO : 
# 1) générer des commentaires
# 2) écrire les fonctions   empile(char* reg)
#                           depile(char* reg)
# 3) Variable globale etiquettecourante = 0
# 4) fonction nouvelle_etiquette()
# 5) syscall(int v0)
# 6) asm_arith(char *operation)

