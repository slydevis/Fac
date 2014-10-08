#ifndef __MERGESORT_H__
#define __MERGESORT_H__

/*void fusion(int g, int m, int d, int* t)
{
	int i, pG = g, pD = m+1;
	int* fus = (int*) malloc((m - g + 1) * sizeof(int));
	for(i = g; i <= m; ++i)
		fus[i - g] = t[i];
		
	for(i = g; i <= d; i++) 
	{
		if(pG == m+1)
			break;
		else if(pD == d+1 || fus[pG - g] < t[pD])
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
}*/

void mergedSort(int* arr, int l, int h) {
	int i = 0;
	int length = h - l + 1;
	int pivot  = 0;
	int merge1 = 0;
	int merge2 = 0;
	int temp[100];

	if(l == h)
		return;

	pivot  = (l + h) / 2;

mergedSort(arr, l, pivot);
mergedSort(arr, pivot + 1, h);

for(i = 0; i < length; i++)
{
temp[i] = arr[l + i];
}

merge1 = 0;
merge2 = pivot - l + 1;

for(i = 0; i < length; i++) 
{
if(merge2 <= h - l)
{
if(merge1 <= pivot - l)
{
if(temp[merge1] > temp[merge2])
{
 arr[i + l] = temp[merge2++];
}

else
{
 arr[i + l] = temp[merge1++];
}
}

else
{
arr[i + l] = temp[merge2++];
}
}

else
{
arr[i + l] = temp[merge1++];
}
}
}

void mergeSort(int* tab, int size) {
	mergedSort(tab, 0, size);
}

#endif // __MERGESORT_H__
