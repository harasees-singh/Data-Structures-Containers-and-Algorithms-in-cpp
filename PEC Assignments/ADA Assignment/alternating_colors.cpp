#include <bits/stdc++.h>
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
using namespace std;
template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a){in >> a.ff >> a.ss; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> a){out << a.ff << ' ' << a.ss; return out;}
template<typename T, typename T1> T amax(T &a, T1 b){if(b > a) a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b){if(b < a) a = b; return a;}
using namespace std;
  
int graph[18][18][2];
  
long long dp[1 << 18][18][2];
  
long long minCost(int n, int m, int mask, int prev, int col)
{
    if (mask == ((1 << n) - 1)) {
        return 0;
    }
    if (dp[mask][prev][col == 1] != 0) {
        return dp[mask][prev][col == 1];
    }
  
    long long ans = 1e9;
  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            if (graph[prev][i][j] && !(mask & (1 << i)) 
                && (j != col)) {
                long long z = graph[prev][i][j] + 
                              minCost(n,m,mask|(1<<i),i,j);
                ans = min(z, ans);
            }
        }
    }
  
    return dp[mask][prev][col == 1] = ans;
}
  
void makeGraph(vector<pair<pair<int,int>,
                      pair<int,char>>>& vp,int m){
  
  for (int i = 0; i < m; i++) {
    int a = vp[i].first.first - 1;
    int b = vp[i].first.second - 1;
    int cost = vp[i].second.first;
    char color = vp[i].second.second;
    graph[a][b][color == 'W'] = cost;
    graph[b][a][color == 'W'] = cost;
  }
}
  
int getCost(int n,int m){
      
    long long ans = 1e9;
  
    for (int i = 0; i < n; i++) {
        ans = min(ans, minCost(n, m, 1 << i, i, 2));
    }
  
    if (ans != 1e9) {
        return ans;
    }
    else {
        return -1;
    }
}
  
int32_t main()
{
    int n, m; cin >> n >> m;

    vector<pair<pair<int, int>, pair<int, char> > > vp(m);
    for(auto &p : vp) cin >> p;
  
    makeGraph(vp, m);

    cout << getCost(n,m) << '\n';
      
    return 0;
}