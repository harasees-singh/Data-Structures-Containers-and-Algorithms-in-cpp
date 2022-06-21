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

int32_t main(){
        FIO 

        int n; cin >> n;

        vector<vi> tasks(n);

        vector<int> arrival(n);
        vector<int> time(n);
        vector<int> priority(n);

        for(auto &p : arrival) cin >> p; 
        for(auto &p : time) cin >> p; 
        for(auto &p : priority) cin >> p; 

        for(int i = 0; i < n; i++){

                tasks[i] = {arrival[i], priority[i], time[i], i + 1};
        }
        sort(tasks.begin(), tasks.end());
        int t = tasks[0][0];
        set<vi> pq;                     // {priority, time};
        int pt = 0;
        vector<int> billing_sequence;
        vector<int> waiting_time(n + 1);
        vector<int> turnaround_time(n + 1);     // response time + billing time - arrival time

        while(true){
                while(pt < n and tasks[pt][0] <= t){
                        pq.insert({-tasks[pt][1], tasks[pt][2], tasks[pt][0], tasks[pt][3]});

                        pt++;
                }
                if(not pq.size()) break;

                auto execute = *pq.begin();

                billing_sequence.push_back(execute[3]);

                waiting_time[execute[3]] = t - execute[2];

                turnaround_time[execute[3]] = waiting_time[execute[3]] + execute[1];

                t += execute[1];

                pq.erase(pq.begin());
        }       
        cout << "Billing Sequence: "; for(auto p : billing_sequence) cout << p << ' '; cout << endl;
        cout << "Waiting time for each customer: "; for(int i = 1; i <= n; i++) cout << waiting_time[i] << ' '; cout << endl;
        cout << "Turn Around time: "; for(int i = 1; i <= n; i++) cout << turnaround_time[i] << ' '; cout << endl;
        cout << "Average waiting time: " << accumulate(waiting_time.begin(), waiting_time.end(), 0)/(double)n << endl;
        cout << "Average Turn Around Time: " << accumulate(turnaround_time.begin(), turnaround_time.end(), 0)/(double)n << endl;
        return 0;
}
