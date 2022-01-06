#include<bits/stdc++.h>
void swap(int a, int b, int pq[]){
    	int t = pq[a]; 
    	pq[a] = pq[b];
    	pq[b] = t;
}
void heapify(int pq[], int i, int n){
    	int id = i;
        while(true){
                int l = 2*id + 1;
                int r = 2*id + 2;
                if(l < n and r < n){
                        if(pq[id] <= pq[l] and pq[id] <= pq[r]) return;
                        if(pq[l] < pq[r])
                                swap(l, id, pq), id = l;
                        else 
                                swap(r, id, pq), id = r;
                }
                else if(l < n){
                        if(pq[id] <= pq[l]) return;


                        swap(l, id, pq); id = l;
                }
                else 
                    	return;
        }
}
void heapSort(int arr[], int n) {
    	for(int i = n - 1; i >= 0; i--){
            	heapify(arr, i, n);
        }
    	
    	for(int i = n - 1; i >= 0; i--){
            	swap(0, i, arr);
            	
            	heapify(arr, 0, i);
        }
    	
}
