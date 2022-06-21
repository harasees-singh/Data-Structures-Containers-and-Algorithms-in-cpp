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
long long power(int a, int b){
    if(b == 0) return 1;
    if(b == 1) return a;
    
    long long ret = power(a, b/2);
    return ret*ret*(b%2 ? a : 1);
}
vector<vector<long long>> dp(2, vector<long long> (1e4 + 1));
int getAllWays(int a, int b) {
	dp[0][0] = 1;
    for(int i = 1; power(i, b) <= a; i++){
        for(int j = 0; j + power(i, b) <= a; j++){
            if(dp[0][j])
                dp[1][j + power(i, b)] += dp[0][j];
        }
        for(int j = 0; j < dp[0].size(); j++) dp[0][j] += dp[1][j], dp[1][j] = 0;
    }
    return dp[0][a];
}
int32_t main(){
        FIO 

        return 0;
}
