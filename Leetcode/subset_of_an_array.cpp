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
int subset(int input[], int n, int output[][20]) {
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
int32_t main(){
    FIO 

    return 0;
}
