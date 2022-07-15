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
#define fps(x,y)                        fixed<<setprecision(y)<<x

MOD_DEFINE

struct SegmentTree{
        int n;

        vector<int> t, a;

        SegmentTree(vector<int> &arr){
                n = arr.size();
                a = arr;
                t = vector<int> (4 * n);

                build(1, 0, n - 1);
        }
        int Query(int l, int r){
                // 0 index based
                assert(min(l, r) >= 0 and max(l, r) < n);
                return sum(1, 0, n - 1, l, r);
        }
        void Update(int id, int x){
                assert(id >= 0 and id < n);
                // 0 index based
                update(1, 0, n - 1, id, x);
        }

        void build(int v, int tl, int tr) {
                if (tl == tr) {
                        t[v] = a[tl];
                } else {
                        int tm = (tl + tr) / 2;
                        build(v * 2, tl, tm);
                        build(v * 2 + 1, tm + 1, tr);
                        t[v] = t[v * 2] + t[v * 2 + 1];
                }
        }
        int sum(int v, int tl, int tr, int l, int r) {
                if (l > r) 
                        return 0;
                if (l == tl && r == tr) {
                        return t[v];
                }
                int tm = (tl + tr) / 2;
                return sum(v * 2, tl, tm, l, min(r, tm)) + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        }
        void update(int v, int tl, int tr, int pos, int new_val) {
                if (tl == tr) {
                        t[v] = new_val;
                } 
                else{
                        int tm = (tl + tr) / 2;
                        if (pos <= tm)
                                update(v * 2, tl, tm, pos, new_val);
                        else
                                update(v * 2 + 1, tm + 1, tr, pos, new_val);
                        t[v] = t[v * 2] + t[v * 2 + 1];
                }
        }
};
int32_t main(){
        FIO 

        vi a = {0, 1, -1, 2, -2, 4, 4, 1, 1, 6, -6};

        SegmentTree T(a);

        T.Update(0, 5);

        cout << T.Query(1, 3) << endl;

        return 0;
}
