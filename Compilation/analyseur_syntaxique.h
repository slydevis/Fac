#ifndef __ANALYSEUR_SYNTAXIQUE__
#define __ANALYSEUR_SYNTAXIQUE__

#include "symboles.h"
#include "syntabs.h"

extern int uniteCourante;

int premier[NB_NON_TERMINAUX + 1][NB_TERMINAUX + 1];
int suivant[NB_NON_TERMINAUX + 1][NB_TERMINAUX + 1];

void init();
void printError();
void printToken();

int estPremier(int nonTerm, int term);
int estSuivant(int nonTerm, int term);

n_prog* PG(int trace);
n_l_dec* ODV(void);
n_l_dec* LDF(void);
n_dec* DF(void);
n_l_dec* LP(void);
n_instr* IB(void);
n_l_dec* OLDV(void);
n_l_dec* LDV(void);
n_l_dec* LDVB(void);
n_dec* DV(void);
n_l_instr* LI(void);
int OTT(void);
n_instr* I(void);
n_var* VAR(void);
n_exp* OIND(void);
n_exp* EXP(void);
n_instr* IAFF(void);
n_instr* ISI(void);
n_instr* OSINON(void);
n_instr* ITQ(void);
n_instr* IAPP(void);
n_appel* APPF(void);
n_l_exp* LEXP(void);
n_l_exp* LEXPB(void);
n_instr* IRET(void);
n_instr* IECR(void);
n_instr* IPOUR(void);
n_instr* IVIDE(void);
n_exp* CONJ(void);
n_exp* EXPB(n_exp* conjPere);
n_exp* F(void);
n_exp* TB(n_exp* fils);
n_exp* T(void);
n_exp* CONJB(n_exp* herite); 
n_exp* NEG(void); 
n_exp* COMP(void); 
n_exp* COMPB(n_exp* herite);
n_exp* E(void);
n_exp* EB(); 

/*
 * S -> TS'
 * S' -> '|'S | EPISLON
 * T -> RT'
 * T' -> &T | EPSILON
 * R -> !R | U
 * U -> VU'
 * U' -> =U | <U | EPSILON
 * V -> WV'
 * V' -> +V | -V | EPSILON
 * W -> XW'
 * W' -> *W | /W | EPSILON
 * X -> (S) | NOMBRE | ID_VAR | APPEL_FONCTION | -X
 */

/*

void S(void);
void Sprim(void);
void T(void);
void Tprim(void);
void R(void);
void U(void);
void Uprim(void);
void V(void);
void Vprim(void);
void W(void);
void Wprim(void);
void X(void); 

*/

// Début du TP
/*
void E(void);
void T(void);
void Eprim(void);
void T(void);
void Tprim(void);
void F(void);
*/
#endif
