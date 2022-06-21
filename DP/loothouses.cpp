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
vector<pair<int, int>> dp(10001);
int dontloot(int i){
    if(i) return max(dp[i - 1].first, dp[i - 1].second);
    
    return 0;
}
int loot(int i, int *arr){
    if(i) return arr[i] + dp[i - 1].second;
    
    return arr[i];
}
int maxMoneyLooted(int *arr, int n){
    if(n == 0) return 0;
	for(int i = 0; i < n; i++) dp[i] = {loot(i, arr), dontloot(i)};
    
    return max(dp[n - 1].first, dp[n - 1].second);
}
int32_t main(){
        FIO 

        return 0;
}
