#ifndef __INSERTDICO_H__
#define __INSERTDICO_H__

int DicoPos(const int * tab, int value, int beg, int end)
/* 
 * Execute l'algorithme de la recherche dichotomique afin de trouver
 * la position d'insertion dans l'algorithme de tri insertion 
 * dichotomique 
 */
{
    if(value > tab[end])
        return end;

    int pos;
    
    while(beg != end)
    {
        pos = (beg+end)/2;

        if(value < tab[pos])
            end = pos;
        else
            beg = pos+1;
    }

    return beg;
}

void insertDico(int* tab, int n)
/* 
 * Execute l'algorithme de l'insertion dichotomique pour un 
 * tableau tab de taille n
 */
{
	int val;
	int pos;
	for(int i = 1; i < n; ++i)
	{
		val = tab[i];
		pos = DicoPos(tab, val, 0, i);
		
		for( int j = i; j >= pos; --j )
			tab[j] = tab[j-1];
			
		tab[pos] = val;
	}
}

#endif /* __INSERTDICO_H__ */
