#ifndef __MERGESORT_H__
#define __MERGESORT_H__

void fusion(int* t, int g, int m, int d)
/*
 * Fais le tri de deux sous tableau fus et t et ensuite fussionne
 * ces deux derniers
 */
{
	int i, pG = g, pD = m + 1;
	
	int *fus = (int*) malloc((m - g + 1)*sizeof(int));
	
	for(i = g; i <= m; ++i)
		fus[i - g] = t[i];
		
	for(i = g; i <= d; ++i)
	{
		if(pG == m + 1)
			break;
		else if(pD == d + 1 || fus[pG - g] < t[pD])
		{
			t[i] = fus[pG - g];
			pG++;
		}
		else
		{
			t[i] = t[pD];
			pD++;
		}
	}
	
	free(fus);
}

void mergedSort(int* tab, int g, int d)
/* 
 * Fait l'algorithme du tri fusion sur un tableau borné
 */
{
	int m;
	if(g < d)
	{
		m = (g+d)/2;
		mergedSort(tab, g, m);
		mergedSort(tab, m + 1, d);
		fusion(tab, g, m, d);
	}
}
 
void mergeSort(int* tab, int size)
/* 
 * Lance l'algorithme du tri fusion pour un tableau de taille n 
 */
{
	mergedSort(tab, 0, size - 1);
}

#endif // __MERGESORT_H__
