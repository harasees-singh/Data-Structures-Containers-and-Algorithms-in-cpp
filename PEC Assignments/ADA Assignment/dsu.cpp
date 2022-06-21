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

template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a){in >> a.ff >> a.ss; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> a){out << a.ff << ' ' << a.ss; return out;}
template<typename T, typename T1> T amax(T &a, T1 b){if(b > a) a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b){if(b < a) a = b; return a;}

MOD_DEFINE

struct DisjointSet{
        int N;

        int * Rank;
        int * parent;
        int * treesize;

        DisjointSet(int n){
                N = n;
                Rank = new int[N + 1];
                parent = new int[N + 1];
                treesize = new int[N + 1];
                MakeSet();
        }
        

        void MakeSet(){
                for(int i = 0; i <= N; i++)
                        parent[i] = i, Rank[i] = 0, treesize[i] = 1;
        }

        int findParent(int v){

                if(parent[v] == v)
                        return v;
                
                return parent[v] = findParent(parent[v]);
        }

        void Union(int u, int v){

                u = findParent(u), v = findParent(v);

                if(Rank[u] > Rank[v])
                        parent[v] = u, treesize[u] += treesize[v];
                else if(Rank[u] < Rank[v])
                        parent[u] = v, treesize[v] += treesize[u];
                else        
                        parent[v] = u, Rank[u]++, treesize[u] += treesize[v];
        }
        int nodecnt(int i){
                i = findParent(i);

                return treesize[i]; // node cnt including the parent itself
        }
        ~DisjointSet(){
                delete []parent;
                delete []Rank;
                delete []treesize;
        }
};
int32_t main(){
        FIO 

        DisjointSet dsu(1e5);

        int n; cin >> n;

        int m; cin >> m;

        int rem = 0;

        for(int i = 0; i < m; i++){
            int u, v; cin >> u>> v;

            if(dsu.findParent(u) != dsu.findParent(v)){
                dsu.Union(u, v);
            }
            else rem++;
        }
        int add = 0;
        for(int i = 1; i < n; i++){
            if(dsu.findParent(i) != dsu.findParent(1)){
                if(rem) dsu.Union(i, 1);

                else{
                    cout << -1; return 0;
             
             
               }
               rem--;

               add++;
            }
        }
        cout << "Minimum number of additions required = " << add << endl;

        return 0;
}
