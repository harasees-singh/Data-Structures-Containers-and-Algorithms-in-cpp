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

int subset(int input[], int n, int output[][25]) {
    if(n == 1){
        
        	output[0][0] = 0;
        	output[1][0] = 1; output[1][1] = *(input);
        	return 2;
    }
        	
	int curr = *(input + n - 1);
    
    int size_of_output = subset(input, n - 1, output);
    
    for(int i = 0; i < size_of_output; i++){
        	output[size_of_output + i][0] = output[i][0] + 1;
        	for(int j = 1; j <= output[i][0]; j++)
                	output[size_of_output + i][j] = output[i][j];
        	
        	output[size_of_output + i][output[size_of_output + i][0]] = curr;
                	
    }
    
    return size_of_output*2;
}	

int subsetSumToK(int input[], int n, int output[][50], int k) {
    int cnt = (1 << n);
	int S = cnt;
    int pt = 0;

    int arr[S][25];

    subset(input, n, arr);
    
    int ret = 0;
    
    for(int i = 0; i < S; i++){
        	
        int limit = arr[i][0];
        
        int Sum = 0;
        
        for(int j = 1; j <= limit; j++)
            		Sum += arr[i][j];
        if(Sum == k){
            	output[pt][0] = arr[i][0];
            	for(int k = 1; k <= output[pt][0]; k++)
                    		output[pt][k] = arr[i][k];
            	pt++;
            	ret++;
        }
        
    }
    return ret;
}
int32_t main(){
    FIO 
    cout << "ESU" << endl;cout.flush();
    int arr[] = {17, 18, 6, 11, 2, 4};



    int output[1000][50];

    cout << subsetSumToK(arr, 6, output, 6) << endl;

    // cout << output[0][0] << endl; 
    // cout << output[0][1] << endl;
    // cout << output[1][2] << endl;

    return 0;
}
