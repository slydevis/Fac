#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

#include "Util.h"

// TODO : Optimiser et Personnalisé

void quickSortRec(int* arr, int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };

      /* recursion */

      if (left < j)
            quickSortRec(arr, left, j);
      if (i < right)
            quickSortRec(arr, i, right);
}

void quickSort(int* tab, int size)
{
	quickSortRec(tab, (int)0, size);
}
#endif // __QUICKSORT_H__

