#include "analyseur_syntaxique.h"

void initSuivant() {
    suivant[_programme_][FIN] = 1;

    suivant[_optDecVariables_][ID_FCT] = 1;
    suivant[_optDecVariables_][ACCOLADE_OUVRANTE] = 1;
    suivant[_optDecVariables_][FIN] = 1;

    suivant[_listeDecVariables_][POINT_VIRGULE] = 1;
    suivant[_listeDecVariables_][PARENTHESE_FERMANTE] = 1;

    suivant[_listeDecVariablesBis_][POINT_VIRGULE] = 1;
    suivant[_listeDecVariablesBis_][PARENTHESE_FERMANTE] = 1;

    suivant[_declarationVariable_][VIRGULE] = 1;
    suivant[_declarationVariable_][POINT_VIRGULE] = 1;
    suivant[_declarationVariable_][PARENTHESE_FERMANTE] = 1;

    suivant[_optTailleTableau_][VIRGULE] = 1;
    suivant[_optTailleTableau_][POINT_VIRGULE] = 1;
    suivant[_optTailleTableau_][PARENTHESE_FERMANTE] = 1;

    suivant[_listeDecFonctions_][FIN] = 1;

    suivant[_declarationFonction_][ID_FCT] = 1;
    suivant[_declarationFonction_][FIN] = 1;

    suivant[_listeParam_][ENTIER] = 1;
    suivant[_listeParam_][ACCOLADE_OUVRANTE] = 1;

    suivant[_optListeDecVariables_][PARENTHESE_FERMANTE] = 1;

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

    suivant[_listeInstructions_][ACCOLADE_FERMANTE] = 1;

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

    suivant[_expression_][CROCHET_FERMANT] = 1;
    suivant[_expression_][PARENTHESE_FERMANTE] = 1;
    suivant[_expression_][POINT_VIRGULE] = 1;
    suivant[_expression_][ALORS] = 1;
    suivant[_expression_][FAIRE] = 1;
    suivant[_expression_][VIRGULE] = 1;

    suivant[_expressionBis_][CROCHET_FERMANT] = 1;
    suivant[_expressionBis_][PARENTHESE_FERMANTE] = 1;
    suivant[_expressionBis_][POINT_VIRGULE] = 1;
    suivant[_expressionBis_][ALORS] = 1;
    suivant[_expressionBis_][FAIRE] = 1;
    suivant[_expressionBis_][VIRGULE] = 1;

    suivant[_conjonction_][OU] = 1;
    suivant[_conjonction_][POINT_VIRGULE] = 1;
    suivant[_conjonction_][ALORS] = 1;
    suivant[_conjonction_][FAIRE] = 1;
    suivant[_conjonction_][PARENTHESE_FERMANTE] = 1;
    suivant[_conjonction_][CROCHET_FERMANT] = 1;
    suivant[_conjonction_][VIRGULE] = 1;

    suivant[_conjonctionBis_][OU] = 1;
    suivant[_conjonctionBis_][POINT_VIRGULE] = 1;
    suivant[_conjonctionBis_][ALORS] = 1;
    suivant[_conjonctionBis_][FAIRE] = 1;
    suivant[_conjonctionBis_][PARENTHESE_FERMANTE] = 1;
    suivant[_conjonctionBis_][CROCHET_FERMANT] = 1;
    suivant[_conjonctionBis_][VIRGULE] = 1;

    suivant[_negation_][ET] = 1;
    suivant[_negation_][OU] = 1;
    suivant[_negation_][POINT_VIRGULE] = 1;
    suivant[_negation_][ALORS] = 1;
    suivant[_negation_][FAIRE] = 1;
    suivant[_negation_][PARENTHESE_FERMANTE] = 1;
    suivant[_negation_][CROCHET_FERMANT] = 1;
    suivant[_negation_][VIRGULE] = 1;

    suivant[_comparaison_][ET] = 1;
    suivant[_comparaison_][OU] = 1;
    suivant[_comparaison_][POINT_VIRGULE] = 1;
    suivant[_comparaison_][ALORS] = 1;
    suivant[_comparaison_][FAIRE] = 1;
    suivant[_comparaison_][PARENTHESE_FERMANTE] = 1;
    suivant[_comparaison_][CROCHET_FERMANT] = 1;
    suivant[_comparaison_][VIRGULE] = 1;

    suivant[_comparaisonBis_][ET] = 1;
    suivant[_comparaisonBis_][OU] = 1;
    suivant[_comparaisonBis_][POINT_VIRGULE] = 1;
    suivant[_comparaisonBis_][ALORS] = 1;
    suivant[_comparaisonBis_][FAIRE] = 1;
    suivant[_comparaisonBis_][PARENTHESE_FERMANTE] = 1;
    suivant[_comparaisonBis_][CROCHET_FERMANT] = 1;
    suivant[_comparaisonBis_][VIRGULE] = 1;
    suivant[_expArith_][EGAL] = 1;
    suivant[_expArith_][INFERIEUR] = 1;
    suivant[_expArith_][OU] = 1;
    suivant[_expArith_][POINT_VIRGULE] = 1;
    suivant[_expArith_][ALORS] = 1;
    suivant[_expArith_][FAIRE] = 1;
    suivant[_expArith_][PARENTHESE_FERMANTE] = 1;
    suivant[_expArith_][CROCHET_FERMANT] = 1;
    suivant[_expArith_][VIRGULE] = 1;
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
    suivant[_listeExpressions_][PARENTHESE_FERMANTE] = 1;
    suivant[_listeExpressionsBis_][PARENTHESE_FERMANTE] = 1;
}