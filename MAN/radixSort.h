#ifndef __RADIXSORT_H__
#define __RADIXSORT_H__

void radixSort(int* tab, int n)
/*
 *  Execute l'algorithme du tri par base pour un tableau de taille n
 */
{
	// On recherche la plus grande valeur dans le tableau

	int max = tab[0];	
	for (int i = 1; i < n; i++) {
		if (tab[i] > max)
			max = tab[i];
	}

	int *tmp = malloc(n* sizeof(int*));
	int *bucket = calloc(10, sizeof(int*));

	// Tant qu'on est pas dans l'exposant du plus grand élément (10^exp = phase courante)

	int exp = 1;
	while (max/exp > 0) {
		
		// On initialise tmp pour avoir toutes ses valeurs à 0
		
		memset(bucket, 0, 10*sizeof(int*));

		// On compte le nombre de valeur qui vont être dans case du tableau bucket
		
		for (int i = 0; i < n; i++) {
			int unite = (tab[i]/exp)%10;
			++bucket[unite];
		}

		// On incremente pour savoir le nombre d'élément avant l'indice précédant
		
		for (int i = 1; i < 10; i++) {
			bucket[i] += bucket[i - 1];
		}

		// On place la valeur correspondant dans le tableau tmp
		
		for (int i = n - 1; i >= 0; i--) {
			int unite = (tab[i]/exp)%10;
			--bucket[unite];
			int indiceBuck = bucket[unite];
			tmp[indiceBuck] = tab[i];
		}

		for (int i = 0; i < n; i++)
			tab[i] = tmp[i];

		exp *= 10;
	}

	free(bucket);
	free(tmp);
}

#endif /* __RADIXSORT_H__ */
