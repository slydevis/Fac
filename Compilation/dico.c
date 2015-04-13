#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dico.h"
#include "util.h"

int contexte = C_VARIABLE_GLOBALE;
int adresseArgumentCourant;
int adresseLocaleCourante;
char* yyout = NULL;

int getParamNumber(n_dec* n) {
    int i = 0;
    n_l_dec* param = n->u.foncDec_.param;

    while(param != NULL) {
        param = param->queue;
        ++i;
    }

    return i;
}

/*-------------------------------------------------------------------------*/

void ecrireFichier(char* str, char* commentaire) {
    FILE* fic = NULL;

    fic = fopen(yyout, "a+");

    if(fic != NULL) {
        fputs(str, fic);

        if(commentaire != NULL) {
            fputs("\t\t# ", fic);
            fputs(commentaire, fic);
        }

        fputc('\n', fic);
        fclose(fic);
    }
    else {
        printf("Impossible d'ouvrir le fichier de sortie\n");
        exit(-1);
    }
}

/*------------------------------------------------------------------------*/

void printGlobalVariable() {
    FILE* fic = fopen(yyout, "a+");

    int cpt = 0;
    if(fic != NULL) {
      int i;
      for(i = 0; i < dico.sommet; i++){
            if(dico.tab[i].classe == C_VARIABLE_GLOBALE) {
                if(dico.tab[i].type == T_ENTIER) {
                    char* str = malloc(sizeof(char)*100);
                    sprintf(str, "%s:\t.space 4\n", dico.tab[i].identif);
                    fputs(str, fic);
                    free(str);  
                    cpt++;
                }
                else if(dico.tab[i].type == T_TABLEAU_ENTIER) {
                    char* str = malloc(sizeof(char)*100);
                    sprintf(str, "%s:\t.space %d\n", dico.tab[i].identif, 4*dico.tab[i].complement);
                    fputs(str, fic);
                    free(str);
                    cpt++;
                }
            }
        }

        fclose(fic);
    }

    if(cpt != 0)
        ecrireFichier("", NULL);
}

/*------------------------------------------------------------------------*/

void copyFile(char* source, char* dest) {
    FILE* fileDest = fopen(dest, "a+");
    FILE* fileSource = fopen(source, "r");

    char carac;
    if(fileSource != NULL) {
       if(fileDest != NULL) {
            do {
                carac = fgetc(fileSource);
               if(carac == EOF) break;
                fputc(carac, fileDest);
            } while(carac != EOF);
        }
        fclose(fileDest);
        fclose(fileSource);
        remove(source);
    }
}

/*-------------------------------------------------------------------------*/

void createLibelle(char* str) {
    char* buff = malloc(sizeof(char)*100);
    sprintf(buff, "%s:", str);
    ecrireFichier(buff, NULL);
    free(buff);    
}

/*-------------------------------------------------------------------------*/

void li(char* reg, int val, char* commentaire);
void subu(char* regDest, char* reg1, char* reg2, char* commentaire);
void subi(char* regDest, char* reg, int value, char* commentaire);
void addu(char* regDest, char* reg1, char* reg2, char* commentaire);
void addi(char* reg, char* reg2, int val, char* commentaire);
void sw(char* reg, char* adr, char* commentaire);
void lw(char* reg, char* adr, char* commentaire);
void divMIPS(char* regDest, char* reg1, char* reg2, char* commentaire);
void mult(char* regDest, char* reg1, char* reg2, char* commentaire);
void jal(char* label, char* commentaire);
void move(char* reg, char* adr, char* commentaire);

/*-------------------------------------------------------------------------*/

void empiler(char* reg) {
    char* commentaire = malloc(sizeof(char)*100);
    sprintf(commentaire, "empile registre : %s", reg);
    subi("$sp", "$sp", 4, commentaire);
    sw(reg, "$sp", NULL);
    free(commentaire);
}

/*-------------------------------------------------------------------------*/

void depiler(char* reg) { 
    char* commentaire = malloc(sizeof(char)*100);
    sprintf(commentaire, "depile vers registre : %s", reg);
    lw(reg, "$sp", commentaire);
    addi("$sp", "$sp", 4, NULL);
    free(commentaire);
}

/*-------------------------------------------------------------------------*/

void syscall(int valeur) {
    char* commentaire = malloc(sizeof(char)*100);

    switch(valeur) {
        case 1:
            sprintf(commentaire, "print_int 1 integer $a0");
            break;
        case 4:
            sprintf(commentaire, "print_string 4 $a0");
            break;
        case 5:
            sprintf(commentaire, "read_int 5 integer (in $v0)");
            break;
        case 8:
            sprintf(commentaire, "read_string 8 buf $a0, buflen $a1");
            break;
        case 9:
            sprintf(commentaire, "sbrk 9 amount $a address (in $v0)");
            break;
        case 10:
            sprintf(commentaire, "stoppe l'execution du processus");
            break;
        case 11:
            sprintf(commentaire, "ecrire char");
            break;
        default:
            commentaire = NULL;
            break;
    }

    li("$v0", valeur, NULL);
    ecrireFichier("\tsyscall", commentaire);
}

/*-------------------------------------------------------------------------*/

void liWitchChar(char* reg, char* car, char* commentaire) {
    char* buff = malloc(sizeof(char)*100);
    sprintf(buff, "\tli %s, '%s'", reg, car);
    ecrireFichier(buff, commentaire);
    free(buff);
}

/*-------------------------------------------------------------------------*/

void li(char* reg, int val, char* commentaire) {
    char* buff = malloc(sizeof(char)*100);
    sprintf(buff, "\tli %s, %d", reg, val);
    ecrireFichier(buff, commentaire);
    free(buff);
}

/*-------------------------------------------------------------------------*/

void subu(char* regDest, char* reg1, char* reg2, char* commentaire) {
    char* buff = malloc(sizeof(char)*100);
    sprintf(buff, "\tsub %s %s %s", regDest, reg1, reg2);
    ecrireFichier(buff, commentaire);
    free(buff);
}

/*-------------------------------------------------------------------------*/

void subi(char* regDest, char* reg, int value, char* commentaire) {
    char* buff = malloc(sizeof(char)*100);
    sprintf(buff, "\tsubi %s %s %d", regDest, reg, value);
    ecrireFichier(buff, commentaire);
    free(buff);
}

/*-------------------------------------------------------------------------*/

void sw(char* reg, char* adr, char* commentaire) {
    char* buff = malloc(sizeof(char)*100);
    sprintf(buff, "\tsw %s 0(%s)", reg, adr);
    ecrireFichier(buff, commentaire);
    free(buff);
}

/*-------------------------------------------------------------------------*/

void addu(char* regDest, char* reg1, char* reg2, char* commentaire) {
    char* buff = malloc(sizeof(char)*100);
    sprintf(buff, "\tadd %s %s %s", regDest, reg1, reg2);
    ecrireFichier(buff, commentaire);
    free(buff);
}

/*-------------------------------------------------------------------------*/

void addi(char* reg, char* reg2, int val, char* commentaire) {
    char* buff = malloc(sizeof(char)*100);
    sprintf(buff, "\taddi %s %s %d", reg, reg2, val);
    ecrireFichier(buff, commentaire);
    free(buff);
}

/*-------------------------------------------------------------------------*/

void lw(char* reg, char* adr, char* commentaire) {
    char* buff = malloc(sizeof(char)*100);
    sprintf(buff, "\tlw %s 0(%s)", reg, adr);
    ecrireFichier(buff, commentaire);
    free(buff);
}

/*-------------------------------------------------------------------------*/

void divMIPS(char* regDest, char* reg1, char* reg2, char* commentaire) {
    char* buff = malloc(sizeof(char)*100);
    sprintf(buff, "\tdiv %s %s %s", regDest, reg1, reg2);
    ecrireFichier(buff, commentaire);
    free(buff);
}

/*-------------------------------------------------------------------------*/

void mult(char* regDest, char* reg1, char* reg2, char* commentaire) {
    char* buff = malloc(sizeof(char)*100);
    sprintf(buff, "\tdiv %s %s %s", regDest, reg1, reg2);
    ecrireFichier(buff, commentaire);
    free(buff);
}

/*-------------------------------------------------------------------------*/

void jal(char* label, char* commentaire) {
    char* buff = malloc(sizeof(char)*100);
    sprintf(buff, "\tjal %s", label);
    ecrireFichier(buff, commentaire);
    free(buff);
}

/*-------------------------------------------------------------------------*/

void jr(char* reg, char* commentaire) {
    char* buff = malloc(sizeof(char)*100);
    sprintf(buff, "\tjr %s", reg);
    ecrireFichier(buff, commentaire);
    free(buff);
}

/*-------------------------------------------------------------------------*/

void move(char* reg, char* adr, char* commentaire) {
    char* buff = malloc(sizeof(char)*100);
    sprintf(buff, "\tmove %s, %s", reg, adr);
    ecrireFichier(buff, commentaire);
    free(buff);
}
 
/*-------------------------------------------------------------------------*/

void entreeFonction(void){
  dico.base = dico.sommet;
  contexte = C_VARIABLE_LOCALE;
  adresseLocaleCourante = 0;
  adresseArgumentCourant = 0;
}

/*-------------------------------------------------------------------------*/

void sortieFonction(void){
  dico.sommet = dico.base;
  dico.base = 0;
  contexte = C_VARIABLE_GLOBALE;  
}

/*-------------------------------------------------------------------------*/

int getMain() {
    int i;
    for(i=0; i < dico.sommet; i++){
        if(dico.tab[i].type == T_FONCTION) {
            if(strcmp(dico.tab[i].identif, "main")  == 0)
                return i;
        }
    }   

    printf("Error : Fonction main inexistante !\n");
    exit(-1);
}

/*-------------------------------------------------------------------------*/

int ajouteIdentificateur(char *identif, int classe, int type, int adresse, int complement)
{
  dico.tab[dico.sommet].identif = strdup(identif);
  dico.tab[dico.sommet].classe = classe;
  dico.tab[dico.sommet].type = type;
  dico.tab[dico.sommet].adresse = adresse;
  dico.tab[dico.sommet].complement = complement;
  dico.sommet++;

  if(dico.sommet == maxDico){
    fprintf(stderr, "attention, plus de place dans le dictionnaire des \
                     identificateurs, augmenter maxDico\n");
    exit(1);
  }
 /* affiche_dico(); */
  return dico.sommet - 1;
}

/*-------------------------------------------------------------------------*/

int rechercheExecutable(char *identif)
{
  int i;
  for(i = dico.sommet - 1; i >= 0; i--){
    if(!strcmp(identif, dico.tab[i].identif))
      return i;
  }
  return -1;
}

/*-------------------------------------------------------------------------*/

int rechercheDeclarative(char *identif)
{
  int i;
  for(i = dico.base; i < dico.sommet; i++){
    if(!strcmp(identif, dico.tab[i].identif))
      return i;
  }
  return -1;
}

/*-------------------------------------------------------------------------*/

void affiche_dico(void)
{
  int i;
  printf("------------------------------------------\n");
  printf("base = %d\n", dico.base);
  printf("sommet = %d\n", dico.sommet);
  for(i=0; i < dico.sommet; i++){
    printf("%d ", i);
    printf("%s ", dico.tab[i].identif);
    if(dico.tab[i].classe == C_VARIABLE_GLOBALE)
      printf("GLOBALE ");
    else
    if(dico.tab[i].classe == C_VARIABLE_LOCALE)
      printf("LOCALE ");
    else
    if(dico.tab[i].classe == C_ARGUMENT)
      printf("ARGUMENT ");

    if(dico.tab[i].type == T_ENTIER)
      printf("ENTIER ");
    else if(dico.tab[i].type == T_TABLEAU_ENTIER)
      printf("TABLEAU ");
/*     else if(dico.tab[i].type == _ARGUMENT) */
/*       printf("ARGUMENT "); */
    else if(dico.tab[i].type == T_FONCTION)
      printf("FONCTION ");
    
    printf("%d ", dico.tab[i].adresse);
    printf("%d\n", dico.tab[i].complement);
  }
  printf("------------------------------------------\n");
}

void symbole_n_prog(n_prog *n);
void symbole_l_instr(n_l_instr *n);
void symbole_instr(n_instr *n);
void symbole_instr_si(n_instr *n);
void symbole_instr_tantque(n_instr *n);
void symbole_instr_faire(n_instr *n);      /* MODIFIE POUR EVAL */
void symbole_instr_pour(n_instr *n);       /* MODIFIE POUR EVAL */
void symbole_instr_affect(n_instr *n);
void symbole_instr_appel(n_instr *n);
void symbole_instr_retour(n_instr *n);
void symbole_instr_ecrire(n_instr *n);
void symbole_l_exp(n_l_exp *n);
void symbole_exp(n_exp *n);
void symbole_varExp(n_exp *n);
void symbole_opExp(n_exp *n);
void symbole_intExp(n_exp *n);
void symbole_lireExp(n_exp *n);
void symbole_appelExp(n_exp *n);
void symbole_l_dec(n_l_dec *n);
void symbole_dec(n_dec *n);
void symbole_foncDec(n_dec *n);
void symbole_varDec(n_dec *n);
void symbole_tabDec(n_dec *n);
void symbole_var(n_var *n);
void symbole_var_simple(n_var *n);
void symbole_var_indicee(n_var *n);
void symbole_appel(n_appel *n);

/*-------------------------------------------------------------------------*/

void symbole_n_prog(n_prog *n)
{
    if(yyout == NULL)
      yyout = malloc(sizeof(char)*100);

    sprintf(yyout, "%s.out", yyin2);

    symbole_l_dec(n->variables);
    symbole_l_dec(n->fonctions); 

    depiler("$ra");
    depiler("$fp");
    jr("$ra", NULL);

    sprintf(yyout, "%s.mips", yyin2);

    ecrireFichier("\t.data", NULL);
    printGlobalVariable();

    ecrireFichier("\t.text", NULL);
    createLibelle("__start");
    
    jal(dico.tab[getMain()].identif, NULL);
    
    syscall(10);

    char* source = malloc(sizeof(char)*100);
    sprintf(source, "%s.out", yyin2);
    copyFile(source, yyout);

    free(source);
    free(yyout);
}

/*-------------------------------------------------------------------------*/

void symbole_l_instr(n_l_instr *n)
{
  if(n){
    symbole_instr(n->tete);
    symbole_l_instr(n->queue);
  }
}

/*-------------------------------------------------------------------------*/

void symbole_instr(n_instr *n)
{
    if(n) {
        if(n->type == blocInst) symbole_l_instr(n->u.liste);
        else if(n->type == affecteInst) symbole_instr_affect(n);
        else if(n->type == siInst) symbole_instr_si(n);
        else if(n->type == tantqueInst) symbole_instr_tantque(n);
        else if(n->type == faireInst) symbole_instr_faire(n);
        else if(n->type == pourInst) symbole_instr_pour(n);    
        else if(n->type == appelInst) symbole_instr_appel(n);
        else if(n->type == retourInst) symbole_instr_retour(n);
        else if(n->type == ecrireInst) symbole_instr_ecrire(n);
    }
}

/*-------------------------------------------------------------------------*/

void symbole_instr_si(n_instr *n)
{  
  symbole_exp(n->u.si_.test);
  symbole_instr(n->u.si_.alors);
  if(n->u.si_.sinon){
    symbole_instr(n->u.si_.sinon);
  }
}

/*-------------------------------------------------------------------------*/

void symbole_instr_tantque(n_instr *n)
{
  symbole_exp(n->u.tantque_.test);
  symbole_instr(n->u.tantque_.faire);
}

/*-------------------------------------------------------------------------*/

void symbole_instr_faire(n_instr *n)          /* MODIFIE POUR EVAL */
{                                             /* MODIFIE POUR EVAL */
  symbole_instr(n->u.faire_.faire);           /* MODIFIE POUR EVAL */
  symbole_exp(n->u.faire_.test);              /* MODIFIE POUR EVAL */
}                                             /* MODIFIE POUR EVAL */

/*-------------------------------------------------------------------------*/

void symbole_instr_pour(n_instr *n)                /* MODIFIE POUR EVAL */
{                                                  /* MODIFIE POUR EVAL */
  symbole_instr(n->u.pour_.init);                  /* MODIFIE POUR EVAL */
  symbole_exp(n->u.pour_.test);                    /* MODIFIE POUR EVAL */
  symbole_instr(n->u.pour_.faire);                 /* MODIFIE POUR EVAL */
  symbole_instr(n->u.pour_.incr);                  /* MODIFIE POUR EVAL */
}                                                  /* MODIFIE POUR EVAL */

/*-------------------------------------------------------------------------*/

void symbole_instr_affect(n_instr *n)
{
    symbole_var(n->u.affecte_.var);
    symbole_exp(n->u.affecte_.exp);

    depiler("$t1");
    sw("$t1", n->u.affecte_.var->nom, NULL);
    lw("$t1", n->u.affecte_.var->nom, "lit variable dans $t1");
    empiler("$t1");
}

/*-------------------------------------------------------------------------*/

void symbole_instr_appel(n_instr *n)
{
    symbole_appel(n->u.appel);
}

/*-------------------------------------------------------------------------*/

void symbole_appel(n_appel *n)
{
  // affiche_texte( n->fonction, 1);
 
  int res = rechercheExecutable(n->fonction);
  
  if(res < 0) {
    printf("Erreur : Fonction %s non déclaré\n", n->fonction);
    exit(-1);
  }

  symbole_l_exp(n->args);
}

/*-------------------------------------------------------------------------*/

void symbole_instr_retour(n_instr *n)
{
  symbole_exp(n->u.retour_.expression);
}

/*-------------------------------------------------------------------------*/

void symbole_instr_ecrire(n_instr *n)
{
  symbole_exp(n->u.ecrire_.expression);

  depiler("$a0");
  syscall(1);
  liWitchChar("$a0", "\\n", NULL);
  syscall(11);
}

/* -------------------------------------------------------------------------*/

void symbole_l_exp(n_l_exp *n)
{
  if(n){
    symbole_exp(n->tete);
    symbole_l_exp(n->queue);
  }
}

/*-------------------------------------------------------------------------*/

void symbole_exp(n_exp *n)
{
  if(n->type == varExp) symbole_varExp(n);
  else if(n->type == opExp) symbole_opExp(n);
  else if(n->type == intExp) symbole_intExp(n);
  else if(n->type == appelExp) symbole_appelExp(n);
  else if(n->type == lireExp) symbole_lireExp(n);
}

/*-------------------------------------------------------------------------*/

void symbole_varExp(n_exp *n)
{
  symbole_var(n->u.var);
}

/*-------------------------------------------------------------------------*/

void symbole_opExp(n_exp *n)
{
  depiler("$t0");
  depiler("$t1");

  symbole_exp(n->u.opExp_.op1);
  if( n->u.opExp_.op2 != NULL ) {
      if(n->u.opExp_.op == plus)
        addu("$t0", "$t0", "$t1", NULL);
      else if(n->u.opExp_.op == moins)
        subu("$t0", "$t0", "$t1", NULL);
      else if(n->u.opExp_.op == divise)
        divMIPS("$t0", "$t0", "$t1", NULL);
      else if(n->u.opExp_.op == fois)
        mult("$t0", "$t0", "$t1", NULL);

      symbole_exp(n->u.opExp_.op2);
  }
  
  empiler("$t0");
}

/*-------------------------------------------------------------------------*/

void symbole_intExp(n_exp *n)
{
    li("$t0", n->u.entier, NULL);
    empiler("$t0");
}

/*-------------------------------------------------------------------------*/

// TODO : Peut être supprimer cette fonction si rien est fait ici
void symbole_lireExp(n_exp *n) {}

/*-------------------------------------------------------------------------*/

void symbole_appelExp(n_exp *n)
{
  symbole_appel(n->u.appel);
}

/*-------------------------------------------------------------------------*/

void symbole_l_dec(n_l_dec *n)
{
  if(n){
    symbole_dec(n->tete);
    symbole_l_dec(n->queue);
  }
}

/*-------------------------------------------------------------------------*/

void symbole_dec(n_dec *n)
{

  if(n){
    if(n->type == foncDec) {
      symbole_foncDec(n);
    }
    else if(n->type == varDec) {
      symbole_varDec(n);
    }
    else if(n->type == tabDec) { 
      symbole_tabDec(n);
    }
  }
}

/*-------------------------------------------------------------------------*/

void symbole_foncDec(n_dec *n)
{
    int i; // Why it isn't not in c99 ? u_u

    for(i = 0; i < dico.sommet; ++i) {
        if(dico.tab[i].type == T_FONCTION) {
            if(strcmp(n->nom, dico.tab[i].identif) == 0) {
                printf("Error : La fonction %s est déjà déclaré !\n", n->nom);
                exit(-1);
            }
        }
    }

    i = getParamNumber(n);
    
    ajouteIdentificateur(n->nom, C_VARIABLE_GLOBALE, T_FONCTION, dico.sommet, i);

    createLibelle(n->nom);

    entreeFonction();
    empiler("$fp");
    move("$fp", "$sp", NULL);
    empiler("$ra");
    symbole_l_dec(n->u.foncDec_.param);
    symbole_l_dec(n->u.foncDec_.variables);
    symbole_instr(n->u.foncDec_.corps);
    sortieFonction();
}

/*-------------------------------------------------------------------------*/

void symbole_varDec(n_dec *n)
{
    int i;
    for(i = dico.base; i < dico.sommet; ++i) {
        if(strcmp(n->nom, dico.tab[i].identif) == 0) {
            printf("Error : La variable %s est déjà déclaré dans une même porté\n", n->nom);
            exit(-1);
        }
    }

    ajouteIdentificateur(n->nom, contexte, T_ENTIER, adresseLocaleCourante, 0);
    adresseLocaleCourante++;

    //affiche_element("varDec", n->nom, 1);
}

/*-------------------------------------------------------------------------*/

void symbole_tabDec(n_dec *n)
{
  int i;
    for(i = dico.base; i < dico.sommet; ++i) {
        if(strcmp(n->nom, dico.tab[i].identif) == 0) {
            printf("Error : Le tableau %s est déjà déclaré\n", n->nom);
            exit(-1);
        }
    }

    if(contexte == C_VARIABLE_LOCALE) {
        printf("Error : Un tableau ne peux être déclaré en local pour %s\n", n->nom);
        exit(-1);
    }

    ajouteIdentificateur(n->nom, C_VARIABLE_GLOBALE, T_TABLEAU_ENTIER, dico.sommet, n->u.tabDec_.taille);
    adresseLocaleCourante++;
}

/*-------------------------------------------------------------------------*/

void symbole_var(n_var *n)
{
  if(n->type == simple) {
    symbole_var_simple(n);
  }
  else if(n->type == indicee) {
    symbole_var_indicee(n);
  }
}

/*-------------------------------------------------------------------------*/

void symbole_var_simple(n_var *n)
{
    int res = rechercheExecutable(n->nom);
 
    if(res < 0) {
        printf("La variable %s n'est pas daclaré\n", n->nom);
        exit(-1);
    }
  //affiche_element("var_simple", n->nom, 1);
}

/*-------------------------------------------------------------------------*/

void symbole_var_indicee(n_var *n)
{
  //affiche_element("var_base_tableau", n->nom, 1);
  int res = rechercheExecutable(n->nom);
  
  if(res < 0) {
    printf("Error : %s non déclaré\n", n->nom);
    exit(-1);
  }

  symbole_exp( n->u.indicee_.indice );
}

/*-------------------------------------------------------------------------*/