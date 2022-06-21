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
// finding strongly connected components and 
// condensation graph
vector<vi> g, g_rev;

vi scc;

vi order;
vi vis;
void topo_sort(int i){
        if(vis[i]) return;
        vis[i] = 1;

        for(auto p : g[i]) topo_sort(p);

        order.pb(i);
}
void dfs(int i){
        // push if not visited 
        // one scc formed after one dfs run
        // run dfs on the transpose graph
        if(vis[i]) return;
        vis[i] = 1;
        scc.pb(i);

        for(auto p : g_rev[i]){
                dfs(p);
        }
}

int32_t main(){

        FIO 

        int n, m; cin >> n >> m;

        g = vector<vi>(n + 1); g_rev = g;


        for(int i = 0; i < m; i++){
                int u, v; cin >> u >> v;

                g[u].pb(v);
                g_rev[v].pb(u);
        }
        vis = vi(n + 1);

        for(int i = 1; i <= n; i++) topo_sort(i);

        reverse(all(order));

        assert(sz(order) == n);

        vis = vi(n + 1);

        for(int i = 0; i < n; i++){
                scc = vi();

                if(!vis[order[i]]) dfs(order[i]);

                if(sz(scc)){ for(auto p : scc) cout << p << ' '; cout << endl;}
        }

        return 0;
}
