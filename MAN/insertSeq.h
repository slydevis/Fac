#ifndef __INSERTSEQ_H__
#define __INSERTSEQ_H__

void insertSeq(int* tab, int n)
/* 
 * Execute l'algorithme de tri insertion séquentielle pour un tableau
 * de taille n
 */
{
	for(int i = 1; i < n; ++i)
	{
		int tmp = tab[i];
		int j = i;
		while(j > 0 && tab[j - 1] > tmp)
		{
			tab[j] = tab[j - 1];
			j--;
		}
		tab[j] = tmp;
	}
}

#endif /* __INSERTSEQ_H__ */
