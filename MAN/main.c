// Tri insertion séquentielle ====> TP
// Tri insertion dichotomique ====> TD
// Tri par sélection permutation ====> Cours
// Tri à bulles ====> Cours
// Tri par fusion ====> Cours + TD
// Tri rapide ====> Cours + TD2
// Tri avec ABR ====> ....
// Tri par tas ====> TD3
// Tri par insertion séquentielle avec liste chaînées ====> VOUS
// Tri par base ====> VOUS
// Tri à casiers ====> VOUS
// Tri par adressage direct ====> VOUS + COURS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Différents algorithmes de tri

#include "bubbleSort.h"
#include "quickSort.h"
#include "mergeSort.h"
#include "heapSort.h"
#include "selectSort.h"

#define MAX 10 // Nombre de case à afficher afin de vérifier les algorithmes
#define MAX_TIME 5.0 /*5.00000 * 60*/

void (*functor)(int* tab, int size);

int NbCase[] = { 1, 5, 10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000, 5000000, 10000000, 50000000, 100000000, 500000000};

char* currentSort =  "";

int lancerTri(void (*functor)(int*, int), int size)
{
    int *t = (int*) malloc(size * sizeof(int)); // Déclaration d'un tableau dynamique

    clock_t debut, fin/*, timer*/;
			
    srand(time(0));
        
    for(unsigned i = 0; i < 20; ++i)
    {
		debut = clock();
		
		printf("Algo %s : Test = %d, Size = %d", currentSort, i + 1, size);

        for(int i = 0; i < size; ++i)
            t[i] = (int) rand()%100;

//		int nbToShow = 0;
		
//		if(size > MAX)
//			nbToShow = MAX;
//		else
//			nbToShow = size;
		
//        printf("\nAvant tri : \n\n");

//         for(int i = 0; i < nbToShow; ++i)
//             printf("TAB[%d] = %d\n", i, t[i]);

        (*functor)(t, size);

//         printf("\nAprès le tri : \n\n");

//		for(int i = 0; i < nbToShow; ++i)
//			printf("TAB[%d] = %d\n", i, t[i]);
        
		
		fin = clock();
		
		float time = (fin - debut)*1.0/CLOCKS_PER_SEC;
		
		if(time > MAX_TIME) {
			printf(" ======> Erreur temps d'execution trop long (%f)\n", time);
			return -1;
		}
		
		printf(" ======> Temps d'execution = %f ms\n", time);

        // Crée le fichier de sortie pour l'analyse du temps d'éxecution

		FILE* fichier = NULL;
	 
		fichier = fopen("resultat.csv", "a");
	
		if (fichier != NULL)
		{
			fprintf(fichier, "%s;%d;%d\n", currentSort, i + 1, size);
			fclose(fichier);
		}
		 
        // On vérifie si le tableau est bien trié
        
		for(int i = 0; i < size - 1; ++i)
		{
			if(t[i] > t[i + 1])
			{
				printf(" ======> Erreur tableau non trié\n");
				exit(1);
			}
		}		
    }    
	return 0;	
}

void selectSort(int choix)
{
	switch(choix)
    {
        case 1:
        case 2:
			printf("\n-----> Fonction non implémenté\n\n");
			return;
            break;
		case 3:
			printf("\n-----> Fonction non implémenté\n\n");
			//tri = &selectSort;
			return;
			break;
        case 4:
			printf("\n-----> Bubble Sort\n\n");
            functor = &bubbleSort;
            currentSort = "BubbleSort";
            break;
        case 5:
			printf("\n-----> Merge Sort\n\n");
            //functor = &mergeSort; // TODO : Résoudre l'erreur de segmentation
			currentSort = "Merge Sort";
            return;
            break;
        case 6:
			printf("\n-----> Quick Sort\n\n");
            functor = &quickSort;
            currentSort = "Quick Sort";
            break;
        case 7:
			printf("\n-----> Fonction non implémenté\n\n");
			return;
            break;
		case 8:
			printf("\n-----> Heap Sort\n\n");
			// currentSort = "Heap Sort";
			// functor = &heapSort;
			break;
        default:
            printf("\nValeur incorrect\n\n");
            return;
        break;
    }

	int k = 0;
    for(unsigned i = 0; (i < sizeof(NbCase)/sizeof(NbCase[0])) && k == 0; ++i)
        k = lancerTri(functor, NbCase[i]);
}

int main(int argc, char* argv[]) {
	
	(void) argv;

	if(argc > 1)
	{
		printf("Erreur trop d'argument\n");
		return 1;
	}
	
    int choix;

    printf("----- Complexité des tris ------");
    printf("\n\nMenu :\n");
    printf("1 - Tri par insertion séquentielle\n");
    printf("2 - Tri par insertion dichotomique\n");
    printf("3 - Tri par selection-permutation\n");
    printf("4 - Tri à bulles\n");
    printf("5 - Tri par fusion\n");
    printf("6 - Tri rapide (Quicksort)\n");
    printf("7 - Tri à l'aide d'arbres binaires de recherche\n");
    printf("8 - Tri par tas (Heapsort)\n");
    printf("9 - Tous les tris à la suite\n");
    printf("\nVotre choix ? ");
    scanf("%d", &choix);
    printf("\n------------------------------\n");

	if(choix == 9)
		for(int i = 1; i < 9; ++i)
			selectSort(i);

	selectSort(choix);

    return 0;
}
