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

// dsu

int parent[];
const int N = 90;

int findParent(int i){
        if(parent[i] == i)
                return i;
        return findParent(parent[i]);
}

void MakeSet(){
        for(int i = 0; i < N; i++){
                parent[i] = i;
        }
}


void Union(int u, int v){
        u = findParent(u);
        v = findParent(v);

        // parent[u] = u;
        // parent[v] = v;

        parent[u] = v;
}
// kruskal

vector<pair<int, pair<int, int>>> edges;
// {w, {u, v}}

// {1, 2, 3} => 2
// union(3, 4)
// {1, 2, 3, 4} => 2
// {5, 6} => 5
vector<vi> g;

void Kruskal(){
        sort(edges.begin(), edges.end());

        for(auto p : edges){
                int w = p.first;

                int u, v;

                u = p.second.first;
                v = p.second.second;


                if(findParent(u) != findParent(v)){    
                        // O(1)    
                        Union(u, v);

                        g[u].pb(v);
                        g[v].pb(u);
                }
        }
}       
// ElgE
// E < V^2
// lgE similar to lgV
// ElgV

int32_t main(){
        FIO 
        MakeSet();
        return 0;
}
