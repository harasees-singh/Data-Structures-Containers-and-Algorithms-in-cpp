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
void merge(int input[], int size){
    int* arr = new int[size];
    int* t = arr;
    
    int *pt1 = input;
    int *pt2 = input + size/2;

    while(pt1 < input + size/2 and pt2 < input + size){
        
        if(*pt1 < *pt2)
            	*t = *pt1, pt1++;
        
        else
            	*t = *pt2, pt2++;
        t++;
    }
    while(pt1 < input + size/2)
        	*t = *pt1, pt1++, t++;
	while(pt2 < input + size)
        	*t = *pt2, pt2++, t++;
    
    for(int i = 0; i < size; i++)
        	input[i] = arr[i];

    // for(int i = 0; i < 5; i++)
    //         cout << *(arr + i) << endl;
	
    delete []arr;
}
void mergeSort(int input[], int size){
	// Write your code here
    if(size == 1)
        	return;
    
    mergeSort(input, size/2);
    
    mergeSort(input + size/2, (size + 1)/2);
    
    merge(input, size);
    
    // 1 2 3 4
}

int32_t main(){
    FIO 

    int arr[5] = {7, 8, 3, 2, 4};

    mergeSort(arr, 5);
    // merge(arr, 5);

    for(int i = 0; i < 5; i++)
            cout << *(arr + i) << endl;

    return 0;
}
