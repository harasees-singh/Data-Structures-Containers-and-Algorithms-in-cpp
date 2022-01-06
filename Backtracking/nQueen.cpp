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

vector<vector<int>> mat;
int n; 
bool safe(int i, int j){
    bool vert = 1;
    bool hori = 1;
    bool northwest = 1;
    bool northeast = 1;
    for(int r = 0; r < n; r++){
        vert = vert and (!mat[r][j]);
    }
    for(int c = 0; c < n; c++){
        hori = hori and (!mat[i][c]);
    }
    for(int r = 0; r < n; r++){
        if(i - r < 0 or j + r == n) break;
        northeast = northeast and (!mat[i - r][j + r]);
    }
    for(int r = 0; r < n; r++){
        if(i + r == n or j - r < 0) break;
        
        northeast = northeast and (!mat[i + r][j - r]);
    }
    for(int r = 0; r < n; r++){
        if(i - r < 0 or j - r < 0) break;
        northwest = northwest and (!mat[i - r][j - r]);
    }
    for(int r = 0; r < n; r++){
        if(i + r == n or j + r == n) break;
        
        northwest = northwest and (!mat[i + r][j + r]);
    }
    return vert and hori and northeast and northwest;
}
void nQueen(int r){
    if(r == n){
        for(int i = 0; i < n*n; i++) cout << mat[i/n][i%n] << ' ';
        cout << endl;
        return;
    }
    for(int j = 0; j < n; j++){
        if(safe(r, j)){
            mat[r][j] = 1;
            nQueen(r + 1);
            mat[r][j] = 0;
        }
    }
}
int main(){
    
    cin >> n;
    mat = vector<vector<int>> (n, vector<int>(n));
    
    nQueen(0);
    
    return 0;
}
