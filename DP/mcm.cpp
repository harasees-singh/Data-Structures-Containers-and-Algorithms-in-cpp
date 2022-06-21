// ਹਰਅਸੀਸ ਸਿੰਘ 
#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#define ff                              first
#define ss                              second
#define infinity                        8999999999999999999
#define sz(v)                           ((int)(v).size())
#define all(v)                          (v).begin(),(v).end()
#define MOD_DEFINE                      const int MOD = 1e9 + 7;
#define endl                            '\n'
#define int                             long long
#define pii                             pair<int, int>
#define vi                              vector<int>
#define pb(n)                           push_back(n)
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define w(t)                            int t; cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define pqb                             priority_queue<int>
#define pqs                             priority_queue<int, vi, greater<int>>
#define fps(x,y)                        fixed<<setprecision(y)<<x

MOD_DEFINE
vector<vector<int>> dp(101, vector<int> (101, -1));
int help(int *arr, int i, int j){
    if(i > j - 2) return 0;
    
    if(i == j - 2) return arr[i]*arr[i + 1]*arr[i + 2];
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int mn = INT32_MAX;
    
    for(int it = i + 1; it < j; it++){
        mn = min(mn, help(arr, i, it) + help(arr, it, j) + arr[i]*arr[it]*arr[j]);
    }
    return dp[i][j] = mn;
}

int matrixChainMultiplication(int* arr, int n) {

    return help(arr, 0, n);
}

int32_t main(){
        FIO 

        return 0;
}
