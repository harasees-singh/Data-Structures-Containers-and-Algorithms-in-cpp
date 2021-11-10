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
#define space                           " "
#define int                             long long
#define pii                             pair<int, int>
#define vi                              vector<int>
#define pb(n)                           push_back(n)
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define test_cases_loop int t;          cin >> t; while(t--)
#define FIO                             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define pqb                             priority_queue<int>
#define pqs                             priority_queue<int, vi, greater<int>>
#define fps(x,y)                        fixed<<setprecision(y)<<x

MOD_DEFINE

struct FenwickTree{
    // zero based indexing
    // use query(l, r) to get the sum of elements in range[l, r]
    // exceptions handled when l = 0; (read(-1) returns 0)
    // increase and query take logn time and constant space.
    // constructor takes vector<int> input (a const reference) to construct the tree (ft) in nlogn time.

    vector<int> ft;

    FenwickTree(vi const &I){
        ft.assign(I.size(), 0);

        for(int i = 0; i < I.size(); i++){
            increase(i, I[i]);
        }
    }

    int read(int idx){
        if(idx < 0) return 0;

        int ret = 0;

        for(int i = idx; i >= 0; i = (i&(i + 1)) - 1){
            ret += ft[i];
        }
        return ret;
    }

    void increase(int i, int delta){
        for(int j = i; j < ft.size(); j = j|(j + 1)){
            ft[j] += delta;
        }
    }

    int query(int l, int r){
        return read(r) - read(l - 1);
    }
};

int32_t main(){
    FIO 
    vi arr = {0, 1, 2, 5, -1, 3};

    FenwickTree F(arr);

    cout << F.query(1, 4) << endl;

    F.increase(3, 1);
    cout << F.query(1, 4) << endl;

    return 0;
}
