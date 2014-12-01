#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

void echanger(int* t, int p, int i)
/* 
 * Permet d'échanger deux case d'un tableau entre elles 
 */
{
	int tmp = t[p];
	t[p] = t[i];
	t[i] = tmp;
}

void quickSortRec(int* tab, int g, int d)
/* 
 * Execute l'algorithme du Quick sort pour trier un tableau 
 * tab[g...d] non trié 
 */
{
    int gauche = g-1;
    int droite = d+1;
    const int pivot = tab[g];
	
	if(g >= d)
        return;
        
    // On sélectionne notre pivot
    
    while(1)
    {
        do droite--; while(tab[droite] > pivot);
        do gauche++; while(tab[gauche] < pivot);

        if(gauche < droite)
            echanger(tab, gauche, droite);
        else break;
    }
    
	quickSortRec(tab, g, droite);
	quickSortRec(tab, droite+1, d);
}

void quickSort(int* tab, int size)
/* 
 * Fonction appelé dans le fichier principal qui lance 
 * quickSortRec qui est un algorithme récursif 
 */
{
	quickSortRec(tab, 0, size - 1);
}

#endif // __QUICKSORT_H__

