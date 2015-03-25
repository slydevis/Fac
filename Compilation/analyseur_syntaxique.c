#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "symboles.h"
#include "analyseur_lexical.h"
#include "analyseur_syntaxique.h"
#include "syntabs.h"

int uniteCourante;

void init() {
    
    int i = 0;
    int j = 0;
    
    while(i < NB_NON_TERMINAUX) {
        while(j < NB_TERMINAUX) {
            premier[i][j] = 0;
            j++;
        }
        i++;
    }
    
    premier[_programme_][ENTIER] = 1;
    premier[_programme_][EPSILON] = 1;
    suivant[_programme_][FIN] = 1;
    
    premier[_optDecVariables_][ENTIER] = 1;
    premier[_optDecVariables_][EPSILON] = 1;
    suivant[_optDecVariables_][ID_FCT] = 1;
    suivant[_optDecVariables_][ACCOLADE_OUVRANTE] = 1;
    suivant[_optDecVariables_][FIN] = 1;
    
    premier[_listeDecVariables_][ENTIER] = 1;
    suivant[_listeDecVariables_][POINT_VIRGULE] = 1;
    suivant[_listeDecVariables_][PARENTHESE_FERMANTE] = 1;
    
    premier[_listeDecVariablesBis_][VIRGULE] = 1;
    premier[_listeDecVariablesBis_][EPSILON] = 1;
    suivant[_listeDecVariablesBis_][POINT_VIRGULE] = 1;
    suivant[_listeDecVariablesBis_][PARENTHESE_FERMANTE] = 1;
    
    premier[_declarationVariable_][ENTIER] = 1;
    suivant[_declarationVariable_][VIRGULE] = 1;
    suivant[_declarationVariable_][POINT_VIRGULE] = 1;
    suivant[_declarationVariable_][PARENTHESE_FERMANTE] = 1;
    
    premier[_optTailleTableau_][CROCHET_OUVRANT] = 1;
    premier[_optTailleTableau_][EPSILON] = 1;
    suivant[_optTailleTableau_][VIRGULE] = 1;
    suivant[_optTailleTableau_][POINT_VIRGULE] = 1;
    suivant[_optTailleTableau_][PARENTHESE_FERMANTE] = 1;
    
    premier[_listeDecFonctions_][ID_FCT] = 1;
    premier[_listeDecFonctions_][EPSILON] = 1;
    suivant[_listeDecFonctions_][FIN] = 1;
    
    premier[_declarationFonction_][ID_FCT] = 1;
    suivant[_declarationFonction_][ID_FCT] = 1;
    suivant[_declarationFonction_][FIN] = 1;
    
    premier[_listeParam_][PARENTHESE_OUVRANTE] = 1;
    suivant[_listeParam_][ENTIER] = 1;
    suivant[_listeParam_][ACCOLADE_OUVRANTE] = 1;
    
    premier[_optListeDecVariables_][ENTIER] = 1;
    premier[_optListeDecVariables_][EPSILON] = 1;
    suivant[_optListeDecVariables_][PARENTHESE_FERMANTE] = 1;
    
    premier[_instruction_][ID_VAR] = 1;
    premier[_instruction_][ECRIRE] = 1;
    premier[_instruction_][POINT_VIRGULE] = 1;
    premier[_instruction_][ACCOLADE_OUVRANTE] = 1,
    premier[_instruction_][SI] = 1;
    premier[_instruction_][TANTQUE] = 1;
    premier[_instruction_][ID_FCT] = 1;
    premier[_instruction_][RETOUR] = 1;
    premier[_instruction_][ECRIRE] = 1;
    premier[_instruction_][POUR] = 1;
    suivant[_instruction_][ID_VAR] = 1;
    suivant[_instruction_][ACCOLADE_OUVRANTE] = 1;
    suivant[_instruction_][SI] = 1;
    suivant[_instruction_][TANTQUE] = 1;
    suivant[_instruction_][ID_FCT] = 1;
    suivant[_instruction_][RETOUR] = 1;
    suivant[_instruction_][ECRIRE] = 1;
    suivant[_instruction_][POINT_VIRGULE] = 1;
    suivant[_instruction_][ACCOLADE_FERMANTE] = 1;
    suivant[_instruction_][POUR] = 1;
    
    premier[_instructionAffect_][ID_VAR] = 1;
    suivant[_instructionAffect_][ID_VAR] = 1;
    suivant[_instructionAffect_][ACCOLADE_OUVRANTE] = 1;
    suivant[_instructionAffect_][SI] = 1;
    suivant[_instructionAffect_][TANTQUE] = 1;
    suivant[_instructionAffect_][ID_FCT] = 1;
    suivant[_instructionAffect_][RETOUR] = 1;
    suivant[_instructionAffect_][ECRIRE] = 1;
    suivant[_instructionAffect_][POINT_VIRGULE] = 1;
    suivant[_instructionAffect_][ACCOLADE_FERMANTE] = 1;
    suivant[_instructionAffect_][POUR] = 1;
    
    premier[_instructionBloc_][ACCOLADE_OUVRANTE] = 1;
    suivant[_instructionBloc_][ID_FCT] = 1;
    suivant[_instructionBloc_][ACCOLADE_OUVRANTE] = 1;
    suivant[_instructionBloc_][SI] = 1;
    suivant[_instructionBloc_][TANTQUE] = 1;
    suivant[_instructionBloc_][ID_VAR] = 1;
    suivant[_instructionBloc_][RETOUR] = 1;
    suivant[_instructionBloc_][ECRIRE] = 1;
    suivant[_instructionBloc_][ACCOLADE_FERMANTE] = 1;
    suivant[_instructionBloc_][SINON] = 1;
    suivant[_instructionBloc_][POINT_VIRGULE] = 1;
    suivant[_instructionBloc_][POUR] = 1;
    
    premier[_listeInstructions_][ID_VAR] = 1;
    premier[_listeInstructions_][POINT_VIRGULE] = 1;
    premier[_listeInstructions_][EPSILON] = 1;
    premier[_listeInstructions_][ACCOLADE_OUVRANTE] = 1;
    premier[_listeInstructions_][SI] = 1;
    premier[_listeInstructions_][TANTQUE] = 1;
    premier[_listeInstructions_][ID_FCT] = 1;
    premier[_listeInstructions_][RETOUR] = 1;
    premier[_listeInstructions_][ECRIRE] = 1;
    premier[_listeInstructions_][POUR] = 1;
    suivant[_listeInstructions_][ACCOLADE_FERMANTE] = 1;
    
    premier[_instructionSi_][SI] = 1;
    suivant[_instructionSi_][ID_VAR] = 1;
    suivant[_instructionSi_][ACCOLADE_OUVRANTE] = 1;
    suivant[_instructionSi_][SI] = 1;
    suivant[_instructionSi_][TANTQUE] = 1;
    suivant[_instructionSi_][ID_FCT] = 1;
    suivant[_instructionSi_][RETOUR] = 1;
    suivant[_instructionSi_][ECRIRE] = 1;
    suivant[_instructionSi_][POINT_VIRGULE] = 1;
    suivant[_instructionSi_][ACCOLADE_FERMANTE] = 1;
    suivant[_instructionSi_][POUR] = 1;
    
    premier[_optSinon_][SINON] = 1;
    premier[_optSinon_][EPSILON] = 1;
    suivant[_optSinon_][ID_VAR] = 1;
    suivant[_optSinon_][ACCOLADE_OUVRANTE] = 1;
    suivant[_optSinon_][SI] = 1;
    suivant[_optSinon_][TANTQUE] = 1;
    suivant[_optSinon_][ID_FCT] = 1;
    suivant[_optSinon_][RETOUR] = 1;
    suivant[_optSinon_][ECRIRE] = 1;
    suivant[_optSinon_][POINT_VIRGULE] = 1;
    suivant[_optSinon_][ACCOLADE_FERMANTE] = 1;
    suivant[_optSinon_][POUR] = 1;
    
    premier[_instructionTantque_][TANTQUE] = 1;
    suivant[_instructionTantque_][ID_VAR] = 1;
    suivant[_instructionTantque_][ACCOLADE_OUVRANTE] = 1;
    suivant[_instructionTantque_][SI] = 1;
    suivant[_instructionTantque_][TANTQUE] = 1;
    suivant[_instructionTantque_][ID_FCT] = 1;
    suivant[_instructionTantque_][RETOUR] = 1;
    suivant[_instructionTantque_][ECRIRE] = 1;
    suivant[_instructionTantque_][POINT_VIRGULE] = 1;
    suivant[_instructionTantque_][ACCOLADE_FERMANTE] = 1;
    suivant[_instructionTantque_][POUR] = 1;
    
    premier[_instructionAppel_][ID_FCT] = 1;
    suivant[_instructionAppel_][ID_VAR] = 1;
    suivant[_instructionAppel_][ACCOLADE_OUVRANTE] = 1;
    suivant[_instructionAppel_][SI] = 1;
    suivant[_instructionAppel_][TANTQUE] = 1;
    suivant[_instructionAppel_][ID_FCT] = 1;
    suivant[_instructionAppel_][RETOUR] = 1;
    suivant[_instructionAppel_][ECRIRE] = 1;
    suivant[_instructionAppel_][POINT_VIRGULE] = 1;
    suivant[_instructionAppel_][ACCOLADE_FERMANTE] = 1;
    suivant[_instructionAppel_][POUR] = 1;
    
    premier[_instructionRetour_][RETOUR] = 1;
    suivant[_instructionRetour_][ID_VAR] = 1;
    suivant[_instructionRetour_][ACCOLADE_OUVRANTE] = 1;
    suivant[_instructionRetour_][SI] = 1;
    suivant[_instructionRetour_][TANTQUE] = 1;
    suivant[_instructionRetour_][ID_FCT] = 1;
    suivant[_instructionRetour_][RETOUR] = 1;
    suivant[_instructionRetour_][ECRIRE] = 1;
    suivant[_instructionRetour_][POINT_VIRGULE] = 1;
    suivant[_instructionRetour_][ACCOLADE_FERMANTE] = 1;
    suivant[_instructionRetour_][POUR] = 1;
    
    premier[_instructionEcriture_][ECRIRE] = 1;
    suivant[_instructionEcriture_][ID_VAR] = 1;
    suivant[_instructionEcriture_][ACCOLADE_OUVRANTE] = 1;
    suivant[_instructionEcriture_][SI] = 1;
    suivant[_instructionEcriture_][TANTQUE] = 1;
    suivant[_instructionEcriture_][ID_FCT] = 1;
    suivant[_instructionEcriture_][RETOUR] = 1;
    suivant[_instructionEcriture_][ECRIRE] = 1;
    suivant[_instructionEcriture_][POINT_VIRGULE] = 1;
    suivant[_instructionEcriture_][ACCOLADE_FERMANTE] = 1;
    suivant[_instructionEcriture_][POUR] = 1;
    
    premier[_instructionPour_][POUR] = 1;
    suivant[_instructionPour_][ID_VAR] = 1;
    suivant[_instructionPour_][ACCOLADE_OUVRANTE] = 1;
    suivant[_instructionPour_][SI] = 1;
    suivant[_instructionPour_][TANTQUE] = 1;
    suivant[_instructionPour_][ID_FCT] = 1;
    suivant[_instructionPour_][RETOUR] = 1;
    suivant[_instructionPour_][ECRIRE] = 1;
    suivant[_instructionPour_][POINT_VIRGULE] = 1;
    suivant[_instructionPour_][ACCOLADE_FERMANTE] = 1;
    suivant[_instructionPour_][POUR] = 1;
    
    premier[_instructionVide_][POINT_VIRGULE] = 1;
    suivant[_instructionVide_][ID_VAR] = 1;
    suivant[_instructionVide_][ACCOLADE_OUVRANTE] = 1;
    suivant[_instructionVide_][SI] = 1;
    suivant[_instructionVide_][TANTQUE] = 1;
    suivant[_instructionVide_][ID_FCT] = 1;
    suivant[_instructionVide_][RETOUR] = 1;
    suivant[_instructionVide_][ECRIRE] = 1;
    suivant[_instructionVide_][POINT_VIRGULE] = 1;
    suivant[_instructionVide_][ACCOLADE_FERMANTE] = 1;
    suivant[_instructionVide_][POUR] = 1;
    
    premier[_expression_][NON] = 1;
    premier[_expression_][PARENTHESE_OUVRANTE] = 1;
    premier[_expression_][NOMBRE] = 1;
    premier[_expression_][ID_FCT] = 1;
    premier[_expression_][ID_VAR] = 1;
    premier[_expression_][LIRE] = 1;
    suivant[_expression_][CROCHET_FERMANT] = 1;
    suivant[_expression_][PARENTHESE_FERMANTE] = 1;
    suivant[_expression_][POINT_VIRGULE] = 1;
    suivant[_expression_][ALORS] = 1;
    suivant[_expression_][FAIRE] = 1;
    suivant[_expression_][VIRGULE] = 1;

    premier[_expressionBis_][OU] = 1;
    premier[_expressionBis_][EPSILON] = 1;
    suivant[_expressionBis_][CROCHET_FERMANT] = 1;
    suivant[_expressionBis_][PARENTHESE_FERMANTE] = 1;
    suivant[_expressionBis_][POINT_VIRGULE] = 1;
    suivant[_expressionBis_][ALORS] = 1;
    suivant[_expressionBis_][FAIRE] = 1;
    suivant[_expressionBis_][VIRGULE] = 1;
        
    premier[_conjonction_][NON] = 1;
    premier[_conjonction_][PARENTHESE_OUVRANTE] = 1;
    premier[_conjonction_][NOMBRE] = 1;
    premier[_conjonction_][ID_FCT] = 1;
    premier[_conjonction_][ID_VAR] = 1;
    premier[_conjonction_][LIRE] = 1;
    suivant[_conjonction_][OU] = 1;
    suivant[_conjonction_][POINT_VIRGULE] = 1;
    suivant[_conjonction_][ALORS] = 1;
    suivant[_conjonction_][FAIRE] = 1;
    suivant[_conjonction_][PARENTHESE_FERMANTE] = 1;
    suivant[_conjonction_][CROCHET_FERMANT] = 1;
    suivant[_conjonction_][VIRGULE] = 1;
    
    premier[_conjonctionBis_][ET] = 1;
    premier[_conjonctionBis_][EPSILON] = 1;
    suivant[_conjonctionBis_][OU] = 1;
    suivant[_conjonctionBis_][POINT_VIRGULE] = 1;
    suivant[_conjonctionBis_][ALORS] = 1;
    suivant[_conjonctionBis_][FAIRE] = 1;
    suivant[_conjonctionBis_][PARENTHESE_FERMANTE] = 1;
    suivant[_conjonctionBis_][CROCHET_FERMANT] = 1;
    suivant[_conjonctionBis_][VIRGULE] = 1;
    
    premier[_negation_][NON] = 1;
    premier[_negation_][PARENTHESE_OUVRANTE] = 1;
    premier[_negation_][NOMBRE] = 1;
    premier[_negation_][ID_FCT] = 1;
    premier[_negation_][ID_VAR] = 1;
    premier[_negation_][LIRE] = 1;
    suivant[_negation_][ET] = 1;
    suivant[_negation_][OU] = 1;
    suivant[_negation_][POINT_VIRGULE] = 1;
    suivant[_negation_][ALORS] = 1;
    suivant[_negation_][FAIRE] = 1;
    suivant[_negation_][PARENTHESE_FERMANTE] = 1;
    suivant[_negation_][CROCHET_FERMANT] = 1;
    suivant[_negation_][VIRGULE] = 1;
    
    premier[_comparaison_][PARENTHESE_OUVRANTE] = 1;
    premier[_comparaison_][NOMBRE] = 1;
    premier[_comparaison_][ID_FCT] = 1;
    premier[_comparaison_][ID_VAR] = 1;
    premier[_comparaison_][LIRE] = 1;
    suivant[_comparaison_][ET] = 1;
    suivant[_comparaison_][OU] = 1;
    suivant[_comparaison_][POINT_VIRGULE] = 1;
    suivant[_comparaison_][ALORS] = 1;
    suivant[_comparaison_][FAIRE] = 1;
    suivant[_comparaison_][PARENTHESE_FERMANTE] = 1;
    suivant[_comparaison_][CROCHET_FERMANT] = 1;
    suivant[_comparaison_][VIRGULE] = 1;
    
    premier[_comparaisonBis_][EGAL] = 1;
    premier[_comparaisonBis_][INFERIEUR] = 1;
    premier[_comparaisonBis_][EPSILON] = 1;
    suivant[_comparaisonBis_][ET] = 1;
    suivant[_comparaisonBis_][OU] = 1;
    suivant[_comparaisonBis_][POINT_VIRGULE] = 1;
    suivant[_comparaisonBis_][ALORS] = 1;
    suivant[_comparaisonBis_][FAIRE] = 1;
    suivant[_comparaisonBis_][PARENTHESE_FERMANTE] = 1;
    suivant[_comparaisonBis_][CROCHET_FERMANT] = 1;
    suivant[_comparaisonBis_][VIRGULE] = 1;
    
    premier[_expArith_][PARENTHESE_OUVRANTE] = 1;
    premier[_expArith_][NOMBRE] = 1;
    premier[_expArith_][ID_FCT] = 1;
    premier[_expArith_][ID_VAR] = 1;
    premier[_expArith_][LIRE] = 1;
    suivant[_expArith_][EGAL] = 1;
    suivant[_expArith_][INFERIEUR] = 1;
    suivant[_expArith_][OU] = 1;
    suivant[_expArith_][POINT_VIRGULE] = 1;
    suivant[_expArith_][ALORS] = 1;
    suivant[_expArith_][FAIRE] = 1;
    suivant[_expArith_][PARENTHESE_FERMANTE] = 1;
    suivant[_expArith_][CROCHET_FERMANT] = 1;
    suivant[_expArith_][VIRGULE] = 1;
    
    premier[_expArithBis_][PLUS] = 1;
    premier[_expArithBis_][MOINS] = 1;
    premier[_expArithBis_][EPSILON] = 1;
    suivant[_expArithBis_][EGAL] = 1;
    suivant[_expArithBis_][INFERIEUR] = 1;
    suivant[_expArithBis_][OU] = 1;
    suivant[_expArithBis_][ET] = 1;
    suivant[_expArithBis_][POINT_VIRGULE] = 1;
    suivant[_expArithBis_][ALORS] = 1;
    suivant[_expArithBis_][FAIRE] = 1;
    suivant[_expArithBis_][PARENTHESE_FERMANTE] = 1;
    suivant[_expArithBis_][CROCHET_FERMANT] = 1;
    suivant[_expArithBis_][VIRGULE] = 1;
    
    premier[_terme_][PARENTHESE_OUVRANTE] = 1;
    premier[_terme_][NOMBRE] = 1;
    premier[_terme_][ID_FCT] = 1;
    premier[_terme_][ID_VAR] = 1;
    premier[_terme_][LIRE] = 1;
    suivant[_terme_][PLUS] = 1;
    suivant[_terme_][MOINS] = 1;
    suivant[_terme_][EGAL] = 1;
    suivant[_terme_][INFERIEUR] = 1;
    suivant[_terme_][OU] = 1;
    suivant[_terme_][POINT_VIRGULE] = 1;
    suivant[_terme_][ALORS] = 1;
    suivant[_terme_][FAIRE] = 1;
    suivant[_terme_][PARENTHESE_FERMANTE] = 1;
    suivant[_terme_][CROCHET_FERMANT] = 1;
    suivant[_terme_][VIRGULE] = 1;

    premier[_termeBis_][FOIS] = 1;
    premier[_termeBis_][DIVISE] = 1;
    premier[_termeBis_][EPSILON] = 1;
    suivant[_termeBis_][PLUS] = 1;
    suivant[_termeBis_][MOINS] = 1;
    suivant[_termeBis_][EGAL] = 1;
    suivant[_termeBis_][INFERIEUR] = 1;
    suivant[_termeBis_][OU] = 1;
    suivant[_termeBis_][POINT_VIRGULE] = 1;
    suivant[_termeBis_][ALORS] = 1;
    suivant[_termeBis_][FAIRE] = 1;
    suivant[_termeBis_][PARENTHESE_FERMANTE] = 1;
    suivant[_termeBis_][CROCHET_FERMANT] = 1;
    suivant[_termeBis_][VIRGULE] = 1;
    suivant[_termeBis_][ET] = 1;

    premier[_facteur_][PARENTHESE_OUVRANTE] = 1;
    premier[_facteur_][NOMBRE] = 1;
    premier[_facteur_][ID_FCT] = 1;
    premier[_facteur_][ID_VAR] = 1;
    premier[_facteur_][LIRE] = 1;
    suivant[_facteur_][FOIS] = 1;
    suivant[_facteur_][DIVISE] = 1;
    suivant[_facteur_][PLUS] = 1;
    suivant[_facteur_][MOINS] = 1;
    suivant[_facteur_][EGAL] = 1;
    suivant[_facteur_][INFERIEUR] = 1;
    suivant[_facteur_][OU] = 1;
    suivant[_facteur_][POINT_VIRGULE] = 1;
    suivant[_facteur_][ALORS] = 1;
    suivant[_facteur_][FAIRE] = 1;
    suivant[_facteur_][PARENTHESE_FERMANTE] = 1;
    suivant[_facteur_][CROCHET_FERMANT] = 1;
    suivant[_facteur_][VIRGULE] = 1;
    
    premier[_var_][ID_VAR] = 1;
    suivant[_var_][FOIS] = 1;
    suivant[_var_][DIVISE] = 1;
    suivant[_var_][PLUS] = 1;
    suivant[_var_][MOINS] = 1;
    suivant[_var_][EGAL] = 1;
    suivant[_var_][INFERIEUR] = 1;
    suivant[_var_][OU] = 1;
    suivant[_var_][POINT_VIRGULE] = 1;
    suivant[_var_][ALORS] = 1;
    suivant[_var_][FAIRE] = 1;
    suivant[_var_][PARENTHESE_FERMANTE] = 1;
    suivant[_var_][CROCHET_FERMANT] = 1;
    suivant[_var_][VIRGULE] = 1;

    premier[_optIndice_][CROCHET_OUVRANT] = 1;
    premier[_optIndice_][EPSILON] = 1;
    suivant[_optIndice_][FOIS] = 1;
    suivant[_optIndice_][DIVISE] = 1;
    suivant[_optIndice_][PLUS] = 1;
    suivant[_optIndice_][MOINS] = 1;
    suivant[_optIndice_][EGAL] = 1;
    suivant[_optIndice_][INFERIEUR] = 1;
    suivant[_optIndice_][OU] = 1;
    suivant[_optIndice_][POINT_VIRGULE] = 1;
    suivant[_optIndice_][ALORS] = 1;
    suivant[_optIndice_][FAIRE] = 1;
    suivant[_optIndice_][PARENTHESE_FERMANTE] = 1;
    suivant[_optIndice_][CROCHET_FERMANT] = 1;
    suivant[_optIndice_][VIRGULE] = 1;

    premier[_appelFct_][ID_FCT] = 1;
    suivant[_appelFct_][POINT_VIRGULE] = 1;
    suivant[_appelFct_][FOIS] = 1;
    suivant[_appelFct_][DIVISE] = 1;
    suivant[_appelFct_][PLUS] = 1;
    suivant[_appelFct_][MOINS] = 1;
    suivant[_appelFct_][EGAL] = 1;
    suivant[_appelFct_][INFERIEUR] = 1;
    suivant[_appelFct_][OU] = 1;
    suivant[_appelFct_][POINT_VIRGULE] = 1;
    suivant[_appelFct_][ALORS] = 1;
    suivant[_appelFct_][FAIRE] = 1;
    suivant[_appelFct_][PARENTHESE_FERMANTE] = 1;
    suivant[_appelFct_][CROCHET_FERMANT] = 1;
    suivant[_appelFct_][VIRGULE] = 1;
    
    premier[_listeExpressions_][NON] = 1;
    premier[_listeExpressions_][PARENTHESE_OUVRANTE] = 1;
    premier[_listeExpressions_][NOMBRE] = 1;
    premier[_listeExpressions_][ID_FCT] = 1;
    premier[_listeExpressions_][ID_VAR] = 1;
    premier[_listeExpressions_][LIRE] = 1;
    premier[_listeExpressions_][EPSILON] = 1;
    suivant[_listeExpressions_][PARENTHESE_FERMANTE] = 1;
    
    premier[_listeExpressionsBis_][VIRGULE] = 1;
    premier[_listeExpressionsBis_][EPSILON] = 1;
    suivant[_listeExpressionsBis_][PARENTHESE_FERMANTE] = 1;
}

int estPremier(int nonTerm, int term) {
    return premier[nonTerm][term];
}

int estSuivant(int nonTerm, int term) {
    return suivant[nonTerm][term];
}

void printError(const char* func, const int line) {
    printf( "Erreur de syntaxe uniteCourante = %d\nFunction : %s()\nLine : %d\n", uniteCourante, func, line);
    exit(-1);
}

void indent();

void printToken() {
    char nom[25];
    char valeur[25];

    nom_token(uniteCourante, nom, valeur);
    indent();
    printf("%s\n", valeur);
}

void getValues(char * name) {
    char valeur[100];
    char nom[100];
    nom_token(uniteCourante, nom, valeur);
    strcat(name, valeur);
    strcat(name, " ");
}

void consommer() {
    indent();
    if(uniteCourante == ENTIER)
        printf("<mot_clef>entier</mot_clef>\n");
    else if(uniteCourante == ID_VAR) {
        char valeur[25];
        char nom[25];
        nom_token(uniteCourante, nom, valeur);
        printf("<id_variable>%s</id_variable>\n", valeur);
    }
    else if(uniteCourante == POINT_VIRGULE) {
        printf("<symbole>POINT_VIRGULE</symbole>\n");
    }
    else if(uniteCourante == ID_FCT) {
        char valeur[25];
        char nom[25];
        nom_token(uniteCourante, nom, valeur);
        printf("<id_fonction>%s</id_fonction>\n", valeur);
    }
    else if(uniteCourante == PARENTHESE_OUVRANTE) {
        printf("<symbole>PARENTHESE_OUVRANTE</symbole>\n");
    }
    else if(uniteCourante == PARENTHESE_FERMANTE) {
        printf("<symbole>PARENTHESE_FERMANTE</symbole>\n");
    }
    else if(uniteCourante == VIRGULE) {
        printf("<symbole>VIRGULE</symbole>\n");
    }
    else if(uniteCourante == CROCHET_OUVRANT) {
        printf("<symbole>CROCHET_OUVRANT</symbole>\n");
    }
    else if(uniteCourante == CROCHET_FERMANT) {
        printf("<symbole>CROCHET_FERMANT</symbole>\n");
    }
    else if(uniteCourante == NOMBRE) {
        char valeur[25];
        char nom[25];
        nom_token(uniteCourante, nom, valeur);
        printf("<nombre>%s</nombre>\n", valeur);
    }
    else if(uniteCourante == EGAL) {
        printf("<symbole>EGAL</symbole>\n");
    }
    else if(uniteCourante == VIRGULE) {
        printf("<symbole>VIRGULE</symbole>\n");
    }
    else if(uniteCourante == PLUS) {
        printf("<symbole>PLUS</symbole>\n");
    }
    else if(uniteCourante == MOINS) {
        printf("<symbole>MOINS</symbole>\n");
    }
    else if(uniteCourante == FOIS) {
        printf("<symbole>FOIS</symbole>\n");
    }
    else if(uniteCourante == DIVISE) {
        printf("<symbole>DIVISE</symbole>\n");
    }
    else if(uniteCourante == ACCOLADE_OUVRANTE) {
        printf("<symbole>ACCOLADE_OUVRANTE</symbole>\n");
    }
    else if(uniteCourante == ACCOLADE_FERMANTE) {
        printf("<symbole>ACCOLADE_FERMANTE</symbole>\n");
    }
    else if(uniteCourante == INFERIEUR) {
        printf("<symbole>INFERIEUR</symbole>\n");
    }
    else if(uniteCourante == ET) {
        printf("<symbole>ET</symbole>\n");
    }
    else if(uniteCourante == OU) {
        printf("<symbole>OU</symbole>\n");
    }
    else if(uniteCourante == NON) {
        printf("<symbole>NON</symbole>\n");
    }
    else if(uniteCourante == SI) {
        printf("<mot_clef>SI</mot_clef>\n");
    }
    else if(uniteCourante == ALORS) {
        printf("<mot_clef>ALORS</mot_clef>\n");
    }
    else if(uniteCourante == SINON) {
        printf("<mot_clef>SINON</mot_clef>\n");
    }
    else if(uniteCourante == TANTQUE) {
        printf("<mot_clef>TANTQUE</mot_clef>\n");
    }
    else if(uniteCourante == FAIRE) {
        printf("<mot_clef>FAIRE</mot_clef>\n");
    }
    else if(uniteCourante == TANTQUE) {
        printf("<mot_clef>TANTQUE</mot_clef>\n");
    }
    else if(uniteCourante == RETOUR) {
        printf("<mot_clef>RETOUR</mot_clef>\n");
    }
    else if(uniteCourante == LIRE) {
        printf("<mot_clef>LIRE</mot_clef>\n");
    }
    else if(uniteCourante == ECRIRE) {
        printf("<mot_clef>ecrire</mot_clef>\n");
    }
    else if(uniteCourante == POUR) {
        printf("<mot_clef>pour</mot_clef>\n");
    }

    uniteCourante = yylex();
}

void affiche_balise_ouvrante(char*, int);
void affiche_balise_fermante(char*, int);

/*
 * pg -> odv ldf #(1) programme -> optDecVariables listeDecFonctions
 */

n_prog* PG(void) {
    affiche_balise_ouvrante("programme", 1);

    n_l_dec* odv = NULL;
    n_l_dec* ldf = NULL;

    if(estPremier(_optDecVariables_, uniteCourante)) {
        odv = ODV();
        ldf = LDF();
    }
    else if(estPremier(_listeDecFonctions_, uniteCourante)) {// Cas unite = EPSILON
        odv = ODV();
        ldf = LDF();
    }
    else if(estSuivant(_programme_, uniteCourante)) {
        odv = ODV();
        ldf = LDF();
        affiche_balise_fermante("programme", 1);
        return cree_n_prog(odv, ldf);
    }
    else {
       printError(__FUNCTION__, __LINE__);
    }

    affiche_balise_fermante("programme", 1);

    return cree_n_prog(odv, ldf);
}

/*
 * odv -> ldv ';' #(2) optDecVariables -> listeDecVariables ';'
 * odv -> #(3) | 
 */

n_l_dec* ODV() {
    affiche_balise_ouvrante("optDecVariables", 1);

    n_l_dec* ldv = NULL;

    if(estPremier(_listeDecVariables_, uniteCourante)) {
        ldv = LDV();
        if(uniteCourante != POINT_VIRGULE) {
            printError(__FUNCTION__, __LINE__);
        }
        
        consommer();
    }
    else if(estSuivant(_optDecVariables_, uniteCourante)) {
        affiche_balise_fermante("optDecVariables", 1);
        return ldv;
    }
    else {
        printError(__FUNCTION__, __LINE__);
    }

    affiche_balise_fermante("optDecVariables", 1);

    return ldv;
}

/*
 * ldv -> dv ldvb #(4) listeDecVariables -> declarationVariable listeDecVariablesBis
 */

n_l_dec* LDV() {
    affiche_balise_ouvrante("listeDecVariables", 1);

    n_dec* dv = NULL;
    n_l_dec* ldvb = NULL;

    if(estPremier(_declarationVariable_, uniteCourante)) {
        dv = DV();
        ldvb = LDVB();
    }
    else {
        printError(__FUNCTION__, __LINE__);
    }
    
    affiche_balise_fermante("listeDecVariables", 1);
    
    return cree_n_l_dec(dv, ldvb);
}

/*
 * ldvb -> ',' dv ldvb #(5) listeDecVariablesBis -> ',' declarationVariable listeDecVariablesBis
 * ldvb -> #(6) |
 */

n_l_dec* LDVB() {
    affiche_balise_ouvrante("listeDecVariablesBis", 1);

    n_dec* dv = NULL;
    n_l_dec* ldvb = NULL;
    
    if(uniteCourante == VIRGULE)
    {
        consommer();
        dv = DV();
        ldvb = LDVB();
    }
    else if(estSuivant(_listeDecVariablesBis_, uniteCourante)) {
        affiche_balise_fermante("listeDecVariablesBis", 1);
        return cree_n_l_dec(dv, ldvb);
    }
    else
        printError(__FUNCTION__, __LINE__);
    affiche_balise_fermante("listeDecVariablesBis", 1);
    return cree_n_l_dec(dv, ldvb);
}

/*
 * dv -> INT IDV ott #(7) declarationVariable -> ENTIER ID_VAR optTailleTableau
 */

n_dec* DV() {
    affiche_balise_ouvrante("declarationVariable", 1);

    int ott = 0;
    char* nom = malloc(sizeof(char)*100);

    if(uniteCourante == ENTIER)
    {
        consommer();
        if(uniteCourante == ID_VAR)
        {
            getValues(nom);
            consommer();
            ott = OTT();
        }
        else {
            printError(__FUNCTION__, __LINE__);
        }
    }
    else { printError(__FUNCTION__, __LINE__); }
    affiche_balise_fermante("declarationVariable", 1);

    if(ott <= 0) { return cree_n_dec_var(nom); }
    
    return cree_n_dec_tab(nom, ott);
}

/*
 * ott -> '[' NB ']' #(8) optTailleTableau -> '[' NOMBRE ']'
 * ott -> #(9) |
 */

int OTT() {
    affiche_balise_ouvrante("optTailleTableau", 1);

    int taille = 0;
    if(uniteCourante == CROCHET_OUVRANT)
    {
        consommer();
        if(uniteCourante == NOMBRE)
        {
            char* buff = malloc(sizeof(char)*100);
            getValues(buff);
            taille = atoi(buff);
            consommer();
            if(uniteCourante == CROCHET_FERMANT)
            {
                consommer();
            }
            else
                printError(__FUNCTION__, __LINE__);
        }
        else
            printError(__FUNCTION__, __LINE__);
    }
    else if(estSuivant(_optTailleTableau_, uniteCourante))
    {
        affiche_balise_fermante("optTailleTableau", 1);
        return taille;
    }
    else 
        printError(__FUNCTION__, __LINE__);
    
    affiche_balise_fermante("optTailleTableau", 1);

    return taille;
}

/*
 * ldf -> df ldf #(10) listeDecFonctions -> declarationFonction listeDecFonctions
 * ldf -> #(11) |
 */

n_l_dec* LDF() {
    affiche_balise_ouvrante("listeDecFonctions", 1);
    
    n_dec* df = NULL;
    n_l_dec* ldf = NULL;

    if(estPremier(_declarationFonction_, uniteCourante)) {
        df = DF();
        ldf = LDF();
    }
    else if(estSuivant(_listeDecFonctions_, uniteCourante)) {
        affiche_balise_fermante("listeDecFonctions", 1);
        return NULL;
    }
    else
        printError(__FUNCTION__, __LINE__);
        
    affiche_balise_fermante("listeDecFonctions", 1);

    return cree_n_l_dec(df, ldf);
}

/*
 * df -> IDF lp odv ib #(12) declarationFonction -> ID_FCT listeParam optDecVariables instructionBloc
 */

n_dec* DF() {
    affiche_balise_ouvrante("declarationFonction", 1);

    char* nom = malloc(sizeof(char)*100);
    n_l_dec* lp = NULL;
    n_l_dec* odv = NULL;
    n_instr* ib = NULL;

    if(uniteCourante == ID_FCT) {
        
        getValues(nom);

        consommer();
        lp = LP();
        odv = ODV();
        ib = IB();
    }
    else {
        printError(__FUNCTION__, __LINE__);
    }
    
    affiche_balise_fermante("declarationFonction", 1);

    return cree_n_dec_fonc(nom, lp, odv, ib);
}

/*
 * lp -> '(' oldv ')' #(13) listeParam -> '(' optListeDecVariables ')'
 */

n_l_dec* LP() {
    affiche_balise_ouvrante("listeParam", 1);
    
    n_l_dec* oldv = NULL;

    if(uniteCourante == PARENTHESE_OUVRANTE) {
        consommer();
        oldv = OLDV();
        if(uniteCourante == PARENTHESE_FERMANTE) {
            consommer();
            affiche_balise_fermante("listeParam", 1);
            return oldv;
        }
        else
            printError(__FUNCTION__, __LINE__);
    }
    else
        printError(__FUNCTION__, __LINE__);
    
    affiche_balise_fermante("listeParam", 1);

    return oldv;
}

/*
 * oldv -> ldv #(14) optListeDecVariables -> listeDecVariables
 * oldv -> #(15) |
 */

n_l_dec* OLDV() {
    affiche_balise_ouvrante("optListeDecVariables", 1);

    n_l_dec* ldv = NULL;

    if(estPremier(_listeDecVariables_, uniteCourante)) {
        ldv = LDV();
    }
    else if(estSuivant(_optListeDecVariables_, uniteCourante)) {
        affiche_balise_fermante("optListeDecVariables", 1);
        return NULL;
    }
    else
        printError(__FUNCTION__, __LINE__);

    affiche_balise_fermante("optListeDecVariables", 1);

    return ldv;
}

/*
 * i -> iaff #(16) instruction -> instructionAffect
 * i -> ib #(17) | instructionBloc
 * i -> isi #(18) | instructionSi
 * i -> itq #(19) | instructionTantque
 * i -> iapp #(20) | instructionAppel
 * i -> iret #(21) | instructionRetour
 * i -> iecr #(22) | instructionEcriture
 * i -> ivide #(23) | instructionVide
 */

n_instr* I() {
    affiche_balise_ouvrante("instruction", 1);

    n_instr* i = NULL;

    if(estPremier(_instructionAffect_, uniteCourante))
        i = IAFF();
    else if(estPremier(_instructionBloc_, uniteCourante))
        i = IB();
    else if(estPremier(_instructionSi_, uniteCourante))
        i = ISI();
    else if(estPremier(_instructionTantque_, uniteCourante))
        i = ITQ();
    else if(estPremier(_instructionEcriture_, uniteCourante))
        i = IECR();
    else if(estPremier(_instructionAppel_, uniteCourante))
        i = IAPP();
    else if(estPremier(_instructionRetour_, uniteCourante))
        i = IRET();
    else if(estPremier(_instructionVide_, uniteCourante))
        i = IVIDE();
    else if(estPremier(_instructionPour_, uniteCourante))
        i = IPOUR();
    else
        printError(__FUNCTION__, __LINE__);
        
    affiche_balise_fermante("instruction", 1);

    return i;
}

/*
 * iaff -> var '=' exp ';' #(24) instructionAffect -> var '=' expression ';'
 */

n_instr* IAFF() {
    affiche_balise_ouvrante("instructionAffect", 1);
    
    n_var* var = NULL;
    n_exp* exp = NULL;

    if(estPremier(_var_, uniteCourante)) {
        var = VAR();
        
        if(uniteCourante == EGAL)
        {
            consommer();
            
            exp = EXP();
            
            if(uniteCourante == POINT_VIRGULE)
            {
                consommer();
            }
            else
                printError(__FUNCTION__, __LINE__);
        }
        else 
            printError(__FUNCTION__, __LINE__);
    }
    affiche_balise_fermante("instructionAffect", 1);

    return cree_n_instr_affect(var, exp);
}

/*
 * ib -> '{' li '}' #(25) instructionBloc -> '{' listeInstructions '}'
 */

n_instr* IB() {
    affiche_balise_ouvrante("instructionBloc", 1);
    
    n_l_instr* li = NULL;
    if(uniteCourante == ACCOLADE_OUVRANTE)
    {
        consommer();
        li = LI();
        if(uniteCourante == ACCOLADE_FERMANTE)
        {
            consommer();
        }
        else {
            printError(__FUNCTION__, __LINE__);
        }
    }
    else
        printError(__FUNCTION__, __LINE__);
    affiche_balise_fermante("instructionBloc", 1);

    return cree_n_instr_bloc(li);
}

/*
 * li -> i li #(26) listeInstructions -> instruction listeInstructions
 * li -> #(27) |
 */

n_l_instr* LI() {
    affiche_balise_ouvrante("listeInstructions", 1);
    
    n_instr* i;
    n_l_instr* li;

    if(estPremier(_instruction_, uniteCourante)) {
        i = I();
        li = LI();
    }
    else if(estSuivant(_listeInstructions_, uniteCourante)) {
        affiche_balise_fermante("listeInstructions", 1);
        return NULL;
    }
    else
        printError(__FUNCTION__, __LINE__);
        
    affiche_balise_fermante("listeInstructions", 1);

    return cree_n_l_instr(i, li);
}

/*
 * ipour -> POUR iaff; exp; iaff; FAIRE instructionBloc
 */
 
n_instr* IPOUR() {
    affiche_balise_ouvrante("instructionPour", 1);
    
    n_instr* iaff = NULL;
    n_exp* exp = NULL; 
    n_instr* iaff2 = NULL;
    n_instr* ib = NULL;
    
    if(uniteCourante == POUR)
    {
        consommer();
        if(estPremier(_instructionAffect_, uniteCourante))
        {
            iaff = IAFF();
            if(estPremier(_expression_, uniteCourante))
            {
                exp = EXP();
                if(uniteCourante == POINT_VIRGULE)
                {
                    consommer();
                    if(estPremier(_instructionAffect_, uniteCourante))
                    {
                        iaff2 = IAFF();
                        if(uniteCourante == FAIRE)
                        {
                            consommer();
                            if(estPremier(_instructionBloc_, uniteCourante))
                            {
                                ib = IB();
                            }
                            else
                                printError(__FUNCTION__, __LINE__);
                        }
                        else
                            printError(__FUNCTION__, __LINE__);
                    }
                    else
                        printError(__FUNCTION__, __LINE__);
                }
                else
                    printError(__FUNCTION__, __LINE__);
            }
            else
                printError(__FUNCTION__, __LINE__);
        }
        else
            printError(__FUNCTION__, __LINE__);
    }
    else
        printError(__FUNCTION__, __LINE__);

    affiche_balise_fermante("instructionPour", 1);

    return cree_n_instr_pour(iaff, exp, iaff2, ib);
}


/*
 * isi -> SI exp ALR ib osinon #(28) instructionSi -> SI expression ALORS instructionBloc optSinon
 */

n_instr* ISI() {
    affiche_balise_ouvrante("instructionSi", 1);

    n_exp* exp = NULL;
    n_instr* ib = NULL;
    n_instr* osinon = NULL;

    if(uniteCourante == SI)
    {
        consommer();
        exp = EXP();
        if(uniteCourante == ALORS)
        {
            consommer();
            ib = IB();
            osinon = OSINON();
        }
        else {
            printError(__FUNCTION__, __LINE__);
        }
    }
    else
        printError(__FUNCTION__, __LINE__);
        
    affiche_balise_fermante("instructionSi", 1);

    return cree_n_instr_si(exp, ib, osinon);
}

/*
 * osinon -> SIN ib #(29) optSinon -> SINON instructionBloc
 * osinon -> #(30) |
 */

n_instr* OSINON() {
    affiche_balise_ouvrante("optSinon", 1);
    
    n_instr* ib = NULL;

    if(uniteCourante == SINON)
    {
        consommer();
        ib = IB();
    }
    else if(estSuivant(_optSinon_, uniteCourante)) {
        affiche_balise_fermante("optSinon", 1);
        return NULL;
    }
    else
        printError(__FUNCTION__, __LINE__);
        
    affiche_balise_fermante("optSinon", 1);

    return ib;
}

/*
 * itq -> TQ exp FR ib #(31) instructionTantque -> TANTQUE expression FAIRE instructionBloc
 */

n_instr* ITQ() {
    affiche_balise_ouvrante("instructionTantque", 1);
    
    n_exp* exp = NULL;
    n_instr* ib = NULL;

    if(uniteCourante == TANTQUE)
    {
        consommer();
        exp = EXP();
        if(uniteCourante == FAIRE)
        {
            consommer();
            ib = IB();
        }
        else
            printError(__FUNCTION__, __LINE__);
    }
    else
        printError(__FUNCTION__, __LINE__);

    affiche_balise_fermante("instructionTantque", 1);

    return cree_n_instr_tantque(exp, ib);
}

/*
 * iapp -> appf ';' #(32) instructionAppel -> appelFct ';'
 */

n_instr* IAPP() {
    affiche_balise_ouvrante("instructionAppel", 1);
    
    n_appel* appf = NULL;
    if(estPremier(_appelFct_, uniteCourante))
    {
        appf = APPF();
        if(uniteCourante == POINT_VIRGULE)
        {
            consommer();
        }
        else
            printError(__FUNCTION__, __LINE__);
    }
    else 
        printError(__FUNCTION__, __LINE__);
        
    affiche_balise_fermante("instructionAppel", 1);

    return cree_n_instr_appel(appf);
}

/*
 * iret -> RET exp ';' #(33) instructionRetour -> RETOUR expression ';'
 */

n_instr* IRET() {
    affiche_balise_ouvrante("instructionRetour", 1);
    
    n_exp* exp = NULL;

    if(uniteCourante == RETOUR)
    {
        consommer();
        exp = EXP();
        if(uniteCourante == POINT_VIRGULE)
            consommer();
        else
            printError(__FUNCTION__, __LINE__);
    }
    else
        printError(__FUNCTION__, __LINE__);
        
    affiche_balise_fermante("instructionRetour", 1);

    return cree_n_instr_retour(exp);
}

/*
 * iecr -> ECR '(' exp ')' #(34) instructionEcriture -> ECRIRE '(' expression ')' ';'
 */

n_instr* IECR() {
    affiche_balise_ouvrante("instructionEcriture", 1);
    
    n_exp* exp = NULL;

    if(uniteCourante == ECRIRE)
    {
        consommer();
        if(uniteCourante == PARENTHESE_OUVRANTE)
        {
            consommer();
            exp = EXP();
            if(uniteCourante == PARENTHESE_FERMANTE) {
                consommer();
                if(uniteCourante == POINT_VIRGULE)
                    consommer();
                else
                    printError(__FUNCTION__, __LINE__);
            }
            else
                printError(__FUNCTION__, __LINE__);
        }
        else
            printError(__FUNCTION__, __LINE__);
    }
    else
        printError(__FUNCTION__, __LINE__);
        
    affiche_balise_fermante("instructionEcriture", 1);

    return cree_n_instr_ecrire(exp);
}

/*
 * ivide -> ';' #(35) instructionVide -> ';'
 */

n_instr* IVIDE() {
    affiche_balise_ouvrante("instructionVide", 1);
    
    if(uniteCourante == POINT_VIRGULE)
        consommer();
    else
        printError(__FUNCTION__, __LINE__);
        
    affiche_balise_fermante("instructionVide", 1);

    return cree_n_instr_vide();
}

/*
 * exp -> conj expB #(36) expression -> conjonction expressionBis
 */
 
n_exp* EXP() {
    affiche_balise_ouvrante("expression", 1);

    n_exp* conj = NULL;
    n_exp* expb = NULL;

    if(estPremier(_conjonction_, uniteCourante))
    {
        conj = CONJ();
        expb = EXPB(conj);
    }
    else
        printError(__FUNCTION__, __LINE__);
        
    affiche_balise_fermante("expression", 1);

    if(expb == NULL) return conj;

    return expb;
}
 
/*
 * expB -> '|' conj expB #(37) expressionBis -> '|' conjonction expressionBis
 * expB -> #(38) |
 */
 
n_exp* EXPB(n_exp* conjPere) {
    affiche_balise_ouvrante("expressionBis", 1);

    n_exp* conj = NULL;
    n_exp* expb = NULL;
    n_exp* herite_fils = NULL;

    if(uniteCourante == OU)
    {
        consommer();
        
        conj = CONJ();      
        herite_fils = cree_n_exp_op(ou, conjPere, conj);
        expb = EXPB(herite_fils);
    }
    else if(estSuivant(_expressionBis_, uniteCourante))
    {
        affiche_balise_fermante("expressionBis", 1);
        return conjPere;
    }
    else
        printError(__FUNCTION__, __LINE__);
    
    affiche_balise_fermante("expressionBis", 1);

    return expb;
}
 
/*
 * conj -> neg conjB #(39) conjonction -> negation conjonctionBis
 */
 
 n_exp* CONJ() {
     affiche_balise_ouvrante("conjonction", 1);
     
     n_exp* neg = NULL;
     n_exp* conjb = NULL;

     if(estPremier(_negation_, uniteCourante))
     {
         neg = NEG();
         conjb = CONJB(neg);
     }
     else
        printError(__FUNCTION__, __LINE__);
        
     affiche_balise_fermante("conjonction", 1);

     if(conjb == NULL) return neg;

     return conjb;
 }
 
/*
 * conjB -> '&' neg conjB #(40) conjonctionBis -> '&' negation conjonctionBis
 * conjB -> #(41) |
 */
 
n_exp* CONJB(n_exp* negPere) {
     affiche_balise_ouvrante("conjonctionBis", 1);
     
     n_exp* neg = NULL;
     n_exp* conjb = NULL;
     n_exp* herite_fils = NULL;

     if(uniteCourante == ET) {
         consommer();
         neg = NEG();

         herite_fils = cree_n_exp_op(et, negPere, neg);
         conjb = CONJB(herite_fils);
     }
     else if(estSuivant(_conjonctionBis_, uniteCourante)) {
        affiche_balise_fermante("conjonctionBis", 1);
        return negPere;
     }
     else
        printError(__FUNCTION__, __LINE__);
     
     affiche_balise_fermante("conjonctionBis", 1);
 
     return conjb;
}
 
/*
 * neg -> '!' comp #(42) negation -> '!' comparaison
 * neg -> comp #(43) | comparaison
 */
 
 n_exp* NEG() {
     affiche_balise_ouvrante("negation", 1);
     
     n_exp* comp = NULL;

     if(uniteCourante == NON) {
        consommer();
        comp = COMP();
        affiche_balise_fermante("negation", 1);

        return cree_n_exp_op(non, comp, NULL);
     }
     else if(estPremier(_comparaison_, uniteCourante)) {
         comp = COMP();
     }
     else
        printError(__FUNCTION__, __LINE__);

    return comp;
 }
 
/*
 * comp -> e compb #(44) comparaison -> expArith comparaisonBis
 */
 
 n_exp* COMP() {
     affiche_balise_ouvrante("comparaison", 1);
     
     n_exp* e = NULL;
     n_exp* compb = NULL;

     if(estPremier(_expArith_, uniteCourante))
     {
         e = E();
         compb = COMPB(e);
     }
     else
        printError(__FUNCTION__, __LINE__);
        
     affiche_balise_fermante("comparaison", 1);

     if(compb == NULL) return e;

     return compb;
 }
 
/*
 * compb -> '=' e compb #(45) comparaisonBis -> '=' expArith comparaisonBis
 * compb -> '<' e compb #(46) | '<' expArith comparaisonBis
 * compb -> #(47) |
 */
 
n_exp* COMPB(n_exp* herite) {
    affiche_balise_ouvrante("comparaisonBis", 1);
     
    n_exp* e = NULL;
    n_exp* compb = NULL;
    n_exp* herite_fils = NULL;

    if(uniteCourante == EGAL || uniteCourante == INFERIEUR) {
        int uniteCouranteBefore = uniteCourante;
        consommer();
        e = E();
         
        if(uniteCouranteBefore == EGAL)
            herite_fils = cree_n_exp_op(egal, herite, e);
        if(uniteCouranteBefore == INFERIEUR)
            herite_fils = cree_n_exp_op(inf, herite, e);

        compb = COMPB(herite_fils);
    }
    else if(estSuivant(_comparaisonBis_, uniteCourante)) {
        affiche_balise_fermante("comparaisonBis", 1);
        return herite;
    }
    else
        printError(__FUNCTION__, __LINE__);
    
    affiche_balise_fermante("comparaisonBis", 1);
    
    return compb;
}
 
/*
 * e -> t eb #(48) expArith -> terme expArithBis
 */
 
n_exp* E() {
    affiche_balise_ouvrante("expArith", 1);
    
    n_exp* t = NULL;
    n_exp* eb = NULL;

    if(estPremier(_terme_, uniteCourante)) {
        t = T();
        eb = EB(t);
    }
    else
        printError(__FUNCTION__, __LINE__);
        
    affiche_balise_fermante("expArith", 1);

    if(eb == NULL) return t;

    return eb;
}

/* eb -> '+' t eb #(49) expArithBis -> '+' terme expArithBis
 * eb -> '-' t eb #(50) | '-' terme expArithBis
 * eb -> #(51) |
 */

n_exp* EB(n_exp* herite) {
    affiche_balise_ouvrante("expArithBis", 1);
    
    n_exp* t = NULL;
    n_exp* eb = NULL;
    n_exp* herite_fils = NULL;

    if(uniteCourante == PLUS || uniteCourante == MOINS) {
        int uniteCouranteBefore = uniteCourante;
        consommer();
        t = T();

        if(uniteCouranteBefore == PLUS)
            herite_fils = cree_n_exp_op(plus, herite, t);
        if(uniteCouranteBefore == MOINS)
            herite_fils = cree_n_exp_op(moins, herite, t);

        eb = EB(herite_fils);
    }
    else if(estSuivant(_expArithBis_, uniteCourante)) {
        affiche_balise_fermante("expArithBis", 1);
        return herite;
    }
    else
        printError(__FUNCTION__, __LINE__);
        
    affiche_balise_fermante("expArithBis", 1);

    return eb;
}

/*
 * t -> f tb #(52) terme -> facteur termeBis
 */
 
n_exp* T() {
    affiche_balise_ouvrante("terme", 1);
    
    n_exp* f = NULL;
    n_exp* tb = NULL;
    
    if(estPremier(_facteur_, uniteCourante)) {
        f = F();
        tb = TB(f);
    }
    else
        printError(__FUNCTION__, __LINE__);
        
    affiche_balise_fermante("terme", 1);

    if(tb == NULL) return f;

    return tb;
}

/* 
 * tb -> '*' f tb #(53) termeBis -> '*' facteur termeBis
 * tb -> '/' f tb #(54) | '/' facteur termeBis
 * tb -> #(55) |
 */

n_exp* TB(n_exp* fPere) {
    affiche_balise_ouvrante("termeBis", 1);
    
    n_exp* f = NULL;
    n_exp* tb = NULL;
    n_exp* heriteFils = NULL;

    if(uniteCourante == FOIS || uniteCourante == DIVISE)
    {
        int uniteCouranteBefore = uniteCourante;
        consommer();
        f = F();

        if(uniteCouranteBefore == FOIS)
            heriteFils = cree_n_exp_op(fois, fPere, f);
        if(uniteCouranteBefore == DIVISE)
            heriteFils = cree_n_exp_op(divise, fPere, f);

        tb = TB(heriteFils);
    }
    else if(estSuivant(_termeBis_, uniteCourante))
    {
        affiche_balise_fermante("termeBis", 1);
        return fPere;
    }
    else
        printError(__FUNCTION__, __LINE__);
        
    affiche_balise_fermante("termeBis", 1);

    return tb;
}

/*
 * f -> '(' exp ')' #(56) facteur -> '(' expression ')'
 * f -> NB #(57) | NOMBRE
 * f -> appf #(58) | appelFct
 * f -> var #(59) | var
 * f -> LIRE '(' ')' #(60) | LIRE '(' ')'
 */
 
n_exp* F() {
    affiche_balise_ouvrante("facteur", 1);
    
    n_exp* exp = NULL;

    if(uniteCourante == NOMBRE)
    {
        consommer();
        char* buff = malloc(sizeof(char)*100);
        getValues(buff);
        return cree_n_exp_entier(atoi(buff));
    }
    else if(uniteCourante == PARENTHESE_OUVRANTE)
    {
        consommer();
        exp = EXP();
        if(uniteCourante == PARENTHESE_FERMANTE)
        {
            consommer();
        }
        else
            printError(__FUNCTION__, __LINE__);
    }
    else if(uniteCourante == LIRE) {
        consommer();
        if(uniteCourante == PARENTHESE_OUVRANTE)
        {
            consommer();
            if(uniteCourante == PARENTHESE_FERMANTE)
            {
                consommer();
                affiche_balise_fermante("facteur", 1);
                return cree_n_exp_lire();
            }
            else 
                printError(__FUNCTION__, __LINE__);
        }
        else
            printError(__FUNCTION__, __LINE__);
    }
    else if(estPremier(_appelFct_, uniteCourante))
        return cree_n_exp_appel(APPF());
    else if(estPremier(_var_, uniteCourante))
        return cree_n_exp_var(VAR());
    else
        printError(__FUNCTION__, __LINE__);
        
    affiche_balise_fermante("facteur", 1);

    return exp;
}

/*
 * var -> IDV oind #(61) var -> ID_VAR optIndice
 */

n_var* VAR() {
    affiche_balise_ouvrante("var", 1);
    
    char* nom = malloc(sizeof(char)*100);
    n_exp* oind = NULL;

    if(uniteCourante == ID_VAR)
    {
        getValues(nom);
        consommer();
        oind = OIND();
    }
    else
        printError(__FUNCTION__, __LINE__);
    
    affiche_balise_fermante("var", 1);

    if(oind == NULL) { return cree_n_var_simple(nom); }

    return cree_n_var_indicee(nom, oind);
}

/*
 * oind -> '[' exp ']' #(62) optIndice -> '[' expression ']'
 * oind -> #(63) |
 */
 
n_exp* OIND() {
    affiche_balise_ouvrante("optIndice", 1);
    
    n_exp* exp = NULL;
    
    if(uniteCourante == CROCHET_OUVRANT) {
        consommer();
        exp = EXP();
        if(uniteCourante == CROCHET_FERMANT)
        {
            consommer();
        }
        else
            printError(__FUNCTION__, __LINE__);
    }
    else if(estSuivant(_optIndice_, uniteCourante))
    {
        affiche_balise_fermante("optIndice", 1);
        return NULL;
    }
    else
        printError(__FUNCTION__, __LINE__);
    
    affiche_balise_fermante("optIndice", 1);

    return exp;
}

/*
 * appf -> IDF '(' lexp ')' #(64) appelFct -> ID_FCT '(' listeExpressions ')'
 */

n_appel* APPF() {
    affiche_balise_ouvrante("appelFct", 1);
    
    char* nom = malloc(sizeof(char)*100);
    n_l_exp* lexp = NULL;

    if(uniteCourante == ID_FCT)
    {
        getValues(nom);
        consommer();
        if(uniteCourante == PARENTHESE_OUVRANTE)
        {
            consommer();
            lexp = LEXP();
            if(uniteCourante == PARENTHESE_FERMANTE)
            {
                consommer();
            }
            else
                printError(__FUNCTION__, __LINE__);
        }
        else
            printError(__FUNCTION__, __LINE__);
    }
    else
        printError(__FUNCTION__, __LINE__);
            
    affiche_balise_fermante("appelFct", 1);

    return cree_n_appel(nom, lexp);
}

/*
 * lexp -> exp lexpb #(65) listeExpressions -> expression listeExpressionsBis
 * lexp -> #(66) |
 */

n_l_exp* LEXP() {
    affiche_balise_ouvrante("listeExpressions", 1);
    
    n_exp* exp = NULL;
    n_l_exp* lexpb = NULL;

    if(estPremier(_listeExpressions_, uniteCourante)) {
        exp = EXP();
        lexpb = LEXPB();
    }
    else if(estSuivant(_listeExpressions_, uniteCourante)) {
        affiche_balise_fermante("listeExpressions", 1);
        return NULL;
    }
    else
        printError(__FUNCTION__, __LINE__);
    
    affiche_balise_fermante("listeExpressions", 1);

    return cree_n_l_exp(exp, lexpb);
}

/*
 * lexpb -> ',' exp lexpb #(67) listeExpressionsBis -> ',' expression listeExpressionsBis
 * lexpb -> #(68) |
 */

n_l_exp* LEXPB() {
    affiche_balise_ouvrante("listeExpressionsBis", 1);
    
    n_exp* exp = NULL;
    n_l_exp* lexpb = NULL;

    if(uniteCourante == VIRGULE) {
        consommer();
        exp = EXP();
        lexpb = LEXPB();
    }
    else if(estSuivant(_listeExpressionsBis_, uniteCourante)) {
        affiche_balise_fermante("listeExpressionsBis", 1);
        return NULL;
    }
    else
        printError(__FUNCTION__, __LINE__);
        
    affiche_balise_fermante("listeExpressionsBis", 1);

    return cree_n_l_exp(exp, lexpb);
}
