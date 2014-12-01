#ifndef __BUBBLESORT_H__
#define __BUBBLESORT_H__

void bubbleSort(int* t, int n)
/* 
 * Execute l'algorithme du tri à bulle pour un tableau de taille n 
 */
{
	int i, j;
	i = 0;
	while(i < n - 1)
	{
		j = n - 1;
		while(j > i)
		{
			if(t[j] < t[i])
			{
				int tmp;
				tmp = t[i];
				t[i] = t[j];
				t[j] = tmp;
			}
			--j;
		}
		++i;
	}
}

#endif // __BUBBLESORT_H__
