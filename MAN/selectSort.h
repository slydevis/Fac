/*void selectSort(int*t,int n) { 
	int i,k;
	int s = 0; 
	int nb[n]; 
	int res [n]; 
	
	for (i=0;i<n;i++){ 
		for(k=0;k<n;k++){ 
			if(t[i]>t[k]){
				s++;
				nb[i]=s;
			}
			res[s]=t[i];s=0;
		}
		for(i=0;i<n;i++)
			t[i]=res[i];
	}
}*/
