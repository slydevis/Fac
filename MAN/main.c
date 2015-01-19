#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // sleep()
#include <string.h> // strcmp()
#include <time.h>

// Différents algorithmes de tri

#include "bubbleSort.h"
#include "quickSort.h"
#include "mergeSort.h"
#include "selectPermSort.h"
#include "insertSeq.h"
#include "insertDico.h"
#include "radixSort.h"

#define MAX 10

#define NOM_FIC "resultat.csv"

#ifdef DEBUG
	#define MAX_TIME 5.0
#else
	#define MAX_TIME 5.0 * 60
#endif

void (*functor)(int* tab, int size);

int NbCase[] = { 1, 5, 10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000, 5000000, 10000000, 50000000, 100000000, 500000000};

char* currentSort =  "";

int lancerTri(void (*functor)(int*, int), int size)
/* 
 * Génère un tableau aléatoirement et execute un tri 
 * 20 fois et sauvegarde les résultats dans le fichier de sortie 
 */
{
	int *t = (int*) malloc(size * sizeof(int)); // Déclaration d'un tableau dynamique

    clock_t debut, fin;
			
    srand(time(0));

	FILE* fichier = NULL;
 
	fichier = fopen(NOM_FIC, "a+");
	
	if (fichier != NULL)
	{
		fprintf(fichier, "%s;%d;", currentSort, size);
		fclose(fichier);
	}
		
    for(unsigned i = 0; i < 20; ++i)
    {
		debut = clock();
		
		printf("Algo %s : Test = %d, Size = %d", currentSort, i + 1, size);

        for(int i = 0; i < size; ++i)
            t[i] = (int) rand()%100;

#ifdef DEBUG
		int nbToShow = 0;
		
		if(size > MAX)
			nbToShow = MAX;
		else
			nbToShow = size;
		
        printf("\nAvant tri : \n\n");

         for(int i = 0; i < nbToShow; ++i)
             printf("TAB[%d] = %d\n", i, t[i]);
#endif
        (*functor)(t, size);
#ifdef DEBUG
         printf("\nAprès le tri : \n\n");

		for(int i = 0; i < nbToShow; ++i)
			printf("TAB[%d] = %d\n", i, t[i]);
		sleep(2);
#endif		
		fin = clock();
		
		float time = (fin - debut)*1.0/CLOCKS_PER_SEC;
		
		if(time > MAX_TIME) {
			printf(" ======> Erreur temps d'execution trop long (%f)\n", time);
			return -1;
		}
		
		printf(" ======> Temps d'execution = %f sec.\n", time);

        // Crée le fichier de sortie pour l'analyse du temps d'éxecution celons l'algorithme
	 
		fichier = fopen(NOM_FIC, "a+");
		
		if (fichier != NULL)
		{
			fprintf(fichier, "%f;", time);
			fclose(fichier);
		}
		 
        // On vérifie si le tableau est bien trié, sinon erreur fatale
        
		for(int i = 0; i < size - 1; ++i)
		{
			if(t[i] > t[i + 1])
			{
				printf(" ======> Erreur fatale : tableau non trié\n");
				exit(1);
			}
		}		
    }
    
	fichier = fopen(NOM_FIC, "a+");
	
	if (fichier != NULL)
	{
		fprintf(fichier, "\n");
		fclose(fichier);
	}
	
	free(t);
	
	return 0;	
}

void selectSort(int choix)
/* 
 * Choisi le tri adapté celon le choix de l'utilisateur 
 * et lance les tris celons le nombre de taille différente choisi
 * dans le tableau NbCase 
 */
{
	switch(choix)
    {
        case 1:
			printf("\n-----> Insertion séquentielle\n\n");
			functor = &insertSeq; // OK
			currentSort = "Insertion séquentielle";
			break;
        case 2:
			printf("\n-----> Insertion dichotomique\n\n");
			functor = &insertDico; // OK
			currentSort = "Insertion dichotomique";
            break;
		case 3:
			printf("\n-----> Selection-permutation\n\n");
			functor = &selectPermSort; // OK
			currentSort = "Selection-permutation";
			break;
        case 4:
			printf("\n-----> Bubble Sort\n\n");
            functor = &bubbleSort; // OK
            currentSort = "BubbleSort";
            break;
        case 5:
			printf("\n-----> Merge Sort\n\n");
            functor = &mergeSort; // OK
			currentSort = "Merge Sort";
            break;
        case 6:
			printf("\n-----> Quick Sort\n\n");
            functor = &quickSort; // OK
            currentSort = "Quick Sort";
            break;
        case 7:
			printf("\n-----> Tri avec ABR\n\n");
            break;
		case 8:
			printf("\n-----> Heap Sort\n\n");
			return;
			break;
		case 9:
			printf("\n-----> Tri par insertion séquentielle avec liste chaînées\n\n");
			return;
			break;
		case 10:
			printf("\n-----> Tri par base\n\n");
			functor = &radixSort;
			currentSort = "Tri par base"; // OK
			break;
		case 11:
			printf("\n-----> Tri à casiers\n\n");
			return;
			break;
		case 12:
			printf("\n-----> Tri par adressage direct\n\n");
			return;
			break;
        default:
            printf("\nValeur incorrect\n\n");
            return;
        break;
    }

	int k = 0;
    for(unsigned i = 0; (i < sizeof(NbCase)/sizeof(NbCase[0])) && k == 0; ++i)
    {
		#ifdef DEBUG
			if(NbCase[i] == NbCase[0])
				continue;
		#endif
        k = lancerTri(functor, NbCase[i]);
	}
}

int main(int argc, char* argv[]) {
	
	(void) argv;

	if(argc > 1)
	{
		printf("Nombre d'argument invalide\n");
		return 1;
	}
	
	remove(NOM_FIC);

    int choix;

    printf("----- Complexité des tris ------");
    printf("\n\nMenu :\n");
    printf(" 1 - Tri par insertion séquentielle\n");
    printf(" 2 - Tri par insertion dichotomique\n");
    printf(" 3 - Tri par selection-permutation\n");
    printf(" 4 - Tri à bulles\n");
    printf(" 5 - Tri par fusion\n");
    printf(" 6 - Tri rapide (Quicksort)\n");
    printf(" 7 - Tri à l'aide d'arbres binaires de recherche\n");
    printf(" 8 - Tri par tas (Heapsort)\n");
    printf(" 9 - Tri par insertion séquentielle avec liste chaînées\n");
    printf("10 - Tri par base\n");
    printf("11 - Tri à casiers\n");
    printf("12 - Tri par adressage direct\n");
    printf("13 - Tous les tris à la suite\n");
    printf("\nVotre choix ? ");
    scanf("%d", &choix);
    printf("\n------------------------------\n");

	if(choix == 13)
		for(int i = 1; i < 13; ++i)
			selectSort(i);

	selectSort(choix);

    return 0;
}
