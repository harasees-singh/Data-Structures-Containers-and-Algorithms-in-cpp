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
int N;
vector<vector<bool>> board;
void printboard(){
    for(auto &p : board) {for(auto q : p) {cout << (q ? 'Q' : '_');} cout << endl;} cout << endl;
}
bool safe(int i, int j){
    for(int r = 0; r < N; r++){
        if(r == i) continue;

        if(board[r][j]) return false;
    }
    for(int c = 0; c < N; c++){
        if(c == j) continue;
        if(board[i][c]) return false;
    }
    for(int d = 1; ; d++){
        if(i - d < 0 or j - d < 0) break;

        if(board[i - d][j - d]) return false;
    }
    for(int d = 1; ; d++){
        if(i + d == N or j + d == N) break;

        if(board[i + d][j + d]) return false;
    }
    for(int d = 1; ; d++){
        if(i - d < 0 or j + d == N) break;

        if(board[i - d][j + d]) return false;
    }
    for(int d = 1; ; d++){
        if(i + d == N or j - d < 0) break;

        if(board[i + d][j - d]) return false;
    }
    return true;
}
void n_queens(int i){
    if(i == N){
        printboard();
    }
    for(int j = 0; j < N; j++){
        if(safe(i, j)){

            board[i][j] = 1; 

            n_queens(i + 1);

            board[i][j] = 0;
        }
    }
}
int32_t main(){

        cin >> N;
        board = vector<vector<bool>> (N, vector<bool> (N));

        n_queens(0);

        return 0;
}
