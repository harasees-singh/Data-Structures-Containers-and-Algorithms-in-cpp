#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#define ff                              first
#define ss                              second
#define infinity                        999999999999999999
#define sz(v)                           ((int)(v).size())
#define all(v)                          (v).begin(),(v).end()
#define MOD_DEFINE                      const int MOD = 1e9 + 7;
#define endl                            '\n'
#define space                           " "
#define int                             long long
#define pii                             pair<int, int>
#define vi                              vector<int>
#define pb(n)                           push_back(n)
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define test_cases_loop int t;          cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define fps(x,y)                        fixed<<setprecision(y)<<x

MOD_DEFINE
void swap(int &a, int &b){
    	int t = a; 
    
    	a = b;
    	b = t;
}
int partition(int* input, int size){
    	
    	// return index of partition.
    
    	int ele = *input;
    	
    	int cnt = 0;
    
    	for(int i = 0; i < size; i++)
            	cnt += (input[i] < ele);
    
    	int i = 0, j = size - 1;
    
    	swap(input[0], input[cnt]);
    
    	while(i < j)
            	if(input[i] >= ele)
                    
                    	if(input[j] < ele)
                            	swap(input[i], input[j]), i++, j--;
    					else 
                            	j--;
				else
                    	i++;
    	
    	return cnt;
    	
}

void quickSort(int input[], int size) {
		
    	if(size == 1 or size == 0)
            	return;
    	
    	int p = partition(input, size);
    	
    	quickSort(input, p);
    
    	quickSort(input + p + 1, size - (p + 1));

}
int32_t main(){
	int arr[] = {27, 17, 02, 13, 19, 07, 18};

	quickSort(arr, 7);
	for(int i = 0;i < 7; i++) cout << arr[i] << ' '; 
	
    return 0;
}
