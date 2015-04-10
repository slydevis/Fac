#include "analyseur_syntaxique.h"

void initPremier() {
    premier[_programme_][ENTIER] = 1;
    premier[_programme_][EPSILON] = 1;
    
    premier[_optDecVariables_][ENTIER] = 1;
    premier[_optDecVariables_][EPSILON] = 1;
    
    premier[_listeDecVariables_][ENTIER] = 1;
    
    premier[_listeDecVariablesBis_][VIRGULE] = 1;
    premier[_listeDecVariablesBis_][EPSILON] = 1;
    
    premier[_declarationVariable_][ENTIER] = 1;
    
    premier[_optTailleTableau_][CROCHET_OUVRANT] = 1;
    premier[_optTailleTableau_][EPSILON] = 1;
    
    premier[_listeDecFonctions_][ID_FCT] = 1;
    premier[_listeDecFonctions_][EPSILON] = 1;
    
    premier[_declarationFonction_][ID_FCT] = 1;
    
    premier[_listeParam_][PARENTHESE_OUVRANTE] = 1;
    
    premier[_optListeDecVariables_][ENTIER] = 1;
    premier[_optListeDecVariables_][EPSILON] = 1;
    
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
    
    premier[_instructionAffect_][ID_VAR] = 1;
    
    premier[_instructionBloc_][ACCOLADE_OUVRANTE] = 1;
    
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
    
    premier[_instructionSi_][SI] = 1;
    
    premier[_optSinon_][SINON] = 1;
    premier[_optSinon_][EPSILON] = 1;
    
    premier[_instructionTantque_][TANTQUE] = 1;
    
    premier[_instructionAppel_][ID_FCT] = 1;
    
    premier[_instructionRetour_][RETOUR] = 1;
    
    premier[_instructionEcriture_][ECRIRE] = 1;
    
    premier[_instructionPour_][POUR] = 1;
    
    premier[_instructionVide_][POINT_VIRGULE] = 1;
    
    premier[_expression_][NON] = 1;
    premier[_expression_][PARENTHESE_OUVRANTE] = 1;
    premier[_expression_][NOMBRE] = 1;
    premier[_expression_][ID_FCT] = 1;
    premier[_expression_][ID_VAR] = 1;
    premier[_expression_][LIRE] = 1;

    premier[_expressionBis_][OU] = 1;
    premier[_expressionBis_][EPSILON] = 1;
        
    premier[_conjonction_][NON] = 1;
    premier[_conjonction_][PARENTHESE_OUVRANTE] = 1;
    premier[_conjonction_][NOMBRE] = 1;
    premier[_conjonction_][ID_FCT] = 1;
    premier[_conjonction_][ID_VAR] = 1;
    premier[_conjonction_][LIRE] = 1;
    
    premier[_conjonctionBis_][ET] = 1;
    premier[_conjonctionBis_][EPSILON] = 1;
    
    premier[_negation_][NON] = 1;
    premier[_negation_][PARENTHESE_OUVRANTE] = 1;
    premier[_negation_][NOMBRE] = 1;
    premier[_negation_][ID_FCT] = 1;
    premier[_negation_][ID_VAR] = 1;
    premier[_negation_][LIRE] = 1;
    
    premier[_comparaison_][PARENTHESE_OUVRANTE] = 1;
    premier[_comparaison_][NOMBRE] = 1;
    premier[_comparaison_][ID_FCT] = 1;
    premier[_comparaison_][ID_VAR] = 1;
    premier[_comparaison_][LIRE] = 1;
    
    premier[_comparaisonBis_][EGAL] = 1;
    premier[_comparaisonBis_][INFERIEUR] = 1;
    premier[_comparaisonBis_][EPSILON] = 1;
    
    premier[_expArith_][PARENTHESE_OUVRANTE] = 1;
    premier[_expArith_][NOMBRE] = 1;
    premier[_expArith_][ID_FCT] = 1;
    premier[_expArith_][ID_VAR] = 1;
    premier[_expArith_][LIRE] = 1;
    
    premier[_expArithBis_][PLUS] = 1;
    premier[_expArithBis_][MOINS] = 1;
    premier[_expArithBis_][EPSILON] = 1;
    
    premier[_terme_][PARENTHESE_OUVRANTE] = 1;
    premier[_terme_][NOMBRE] = 1;
    premier[_terme_][ID_FCT] = 1;
    premier[_terme_][ID_VAR] = 1;
    premier[_terme_][LIRE] = 1;

    premier[_termeBis_][FOIS] = 1;
    premier[_termeBis_][DIVISE] = 1;
    premier[_termeBis_][EPSILON] = 1;

    premier[_facteur_][PARENTHESE_OUVRANTE] = 1;
    premier[_facteur_][NOMBRE] = 1;
    premier[_facteur_][ID_FCT] = 1;
    premier[_facteur_][ID_VAR] = 1;
    premier[_facteur_][LIRE] = 1;
    
    premier[_var_][ID_VAR] = 1;

    premier[_optIndice_][CROCHET_OUVRANT] = 1;
    premier[_optIndice_][EPSILON] = 1;

    premier[_appelFct_][ID_FCT] = 1;
    
    premier[_listeExpressions_][NON] = 1;
    premier[_listeExpressions_][PARENTHESE_OUVRANTE] = 1;
    premier[_listeExpressions_][NOMBRE] = 1;
    premier[_listeExpressions_][ID_FCT] = 1;
    premier[_listeExpressions_][ID_VAR] = 1;
    premier[_listeExpressions_][LIRE] = 1;
    premier[_listeExpressions_][EPSILON] = 1;
    
    premier[_listeExpressionsBis_][VIRGULE] = 1;
    premier[_listeExpressionsBis_][EPSILON] = 1;
}