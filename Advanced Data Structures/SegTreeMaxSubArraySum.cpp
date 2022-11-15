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
#define w(T)                            int T; cin >> T; while(T--)
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

template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a){in >> a.ff >> a.ss; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> a){out << a.ff << ' ' << a.ss; return out;}
template<typename T, typename T1> T amax(T &a, T1 b){if(b > a) a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b){if(b < a) a = b; return a;}
template<typename T> istream& operator>>(istream &in, vector<T> &v) { for (auto &x : v) in >> x; return in;}
template<typename T> ostream& operator<<(ostream &out, vector<T> &v) {out << "{ "; for (auto &x : v) out << x << " "; out << "}\n"; return out;}
template<typename T, typename... Args> void prn(T x, Args... args) {cout << x << " "; prn(args...);}
template<typename Iterable> void prnIter(const Iterable& ITER, ostream&out = cout){ auto x = ITER.begin(); out << "{ "; for (; x != ITER.end(); ++x) out << *x << ' '; out << "}" << endl;}

MOD_DEFINE

struct data{
    pair<int, int> sum, pref, suff, ans;
};

struct SegTreeMaxSubSum{
    // zero based indexing

    vector<data> t;
    vector<int> a;

    SegTreeMaxSubSum(const vector<int> &in){
        a = in;
        t = vector<data> (in.size() * 4); 
        build(1, 0, sz(a) - 1);
    }
    data make_data (int val) {
        data res;
        res.sum = {val, val};
        res.pref = res.suff = res.ans = {max(0ll, val), min(0ll, val)};
        return res;
    }
    data combine (data l, data r) {
        data res;
        res.sum = {l.sum.first + r.sum.first, l.sum.second + r.sum.second};
        res.pref = {max(l.pref.first, l.sum.first + r.pref.first), min(l.pref.second, l.sum.second + r.pref.second)};
        res.suff = {max(r.suff.first, r.sum.first + l.suff.first), min(r.suff.second, r.sum.second + l.suff.second)};

        res.ans.first = max(max(l.ans.first, r.ans.first), l.suff.first + r.pref.first);
        res.ans.second = min(min(l.ans.second, r.ans.second), l.suff.second + r.pref.second);
        return res;
    }
    void build(int v, int tl, int tr) {
        if (tl == tr)
            t[v] = make_data(a[tl]);
        else {
            int tm = (tl + tr) / 2;
            build(v * 2, tl, tm);
            build(v * 2 + 1, tm + 1, tr);

            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }
    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr)
            t[v] = make_data(new_val);
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);

            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }
    data query(int v, int tl, int tr, int l, int r) {
        if (l == tl && tr == r)
            return t[v];
        int tm = (tl + tr) / 2;

        if (r <= tm)
            return query(v * 2, tl, tm, l, r);
        if (l > tm)
            return query(v * 2 + 1, tm + 1, tr, l, r);
        return combine(query(v * 2, tl, tm, l, tm), query(v * 2 + 1, tm + 1, tr, tm + 1, r));
    }

    data Query(int l, int r){
        return query(1, 0, sz(a) - 1, l, r);
    }
    void Update(int i, int d){
        update(1, 0, sz(a) - 1, i, d);
    }
};

void slv(){
        
}

int32_t main(){
        
        FIO

        w(T) 
                slv();
        
        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/