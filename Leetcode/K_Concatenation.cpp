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
#define w(t)                            int t; cin >> t; while(t--)
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

MOD_DEFINE
int kadane(vi& in){

        int mx = -1e6 - 1;
        int cur = 0;
        for(int i =0; i < sz(in); i++){
                cur += in[i];

                mx = max(mx, cur);

                cur = max(0ll, cur);
        }
        return mx;
}
int32_t main(){
        
        FIO

        w(t){
                int n, k; cin >> n >> k;

                vi in(n); for(auto &p : in) cin>> p;

                if(k < 3){
                        for(int i = 0; i < k - 1; i++){
                                for(int j = 0; j < n; j++){
                                        in.push_back(in[j]);
                                }
                        }
                        cout << (kadane(in)) << endl;
                }
                else{
                        int tot = accumulate(all(in), 0ll);

                        for(int i = 0; i < 1; i++){
                                for(int j = 0; j < n; j++){
                                        in.push_back(in[j]);
                                }
                        }
                        int ret = kadane(in);

                        cout << max(ret, (k - 2) * tot + ret)<<endl;
                }
        }

        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/