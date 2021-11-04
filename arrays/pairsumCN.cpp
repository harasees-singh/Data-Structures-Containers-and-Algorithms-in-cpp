#include<bits/stdc++.h>
using namespace std;
int pairSum(int *arr, int n, int num)
{
    	sort(arr, arr + n);
    	int i = 0, j = n - 1;
    	int cnt = 0;
    	while(i < j){
            	while(i < j and arr[i] + arr[j] > num)
                    	j--;
            	if(arr[i] + arr[j] == num){
            
            		if(arr[i] == arr[j])
                    		return cnt + (j - i + 1)*(j - i)/2;
                    
                    int curr = arr[j];
                    // cnt++;
                    int secpt = j;
                    
                    while(secpt > i  and arr[secpt] == curr)
                        	secpt--, cnt++;
                    
            	}
            
            	i++;
        }
    	return cnt;
}