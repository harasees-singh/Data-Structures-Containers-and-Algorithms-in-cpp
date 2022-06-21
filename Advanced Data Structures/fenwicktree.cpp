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

    vector<vi> ft;

    FenwickTree(string const &I){
        ft.assign(I.size(), vi(26));

        for(int i = 0; i < I.size(); i++){
            put(i, I[i], 'a' - 1);   // put the char I[i] at pos i
        }
    }

    vi read(int idx){
        if(idx < 0) return vi(26, 0);

        // int ret = 0;
        vi ret(26);

        for(int i = idx; i >= 0; i = (i&(i + 1)) - 1){
            for(int j = 0; j < 26; j++) ret[j] += ft[i][j];
            // ret += ft[i];
        }
        return ret;
    }

    void put(int i, int latest, int old){
        latest = latest - 'a';
        old = old - 'a';
        for(int j = i; j < ft.size(); j = j|(j + 1)){
            // ft[j] = vi(26);
            if(old > -1)
                ft[j][old] -= 1;
            ft[j][latest] += 1;
        }
    }

    vi query(int l, int r){
        vi L = read(l - 1);
        vi R = read(r);

        l(i, 0, 26) R[i] -= L[i];

        return R;
    }
};

int32_t main(){
    FIO 

    string a = "abc";

    FenwickTree F(a);

    vi ret = F.query(0, 1); 

    for(auto p : ret) cout <<p << ' '; cout << endl;

    F.put(1, 'a', 'b');

    ret = F.query(0, 1);

    for(auto p : ret) cout <<p << ' '; cout << endl;

    ret = F.query(0, 2);

    for(auto p : ret) cout <<p << ' ';
    return 0;
}
