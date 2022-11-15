// ਹਰਅਸੀਸ ਸਿੰਘ

#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
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
#define pb(n)                           push_back((n))
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define w(T)                            int T; cin >> T; while(T--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define pqb                             priority_queue<int>
#define pqs                             priority_queue<int, vi, greater<int>>
#define fps(x, y)                       fixed<<setprecision(y)<<x
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a){in >> a.ff >> a.ss; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> a){out << a.ff << ' ' << a.ss; return out;}
template<typename T, typename T1> T amax(T &a, T1 b){if(b > a) a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b){if(b < a) a = b; return a;}
template<typename T> istream& operator>>(istream &in, vector<T> &v) { for (auto &x : v) in >> x; return in;}
template<typename T> ostream& operator<<(ostream &out, vector<T> &v) {out << "{ "; for (auto &x : v) out << x << " "; out << "}\n"; return out;}
template<typename T, typename... Args> void prn(T x, Args... args) {cout << x << " "; prn(args...);}
template<typename Iterable> void prnIter(const Iterable& ITER, ostream&out = cout){ auto x = ITER.begin(); out << "{ "; for (; x != ITER.end(); ++x) out << *x << ' '; out << "}" << endl;}

MOD_DEFINE
// A cactus is a graph where every edge (or sometimes, vertex) belongs to at most one simple cycle
vector<vector<int>> g; // graph
vector<int> out, in;
vector<bool> vis;
set<pair<int, int>> span_edges; 
vector<int> d;

void dfsTree(int u){
        vis[u] = 1;
        for(int p : g[u]){
            if(not vis[p]){
                d[p] = d[u] + 1;
                span_edges.insert({u, p});
                dfsTree(p);
            }
        }
        for(int p : g[u]){
            if(not span_edges.count({u, p})){
                if(d[p] > d[u]){ // p is in the subtree of u
                    out[u]++; in[p]++;
                }
            }
        }
}
// compress cycles to nodes
int pt;

vector<int> cycleID;
void compress(int u){
        for(int v : g[u]){
            if(span_edges.count({u, v}))
                compress(v);
        }
        if(in[u]){
            cycleID[u] = pt++;
        }
        else{
            cycleID[u] = u;
            for(int v : g[u]){
                if(span_edges.count({u, v}) and ! out[v]){

                    if(cycleID[v] != v) cycleID[u] = cycleID[v];
                }
            }
        }
}
void slv(){
        int n; cin >> n; 
        pt = n + 1;
        g = vector<vector<int>> (n + 1);

        int m; cin >> m; 

        assert(m >= n - 1); 

        // algorithm works for connected undirected graphs

        for(int i = 0; i < m; i++){
            int u, v; cin >> u >> v; 

            g[u].push_back(v);
            g[v].push_back(u);
        }
        vis = vector<bool> (n + 1);
        out = vector<int> (n + 1); // number of back-edges starting from u and ending on some node in it's subtree
        in = vector<int> (n + 1); // number of back-edges starting from some ancestor of u and ending at u.
        d = vector<int> (n + 1);
        cycleID = vector<int> (n + 1);

        dfsTree(1);

        compress(1);

        cout << cycleID;
}

int32_t main(){
        
        FIO

        slv();
        
        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/