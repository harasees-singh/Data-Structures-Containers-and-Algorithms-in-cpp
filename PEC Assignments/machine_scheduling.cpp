// ਹਰਅਸੀਸ ਸਿੰਘ 
// ADA lab assignment 22 Feb 2022
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
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> a){out << a.ff << " " << a.ss; return out;}
MOD_DEFINE

int32_t main(){
        FIO 

        // n lg n

        // find the min number of machines required to simultaneously process n tasks coming one after the another
        // input format = {start time, end time}

        int n; cin >> n; // number of tasks

        vector<pii> tasks(n);

        for(auto &p : tasks) cin >> p;

        // sort acc to starting times

        sort(tasks.begin(), tasks.end());

        set<pii> end_times = {{0, 1}};// end time, machine id
        cout << "outputing tasks id and machine number" << endl;
        for(int i = 0; i < n; i++){
                auto p = tasks[i];
                
                int start, end; tie(start, end) = p; // start, end= p.first, p,second

                auto top = *end_times.begin();

                if(top.first > start){
                        end_times.insert({end, sz(end_times) + 1});

                        cout << i << ' ' << sz(end_times) << endl;
                }
                else{
                        end_times.erase(end_times.begin());

                        end_times.insert({end, top.second});

                        cout << i << ' ' << top.second << endl;
                }
        }
        cout << end_times.size();

        return 0;
}
