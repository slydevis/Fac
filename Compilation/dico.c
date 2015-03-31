#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dico.h"
#include "util.h"

int contexte = C_VARIABLE_GLOBALE;
int adresseArgumentCourant;
int adresseLocaleCourante;

int getParamNumber(n_dec* n) {
    if(n->u.foncDec_.param == NULL) return 0;

    int i = 0;
    n_l_dec* param = n->u.foncDec_.param;

    while(param != NULL) {
        param = param->queue;
        ++i;
    }

    return i;
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
   symbole_l_dec(n->variables);
   symbole_l_dec(n->fonctions); 
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
  if(n){
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
  // if(n->u.opExp_.op == plus) affiche_texte("plus", 1);
  // else if(n->u.opExp_.op == moins) affiche_texte("moins", 1);
  // else if(n->u.opExp_.op == fois) affiche_texte("fois", 1);
  // else if(n->u.opExp_.op == divise) affiche_texte("divise", 1);
  // else if(n->u.opExp_.op == egal) affiche_texte("egal", 1);
  // else if(n->u.opExp_.op == diff) affiche_texte("diff", 1);
  // else if(n->u.opExp_.op == inf) affiche_texte("inf", 1);
  // else if(n->u.opExp_.op == infeg) affiche_texte("infeg", 1);
  // else if(n->u.opExp_.op == ou) affiche_texte("ou", 1);
  // else if(n->u.opExp_.op == et) affiche_texte("et", 1);
  // else if(n->u.opExp_.op == non) affiche_texte("non", 1);  
  if( n->u.opExp_.op1 != NULL ) {
    symbole_exp(n->u.opExp_.op1);
  }
  if( n->u.opExp_.op2 != NULL ) {
    symbole_exp(n->u.opExp_.op2);
  }
}

/*-------------------------------------------------------------------------*/

void symbole_intExp(n_exp *n)
{
  //char texte[ 50 ]; // Max. 50 chiffres
  //sprintf(texte, "%d", n->u.entier);
  //affiche_element( "intExp", texte, 1);
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
    entreeFonction();
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
