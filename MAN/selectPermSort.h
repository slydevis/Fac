#ifndef __SELECTPERMSORT_H__
#define __SELECTPERMSORT_H__

void selectPermSort(int* t,int n) {
/* 
 * Exécute le tri sélection permutation sur un tableau de taille n 
 */ 
	int i, j, min;
	i = 0;
	j = 0;
	min = 0;
	while(i < n-1)
	{
		min = i;
		j = i + 1;

		while(j < n)
		{
			if(t[j] < t[min]) 
				min = j;

			j = j + 1;
		}
		int tmp = t[i];
		t[i] = t[min];
		t[min] = tmp;
		i = i + 1;
	}
}

#endif /* __SELECTPERMSORT_H__ */
