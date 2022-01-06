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

int32_t main(){
        FIO 

        return 0;
}

class TreeAncestor {
public:
    int l;
    int N;
    vector<vector<int>> up;
    
    TreeAncestor(int n, vector<int>& parent) {
            N = n;
        
            l = 0;

            int c(N);
            while(c) l++, c/=2;

            up = vector<vector<int>>(N + 1, vector<int>(l + 1, 0));

            for(int i = 1; i <= N; i++){
                    up[i][0] = parent[i - 1] + 1;
            }
            up[1][0] = 0;
            for(int j = 1; j <= l; j++){
                    for(int i = 1; i <= N; i++){
                            up[i][j] = up[up[i][j - 1]][j - 1];
                    }
            }
    }
    
    int getKthAncestor(int node, int k) {
            
            int bit = 0;
            int ret = ++node;
            while(k and ret){   
                    if(k&1)
                        ret = up[ret][bit];
                    k >>= 1;
                    bit++;
            }
            return ret - 1;
    }
};