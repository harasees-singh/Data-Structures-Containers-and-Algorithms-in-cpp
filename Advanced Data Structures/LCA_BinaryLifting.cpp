// ਹਰਅਸੀਸ ਸਿੰਘ 
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

vector<vector<int>> up, g;

int t, l;

const int N = 500001;

vi tin, tout;

void dfs(int root, int p){
        tin[root] = ++t;

        up[root][0] = p;

        for(int i = 1; i <= l; i++)
                up[root][i] = up[up[root][i - 1]][i - 1]; 
        
        for(auto u : g[root])
                if(u != p)
                        dfs(u, root);
        
        tout[root] = ++t;
        
}
bool isAncestor(int u, int v){
        return (tin[u] <= tin[v] and tout[u] >= tout[v]);
}
int lca(int u, int v){
        if(isAncestor(u, v))
                return u;
                
        if(isAncestor(v, u))
                return v;

        for(int i = l; i >= 0; i--)
                if(!isAncestor(up[u][i], v))
                        u = up[u][i];

        return up[u][0];
}
void preprocess(int root){
        tin = tout = vector<int>(N);
        // tout[0] = infinity;

        t = 0;

        l = 0;

        int c(N);
        while(c) l++, c/=2;

        up = vector<vector<int>>(N, vector<int>(l + 1));

        dfs(root, root);
}

int32_t main(){
        FIO 

        int n; cin >> n;
        
        g = vector<vector<int>>(n + 1);

        for(int i = 0; i < n - 1; i++){
                int u, v; cin >> u >> v;

                g[u].push_back(v), g[v].push_back(u);
        }

        preprocess(1);

        cout << lca(5, 11) << endl;

        cout << lca(2, 12) << endl;

        return 0;
}
