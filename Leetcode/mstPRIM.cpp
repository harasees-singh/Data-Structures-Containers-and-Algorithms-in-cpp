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

const int N;

set<pii> Heap;

int key[];

int vis[];

int parent[];

vector<vector<pair<int, int>>> g;
// {v, w};
// in uth row store {v, w};
// in vth row store {u, w};

void mstPRIM(int r){
        
        // root 

        for(int i = 0; i < N; i++){
                key[i] = infinity;
                vis[i] = 0;
                // vis = 0 it's not a part of our mst;
        }
        key[r] = 0;
        parent[r] = -1;

        for(int i = 0; i < N; i++){
                Heap.insert({key[i], i});
        }

        for(int i = 0; i < N; i++){
                auto p = *Heap.begin();
                Heap.erase(p);
                int ky = p.first;
                int id = p.second;

                for(auto q : g[id]){
                        
                        if(!vis[q.first] and key[q.first] > q.second){
                                
                                Heap.erase({key[q.first], q.first});
                                key[q.first] = q.second;
                                parent[q.first] = id;
                                Heap.insert({q.second, q.first});
                        }
                }
                vis[id] = 1;
        }
}
// q
// u
// {v, w}
// w, key[v];

int32_t main(){
        FIO 



        return 0;
}
