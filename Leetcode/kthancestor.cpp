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
class TreeAncestor {
public:
    vector<vector<int>> g;
    int t, l;
    int N;
    vector<vector<int>> up;
    void dfs(int root, int p){
        //     cout << "ok " << endl; cout.flush();
            up[root][0] = p;

            for(int i = 1; i <= l; i++)
                    up[root][i] = up[up[root][i - 1]][i - 1]; 

            for(auto u : g[root])
                    if(u != p)
                            dfs(u, root);
        //     cout << "OK" << endl; cout.flush();
    }
    
    int get(int u, int k){
                if(k > l or !up[u][k]) return -1;
                return up[u][k];
    }
    void preprocess(){
            t = 0;

            l = 0;

            int c(N);
            while(c) l++, c/=2;

            ++l;

            up = vector<vector<int>>(N + 1, vector<int>(l + 1, 0));

        //     cout << "OK" << endl; cout.flush();
            dfs(1, 0);
    }
    TreeAncestor(int n, vector<int>& parent) {
            N = n;
        
            g = vector<vector<int>> (N + 1);
                    
            for(int i = 1; i < n; i++){
                    g[i + 1].push_back(parent[i] + 1);
                    g[parent[i] + 1].push_back(i + 1);
            }    
        //     cout << "OK" << endl; cout.flush();
            preprocess();
    }
    
    int getKthAncestor(int node, int k) {
            
            int bit = 0;
            int ret = ++node;
            while(k){   
                        if(k&1)
                            ret = get(ret, bit);
                        if(ret == -1) break;
                        k >>= 1;
                        bit++;
            }
            return ret - 1;
    }
};
int32_t main(){
        FIO 

        vi parent = {-1, 0, 0, 2, 2};

        auto obj = new TreeAncestor(5, parent);

        cout << obj->getKthAncestor(3, 2) << endl;

        return 0;
}
