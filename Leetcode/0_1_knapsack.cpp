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

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n){
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT32_MIN));
        
        dp[0][0] = 0; // dp[m][n];
        
        // m ones and n zeroes
        
        for(auto p : strs){
            int M = count(p.begin(), p.end(), '0');
            
            int N = count(p.begin(), p.end(), '1');
            vector<vector<int>> cpy(dp);
            
            for(int i = 0; i <= m; i++)
                for(int j = 0; j <= n; j++){
                    if(dp[i][j] != INT32_MIN){
                        if(i + M <= m and j + N <= n) cpy[i + M][j + N] = max(dp[i + M][j + N], dp[i][j] + 1);
                    }
                }
            dp = cpy;
            
        }
        // for(auto p : dp) {for(auto q : p) cout << q << ' '; cout << endl;}
        int mx = 0;
            
        for(auto &p : dp) mx = max(mx, *max_element(p.begin(), p.end()));
        
        return mx;
    }
};

int32_t main(){
        FIO 

        return 0;
}
