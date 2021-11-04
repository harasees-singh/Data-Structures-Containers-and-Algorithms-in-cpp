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
#define pqb                             priority_queue<int>
#define pqs                             priority_queue<int, vi, greater<int>>
#define fps(x,y)                        fixed<<setprecision(y)<<x
#define ll                              long long
MOD_DEFINE


void knapsack_less_weight()
{
    int n, w;
    cin >> n >> w;

    vector<ll> wt(n + 1), val(n + 1);

    for(int i = 0; i < n; i++)
        cin >> wt[i + 1] >> val[i + 1];
    
    vector<vector<ll>> dp(n + 1, vector<ll>(w + 1));

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= w; j++)
        {
            if (wt[i] > j)
                dp[i][j] = dp[i - 1][j];
                
            else if(dp[i - 1][j - wt[i]] != 0 or j - wt[i] == 0)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wt[i]] + val[i]);
        }
    }

    int maxi = 0;

    l(i, 0, w + 1){
            maxi = max(maxi, dp[n][i]);
    }
    cout << maxi << endl;
}

int32_t main(){
    FIO 

    knapsack_less_weight();

    return 0;
}
