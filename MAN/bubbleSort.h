#ifndef __BUBBLESORT_H__
#define __BUBBLESORT_H__

void bubbleSort(int* tab, int size)
{
	  int echange_effectue;
	  do
	  {
		  echange_effectue = 0;
		  for(int j = 0; j < size - 1; ++j)
		  {
			  if(tab[j] > tab[j+1]) 
			  {
				  echange_effectue = 1;

				  // swap(&tab[j], &tab[j+1]);
				  
				  int buff;
				  buff = tab[j];
				  tab[j] = tab[j+1];
				  tab[j + 1] = buff; 
			  }
		   }
		   size = size - 1;
       }
       while (echange_effectue == 1);       
}

#endif // __BUBBLESORT_H__
